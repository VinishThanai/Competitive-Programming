#include<bits/stdc++.h>
//Comment optimisations for interactive problems (use endl)

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")

#define ff                first 
#define endl              "\n"
#define ss                second 
#define int               long long 
#define vi                vector<int>
#define ld                long double
#define pii               pair<int,int>
#define vpii              vector<pair<int,int>>
#define pb                push_back
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define setbits(x)        __builtin_popcountll(x)
#define custom            pair<int,pair<int,int> >
#define sz(x)             ((int)(x).size())
#define all(x)            (x).begin(), (x).end()
#define deb(x)            { cout<< #x <<" is "<<x<<endl; }
using namespace std;
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; 
*/
int ax[4]={1,-1,0,0};int ay[4]={0,0,-1,1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
#define mod 1000000007
int pow(int x,int y, int p){
    int res = 1;x = x % p;
    while (y > 0) {
        if (y & 1)
        res = (res * x) % p;
        y = y >> 1; x = (x * x) % p;
    }
    return res%p;
}
int modinverse(int n,int p){
    return pow(n,p-2,p);
}
/*--------------------------------------------------------------------------------------------------------------------------*/
class sparse{
    public:
    vector<vi> table;
    vector<int> logValues;
    int n;
    int maxlog;
    int opeartion(int a,int b)
    {
        return min(a,b);
        return max(a,b);
        return __gcd(a,b);
    }
    sparse(vector<int> arr){
		n = sz(arr);
		table.resize(n);
		logValues.resize(n + 1);
        logValues[0]=logValues[1]=0;
        for(int i=2;i<=n;i++)
        {
            logValues[i]=logValues[i/2]+1;
        }
		maxlog = logValues[n];
		for(int i=0;i<n;i++)
        {
            table[i].resize(maxlog + 1ll);
            table[i][0]=arr[i];
        }
        for(int j=1;j<=maxlog;j++)
        {
            for(int i=0;(i+(1<<j))<=n;i++)
            {
                table[i][j]=opeartion(table[i][j-1],table[i+(1<<(j-1))][j-1]);
            }
        }
	}
    int query(int left,int right)
    {
        int x=logValues[right+1-left];
        return opeartion(table[left][x],table[right-(1<<x)+1][x]);
    }

};
void solve(){
    int n;cin>>n;
    int q;cin>>q;
    vi arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sparse s(arr);
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        cout<<s.query(a-1,b-1)<<endl;
    }
   
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
  //  cin>>t;
    while(t--){
        solve();
    }
    return 0;
}