# # Experiment 12
# # Generate Square Pattern with Star in Parallel on GPU Using CUDA

# ## Aim
# To generate a square star pattern using CUDA threads executing in parallel on GPU.

# ## Theory
# Each GPU thread maps to one matrix location. Threads execute in parallel and fill a square matrix which is later displayed as a star pattern.

!nvidia-smi

from numba import cuda
import numpy as np
import matplotlib.pyplot as plt
import time

# ## Create Input Matrix

n=10
pattern=np.zeros((n,n),dtype=np.int32)
pattern

# ## CUDA Kernel

@cuda.jit
def star_pattern_kernel(arr):
    row,col=cuda.grid(2)
    if row < arr.shape[0] and col < arr.shape[1]:
        arr[row,col]=1

# ## Transfer Data To GPU

d_pattern=cuda.to_device(pattern)

# ## Thread and Block Configuration

threads=(16,16)
blocks=((n+15)//16,(n+15)//16)
print('Threads:',threads)
print('Blocks:',blocks)

# ## Launch Kernel

start=time.time()
star_pattern_kernel[blocks,threads](d_pattern)
cuda.synchronize()
gpu_time=time.time()-start
print('GPU Execution Time:',gpu_time)

# ## Copy Result Back To CPU

result=d_pattern.copy_to_host()
result

# ## Display Matrix

plt.figure(figsize=(5,5))
plt.imshow(result,cmap='gray')
plt.title('GPU Generated Square Pattern')
plt.show()

# ## Print Star Pattern

for row in result:
    for col in row:
        if col==1:
            print('*',end=' ')
    print()

# ## Observation
# All matrix elements were filled in parallel by CUDA threads.

# ## Result
# Square star pattern was generated successfully using CUDA GPU parallel execution.