# ======================================================================
# [Code Cell 1]
# ======================================================================
!nvidia-smi

# ======================================================================
# [Code Cell 2]
# ======================================================================
!pip install torch torchvision torchaudio --index-url https://download.pytorch.org/whl/cu121

# ======================================================================
# [Code Cell 3]
# ======================================================================
import sys
print(sys.executable)

# ======================================================================
# [Code Cell 4]
# ======================================================================
import torch

# Check CUDA availability
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
print("Using device:", device)

# Create tensors on GPU
a = torch.tensor([1, 2, 3, 4, 5], dtype=torch.float32).to(device)
b = torch.tensor([10, 20, 30, 40, 50], dtype=torch.float32).to(device)

# Addition on GPU
addition = a + b

# Multiplication on GPU
multiplication = a * b

print("Tensor A:", a)
print("Tensor B:", b)
print("Addition:", addition)
print("Multiplication:", multiplication)
