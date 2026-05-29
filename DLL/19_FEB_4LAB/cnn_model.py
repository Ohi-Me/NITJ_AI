import torch
import torch.nn as nn
import torch.nn.functional as F

class CNNDetector(nn.Module):
    def __init__(self):
        super(CNNDetector, self).__init__()

        # RGB input → 3 channels
        self.conv1 = nn.Conv2d(3, 16, kernel_size=5, stride=1)
        self.pool1 = nn.MaxPool2d(2, 2)

        self.conv2 = nn.Conv2d(16, 32, kernel_size=5, stride=1)
        self.pool2 = nn.MaxPool2d(2, 2)

        self.conv3 = nn.Conv2d(32, 64, kernel_size=5, stride=1)
        
        self.fc1 = nn.Linear(64 * 18 * 18, 512)
        self.dropout = nn.Dropout(0.5)
        self.fc2 = nn.Linear(512, 4)

    def forward(self, x):
        x = self.pool1(F.relu(self.conv1(x)))
        x = self.pool2(F.relu(self.conv2(x)))
        x = F.relu(self.conv3(x))

        x = x.view(x.size(0), -1)

        x = F.relu(self.fc1(x))
        x = self.dropout(x)
        x = self.fc2(x)

        return x
