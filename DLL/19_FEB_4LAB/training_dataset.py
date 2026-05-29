import torch
from torch.utils.data import Dataset
import pandas as pd
import os
from PIL import Image
import torchvision.transforms as transforms

class CUBDataset(Dataset):
    def __init__(self, root_dir, train=True):
        self.root = root_dir

        images = pd.read_csv(
            os.path.join(root_dir, "images.txt"),
            sep=" ",
            header=None,
            names=["id", "path"]
        )

        bboxes = pd.read_csv(
            os.path.join(root_dir, "bounding_boxes.txt"),
            sep=" ",
            header=None,
            names=["id", "x", "y", "w", "h"]
        )

        split = pd.read_csv(
            os.path.join(root_dir, "train_test_split.txt"),
            sep=" ",
            header=None,
            names=["id", "is_train"]
        )

        data = images.merge(bboxes, on="id")
        data = data.merge(split, on="id")

        if train:
            self.data = data[data["is_train"] == 1]
        else:
            self.data = data[data["is_train"] == 0]

        self.data = self.data.reset_index(drop=True)

        self.transform = transforms.Compose([
            transforms.Resize((100, 100)),
            transforms.ToTensor()
        ])

    def __len__(self):
        return len(self.data)

    def __getitem__(self, idx):
        img_path = os.path.join(self.root, "images", self.data.iloc[idx]["path"])
        image = Image.open(img_path).convert("RGB")
        image = self.transform(image)

        bbox = self.data.iloc[idx][["x", "y", "w", "h"]].astype(float).values
        bbox = torch.tensor(bbox, dtype=torch.float32)

        # Normalize bbox (VERY IMPORTANT)
        bbox = bbox / 100.0

        return image, bbox
