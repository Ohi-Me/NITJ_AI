import torch
import numpy as np
import time
import matplotlib.pyplot as plt

# ---------------- CONFIG ----------------
H, W = 4096, 4096
device = torch.device("cuda")

# ---------------- CREATE A BETTER 4K IMAGE ----------------
x = np.linspace(0, 255, W, dtype=np.uint8)
y = np.linspace(0, 255, H, dtype=np.uint8)

X, Y = np.meshgrid(x, y)

img_np = np.zeros((H, W, 3), dtype=np.uint8)
img_np[..., 0] = X                  # Red gradient
img_np[..., 1] = Y                  # Green gradient
img_np[..., 2] = (X + Y) // 2        # Blue mix

# Draw a bright square in center
img_np[1500:2600, 1500:2600, :] = [255, 255, 0]

# ---------------- CPU GRAYSCALE ----------------
t0 = time.time()
gray_cpu = (
    0.299 * img_np[:,:,0] +
    0.587 * img_np[:,:,1] +
    0.114 * img_np[:,:,2]
)
cpu_time = time.time() - t0

# ---------------- GPU GRAYSCALE ----------------
img_gpu = torch.from_numpy(img_np).to(device)

torch.cuda.synchronize()
t0 = time.time()

gray_gpu = (
    0.299 * img_gpu[:,:,0] +
    0.587 * img_gpu[:,:,1] +
    0.114 * img_gpu[:,:,2]
)

torch.cuda.synchronize()
gpu_kernel_time = time.time() - t0

# ---------------- GPU → CPU ----------------
t0 = time.time()
gray_back = gray_gpu.cpu().numpy()
gpu_transfer_time = time.time() - t0

total_gpu_time = gpu_kernel_time + gpu_transfer_time

# ---------------- DISPLAY IMAGES (DOWNSCALED) ----------------
plt.figure(figsize=(10,4))

plt.subplot(1,2,1)
plt.title("Original 4K RGB (downscaled)")
plt.imshow(img_np[::8, ::8])
plt.axis("off")

plt.subplot(1,2,2)
plt.title("Grayscale 4K (downscaled)")
plt.imshow(gray_back[::8, ::8], cmap="gray")
plt.axis("off")

plt.show()

# ---------------- TIME BAR CHART ----------------
plt.figure(figsize=(6,4))
plt.bar(["CPU", "GPU (total)"], 
        [cpu_time*1000, total_gpu_time*1000])
plt.ylabel("Time (ms)")
plt.title("CPU vs GPU Time (4K RGB → Grayscale)")
plt.show()

# ---------------- PRINT RESULTS ----------------
print("Image resolution :", img_np.shape)
print("CPU time         :", round(cpu_time*1000,2), "ms")
print("GPU kernel time  :", round(gpu_kernel_time*1000,2), "ms")
print("GPU transfer time:", round(gpu_transfer_time*1000,2), "ms")
print("Total GPU time   :", round(total_gpu_time*1000,2), "ms")
print("Speedup (CPU / kernel):", round(cpu_time/gpu_kernel_time,1), "x")
