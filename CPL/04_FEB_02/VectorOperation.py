# ======================================================================
# [Code Cell 1]
# ======================================================================
import torch

print("PyTorch Version:", torch.__version__)
print("CUDA Available:", torch.cuda.is_available())
print("GPU Name:", torch.cuda.get_device_name(0) if torch.cuda.is_available() else "No GPU")

# ======================================================================
# [Code Cell 2]
# ======================================================================
import torch
import time

# Select device
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

# Vector size (large to see GPU benefit)
n = 10_000_000

# Create random vectors directly on GPU
a = torch.rand(n, device=device)
b = torch.rand(n, device=device)

# ----- Addition -----
start = time.time()
c_add = a + b
torch.cuda.synchronize()  # wait for GPU
end = time.time()

print("Addition Time:", end - start, "seconds")

# ----- Multiplication -----
start = time.time()
c_mul = a * b
torch.cuda.synchronize()
end = time.time()

print("Multiplication Time:", end - start, "seconds")

print("First 5 Addition Results:", c_add[:5])
print("First 5 Multiplication Results:", c_mul[:5])
