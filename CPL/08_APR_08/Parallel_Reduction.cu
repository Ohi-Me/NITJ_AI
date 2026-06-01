#include <bits/stdc++.h>
#include <cuda.h>
using namespace std;

#define int long long

__global__ void reduce(int *a,int n){
    int i=blockIdx.x*blockDim.x+threadIdx.x;
    int stride=1;

    while(stride<n){
        if(i%(2*stride)==0 && i+stride<n){
            a[i]+=a[i+stride];
        }
        __syncthreads();
        stride*=2;
    }
}

int main(){
    int n=2048;
    int *h=new int[n];
    for(int i=0;i<n;i++) h[i]=1;

    int *d;
    cudaMalloc(&d,n*sizeof(int));
    cudaMemcpy(d,h,n*sizeof(int),cudaMemcpyHostToDevice);

    reduce<<<1,1024>>>(d,n);

    cudaMemcpy(h,d,sizeof(int),cudaMemcpyDeviceToHost);

    cout<<h[0]<<endl;
}