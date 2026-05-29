import torch
import cv2
from cnn_model import CNNDetector

device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

model = CNNDetector().to(device)
model.load_state_dict(torch.load("model.pth"))
model.eval()

image = cv2.imread("test_image.png", cv2.IMREAD_GRAYSCALE)
image = image / 255.0
image = torch.tensor(image, dtype=torch.float32).unsqueeze(0).unsqueeze(0).to(device)

with torch.no_grad():
    output = model(image)

print("Predicted Bounding Box:", output)
