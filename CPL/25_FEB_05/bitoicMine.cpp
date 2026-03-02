#include <bits/stdc++.h>
using namespace std;

// Common shortcuts
#define int long long
#define endl '\n'
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define COUT(x) cout << x << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define V(x,n) vector<int>x(n);

#define MAX LLONG_MAX;
#define MIN LLONG_MIN;

#define vec(x,n) vector<int>x(n);

// Input/Output helpers
#define VECIN(v, n) for (int i = 0; i < n; ++i) cin >> v[i]
#define VECOUT(v) for (auto &x : v) cout << x << " "; cout << endl

#define SORT(v) sort(all(v))
#define RSORT(v) sort(rall(v))
#define SORTPAIRBYF(v) sort(v.begin(), v.end(), [](auto &a, auto &b){ return a.first < b.first; })
#define SORTPAIRBYS(v) sort(v.begin(), v.end(), [](auto &a, auto &b){ return a.second < b.second; })

#define MAX_ELEM(v) (*max_element((v).begin(), (v).end()))
#define MIN_ELEM(v) (*min_element((v).begin(), (v).end()))
#define MAX_IDX(v) (max_element((v).begin(), (v).end()) - (v).begin())
#define MIN_IDX(v) (min_element((v).begin(), (v).end()) - (v).begin())
#define MAX_ELEM_FIRSTN(v, n) (*max_element((v).begin(), (v).begin() + (n)))
#define MIN_ELEM_FIRSTN(v, n) (*min_element((v).begin(), (v).begin() + (n)))



// Useful constants
const int INF = 1e18;
const int MOD = 1e9 + 7; // or 998244353

// Debugging macros
#ifdef LOCAL
#define dbg(x) cerr << #x << " = "; _print(x); cerr << endl;
#else
#define dbg(x)
#endif



// GCD and LCM (built-in gcd available in C++17+)
inline int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
inline int lcm(int a, int b) { return (a / gcd(a, b)) * b; }

// Bit operations
inline bool is_power_of_two(int x) { return x && (!(x & (x - 1))); }
inline int bitcount(int x) { return __builtin_popcountll(x); }
inline int msb_pos(int x) { return 63 - __builtin_clzll(x); }

void FILE_I_O() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen ("input.txt", "r", stdin);
        freopen ("output.txt", "w", stdout);
    #endif
}

// Main solving function
void solve(){
    int n;
    cin>>n;
    vector<int>temp(n);
    for(int i=0;i<n;i++){
        cin>>temp[i];
    }

    if(!is_power_of_two(n)){
        cout<<"n must be power of 2"<<endl;
        return;
    }
    
    for(auto x:temp){
        cout<<x<<" ";
    }
    cout<<endl;

    for(int k=2;k<=n;k<<=1){
        for(int j=k>>1;j>0;j>>=1){
            for(int i=0;i<n;i++){
                int ixj=i^j;
                if(ixj>i){
                    if((i&k)==0){
                        if(temp[i]>temp[ixj]){
                            swap(temp[i],temp[ixj]);
                        }
                    }
                    else{
                        if(temp[i]<temp[ixj]){
                            swap(temp[i],temp[ixj]);
                        }
                    }
                }
            }
        }
    }

    for(auto x:temp){
        cout<<x<<" ";
    }
    cout<<endl;
}

 
int32_t main() {
    
    FILE_I_O();
 
    int test=1;
    cin>>test;
    while(test--) {
        solve();
    }
    // solve();
    return 0;
}
