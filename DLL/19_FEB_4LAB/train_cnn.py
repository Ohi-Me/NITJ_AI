import torch
import torch.nn as nn
import torch.optim as optim
from torch.utils.data import DataLoader
from cnn_model import CNNDetector
from training_dataset import CUBDataset

device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

dataset = CUBDataset("archive/CUB_200_2011", train=True)

# For faster testing (optional)
# dataset = torch.utils.data.Subset(dataset, range(1000))

loader = DataLoader(dataset, batch_size=32, shuffle=True)

model = CNNDetector().to(device)

criterion = nn.MSELoss()
optimizer = optim.Adam(model.parameters(), lr=1e-4)

epochs = 20

for epoch in range(epochs):
    running_loss = 0.0

    for images, targets in loader:
        images, targets = images.to(device), targets.to(device)

        optimizer.zero_grad()
        outputs = model(images)

        loss = criterion(outputs, targets)
        loss.backward()
        optimizer.step()

        running_loss += loss.item()

    print(f"Epoch {epoch+1}/{epochs}, Loss: {running_loss/len(loader)}")

torch.save(model.state_dict(), "model.pth")
print("Model Saved as model.pth")
