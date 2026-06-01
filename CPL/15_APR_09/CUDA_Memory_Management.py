# # CUDA Memory Management Using Local and Shared Memory

from numba import cuda
import numpy as np
import time

@cuda.jit
def shared_memory_kernel(inp,out):
    sm=cuda.shared.array(256,dtype=np.int32)
    tx=cuda.threadIdx.x
    idx=cuda.grid(1)
    if idx < inp.size:
        sm[tx]=inp[idx]
    cuda.syncthreads()
    if idx < inp.size:
        out[idx]=sm[tx]*2


N=1024
a=np.arange(N,dtype=np.int32)
out=np.zeros_like(a)
d_a=cuda.to_device(a)
d_out=cuda.to_device(out)
shared_memory_kernel[4,256](d_a,d_out)
cuda.synchronize()
print(d_out.copy_to_host()[:20])

