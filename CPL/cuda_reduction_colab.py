# ======================================================================
# [Markdown Cell 1]
# ======================================================================
# # CUDA Parallel Reduction (Google Colab)
# This notebook demonstrates a simple parallel reduction (sum) using CUDA.

# ======================================================================
# [Code Cell 2]
# ======================================================================
!nvidia-smi

# ======================================================================
# [Code Cell 3]
# ======================================================================
%%writefile reduction.cu
#include <bits/stdc++.h>
using namespace std;

__global__ void reduce(int *input, int *output, int n) {
    extern __shared__ int sdata[];
    int tid = threadIdx.x;
    int i = blockIdx.x * blockDim.x + threadIdx.x;

    sdata[tid] = (i < n) ? input[i] : 0;
    __syncthreads();

    for (int s = blockDim.x / 2; s > 0; s >>= 1) {
        if (tid < s) {
            sdata[tid] += sdata[tid + s];
        }
        __syncthreads();
    }

    if (tid == 0) output[blockIdx.x] = sdata[0];
}

int main() {
    int n = 1<<20;
    int size = n * sizeof(int);

    vector<int> h_input(n, 1);
    int *d_input, *d_output;

    cudaMalloc(&d_input, size);
    cudaMalloc(&d_output, size);

    cudaMemcpy(d_input, h_input.data(), size, cudaMemcpyHostToDevice);

    int threads = 256;
    int blocks = (n + threads - 1) / threads;

    reduce<<<blocks, threads, threads*sizeof(int)>>>(d_input, d_output, n);

    vector<int> h_output(blocks);
    cudaMemcpy(h_output.data(), d_output, blocks*sizeof(int), cudaMemcpyDeviceToHost);

    int sum = 0;
    for(int i=0;i<blocks;i++) sum += h_output[i];

    cout << "Final Sum: " << sum << endl;

    cudaFree(d_input);
    cudaFree(d_output);
    return 0;
}

# ======================================================================
# [Code Cell 4]
# ======================================================================
!nvcc reduction.cu -o reduction

# ======================================================================
# [Code Cell 5]
# ======================================================================
!./reduction
