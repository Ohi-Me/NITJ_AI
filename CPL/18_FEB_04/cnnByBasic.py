import os

# base folder
base = "dataset"
class0 = os.path.join(base, "class0")
class1 = os.path.join(base, "class1")

# create folders
os.makedirs(class0, exist_ok=True)
os.makedirs(class1, exist_ok=True)

# create empty image files
open(os.path.join(class0, "img1.jpg"), "wb").close()
open(os.path.join(class1, "img2.jpg"), "wb").close()

print("Folders and files created successfully.")

















import torch
import torchvision
import torchvision.transforms as transforms

# device
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
print("Device:", device)

# transform
transform = transforms.Compose([
    transforms.Resize((128,128)),
    transforms.ToTensor()
])

# download dataset automatically
dataset = torchvision.datasets.CIFAR10(
    root="./data",
    train=True,
    download=True,
    transform=transform
)

# keep only cat (3) and dog (5)
images = []
labels = []

for img, label in dataset:
    if label == 3:
        images.append(img)
        labels.append(1)
    elif label == 5:
        images.append(img)
        labels.append(0)

X = torch.stack(images).to(device)
y = torch.tensor(labels, dtype=torch.float32).to(device)

# initialize parameters manually
kernel = torch.randn(3,3,3, device=device) * 0.01
W = torch.randn(63*63, device=device) * 0.01
b = torch.tensor(0.0, device=device)

lr = 0.001
epochs = 2

for epoch in range(epochs):

    total_loss = 0

    for i in range(len(X)):

        img = X[i].permute(1,2,0)   # convert to HWC
        label = y[i]

        # ----- Convolution -----
        conv_out = torch.zeros(126,126, device=device)

        for r in range(126):
            for c in range(126):
                s = 0
                for ch in range(3):
                    for kr in range(3):
                        for kc in range(3):
                            s += img[r+kr][c+kc][ch] * kernel[kr][kc][ch]
                conv_out[r][c] = s

        # ----- ReLU -----
        relu_out = torch.zeros_like(conv_out)
        for r in range(126):
            for c in range(126):
                if conv_out[r][c] > 0:
                    relu_out[r][c] = conv_out[r][c]

        # ----- Average Pooling (2x2) -----
        pool_out = torch.zeros(63,63, device=device)

        for r in range(0,126,2):
            for c in range(0,126,2):
                total = conv_out[r][c] + conv_out[r][c+1] + \
                        conv_out[r+1][c] + conv_out[r+1][c+1]
                pool_out[r//2][c//2] = total / 4

        flat = pool_out.flatten()

        # ----- Fully Connected -----
        fc = torch.dot(flat, W) + b

        # ----- Sigmoid -----
        output = 1 / (1 + torch.exp(-fc))

        # ----- Binary Cross Entropy -----
        loss = -(label * torch.log(output+1e-8) +
                (1-label) * torch.log(1-output+1e-8))

        total_loss += loss.item()

        # ----- Backprop (only FC layer) -----
        error = output - label
        W = W - lr * error * flat
        b = b - lr * error

    print("Epoch:", epoch+1, "Loss:", total_loss/len(X))

print("Training Finished")
