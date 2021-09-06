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
class fenwick{
    
    public:
    vector<int> bit;
    int n;
    void init(int N)
    {
        for(int i=0;i<=N;i++)
        {
            bit.pb(0);
        }
    }
    fenwick()
    {

    }
    fenwick(int size_jo_given_hoga)
    {
        n=size_jo_given_hoga;
        bit.resize(n+1,0);
    }
    void update_full(int * arr)
    {
        for(int i=0;i<n;i++)
        {
            update(i+1,arr[i]);
        }
    }
    void update_full(vector<int> &arr)
    {
        for(int i=0;i<n;i++)
        {
            update(i+1,arr[i]);
        }
    }
    int query(int idx)
    {
        int ans=0;
        while(idx>0)

        {
            ans+=bit[idx];
            idx-=(idx&(-idx));
        }
        return ans;
    }
    int query(int l,int r)
    {
        if(r<l)
        {
            return 0;
        }
        return query(r)-query(l-1);
    }
    void update(int idx,int value)
    {
        // value to be incremented
        while(idx<=n)
        {
            bit[idx]+=value;
            idx+=(idx&(-idx));
        }
    }
};
// R U P Q
// Initialise with 0 and just query the index
// P U R Q
// Initialise the array with full array or vector and query using r - (l-1)
// R U R Q
// 2 bits, both 0 initialised
class rurq{
    public:
    int n;
    fenwick *f1,*f2;
    rurq(int iska_size)
    {
        n=iska_size;
        f1 = new fenwick(n);
        f2= new fenwick(n);
    }
    void update(int l,int r,int inc)
    {
        f1->update(l,inc);
        f1->update(r+1,-inc);
        f2->update(l,inc*(l-1));
        f2->update(r+1,-(inc*r));
    }
    int pref(int idx)
    {
        return (f1->query(idx)*idx) - f2->query(idx);
    }
    int query(int l,int r)
    {
        return  pref(r)-pref(l-1);
    }

};

 void solve(){
    int n;
    cin>>n;
    int q;
    cin>>q;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    rurq rr(n);
    for(int i=0;i<n;i++)
    {
        rr.update(i+1,i+1,arr[i]);
    }
    while(q--)
    {
        int a,l,r;
        cin>>a>>l>>r;
        if(a==1)
        {
            int num=rr.query(l,l);
            int inc=r-num;
            rr.update(l,l,inc);
        }
        else
        {
            cout<<rr.query(l,r)<<endl;
        }
    }
    
   
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    
    while(t--){
        solve();
    }
    return 0;
}