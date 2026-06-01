# # Parallel Multiplication Reduction

from numba import cuda
import numpy as np

@cuda.jit
def multiply_reduce(arr):
    tid=cuda.threadIdx.x
    stride=1
    while stride < cuda.blockDim.x:
        if tid%(2*stride)==0 and tid+stride<arr.size:
            arr[tid]*=arr[tid+stride]
        cuda.syncthreads()
        stride*=2


arr=np.array([1,2,3,4,5,6,7,8],dtype=np.int32)
d_arr=cuda.to_device(arr)
multiply_reduce[1,8](d_arr)
cuda.synchronize()
print('Product =',d_arr.copy_to_host()[0])