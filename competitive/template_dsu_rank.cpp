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
int gcd(int a, int b){
    if (a == 0)return b;
    return gcd(b % a, a);
}
int gint(int a,int b)
{
    // a/b
    if(a%b==0)
    return a/b;
    return 1+ (a/b);
}
/*--------------------------------------------------------------------------------------------------------------------------*/
class dsu_rank{
    public:
    int n;
    vector<int> parent;
    vector<int> rank;
    dsu_rank(int total)
    {
        n=total;
        
    }
    void init()
    {
        for(int i=0;i<=n;i++)
        {
            parent.pb(i);
            rank.pb(1);
        }
    }
    int get(int a)
    {
        if(parent[a]==a)
        return a;

        return parent[a]=get(parent[a]);
    }
    void addedge(int a,int b)
    {
        int x=get(a);
        int y=get(b);
        if(x==y)
        return;

        if(rank[x]<rank[y])
        {
            parent[x]=y;
        }
        else if(rank[x]==rank[y])
        {
            parent[x]=y;
            rank[x]+=1;
        }
        else
        {
            parent[y]=x;
        }
    }
};
void solve(){
    int n;cin>>n;
    int m1,m2;
    cin>>m1>>m2;
   dsu_rank one(n);
   dsu_rank two(n);
   one.init();
   two.init();
   for(int i=1;i<=m1;i++)
   {
       int a,b;cin>>a>>b;
       one.addedge(a,b);
   }
   for(int i=1;i<=m2;i++)
   {
       int a,b;cin>>a>>b;
       two.addedge(a,b);
   }
   vpii ans;
   for(int i=1;i<=n;i++)
   {
       for(int j=i+1;j<=n;j++)
       {
           int x=one.get(i);
           int y=one.get(j);
           if(x==y)continue;
           x=two.get(i);
           y=two.get(j);
           if(x==y)continue;
           one.addedge(i,j);
           two.addedge(i,j);
           ans.pb({i,j});
       }
   }
   cout<<sz(ans)<<endl;
   for(auto p:ans)
   {
       cout<<p.ff<<" "<<p.ss<<endl;
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