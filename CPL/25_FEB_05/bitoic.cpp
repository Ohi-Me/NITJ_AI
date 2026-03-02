#include <bits/stdc++.h>
#include <cuda_runtime.h>
using namespace std;

#define int long long
#define endl '\n'

__global__ void bitonicSortKernel(long long *d, int j, int k, int n){
    unsigned int i = threadIdx.x + blockDim.x * blockIdx.x;
    if(i >= n) return;

    unsigned int ixj = i ^ j;

    if(ixj > i){
        if((i & k) == 0){
            if(d[i] > d[ixj]){
                long long temp = d[i];
                d[i] = d[ixj];
                d[ixj] = temp;
            }
        } else {
            if(d[i] < d[ixj]){
                long long temp = d[i];
                d[i] = d[ixj];
                d[ixj] = temp;
            }
        }
    }
}

void solve(){
    int n;
    cin >> n;

    vector<long long> temp(n);
    for(int i=0;i<n;i++) cin >> temp[i];

    if((n & (n-1)) != 0){
        cout << "Size must be power of 2\n";
        return;
    }

    long long *d;
    cudaMalloc(&d, n*sizeof(long long));
    cudaMemcpy(d, temp.data(), n*sizeof(long long), cudaMemcpyHostToDevice);

    int threads = 1024;
    int blocks = (n + threads - 1)/threads;

    for(int k=2;k<=n;k<<=1){
        for(int j=k>>1;j>0;j>>=1){
            bitonicSortKernel<<<blocks,threads>>>(d,j,k,n);
            cudaDeviceSynchronize();
        }
    }

    cudaMemcpy(temp.data(), d, n*sizeof(long long), cudaMemcpyDeviceToHost);
    cudaFree(d);

    for(auto x:temp) cout<<x<<" ";
    cout<<endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin>>test;
    while(test--) solve();
}