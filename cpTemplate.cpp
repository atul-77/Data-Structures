#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
#define double long double
#define minheapair priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> >
#define maxheapair priority_queue<pair<int,int>>
#define minheap priority_queue<int,vector<int>,greater<int>>
#define vi vector<int>
#define vpi vector<pair<int,int> >
#define mii map<int,int>
#define mpi map<pair<int,int>,int>
#define msi map<string,int>
#define set set<int>
#define u_set unordered_set<int>
#define pb push_back
#define endl "\n"
#define ll long long int
#define vll vector<long long int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define umap unordered_map
#define mod 1000000007
#define fori(a,n) for(int i=a;i<n;i++)
#define forj(a,n) for(int j=a;j<n;j++)
#define inf 9219999999999999999
using namespace std;
//  inline bool operator<(const data& lhs, const data& rhs)
//  {
//      if(lhs.val< rhs.val)return 1;
//      return 0;
//  }
// inline bool operator>(const data& lhs, const data& rhs)
//  {
//      if(lhs.val > rhs.val)return 1;
//      return 0;
//  }
ll modexp(ll x,ll y,ll m){
    ll ans = 1;
    while(y>0){
        if(y&1){
            ans *= x;
            ans %= m;
            --y;
        }
        else{
            y /= 2;
            x *= x;
            x %= m;
        }
    }
    return ans;
}
ll minv(ll a,ll m){
    return modexp(a,m-2,m);
}
void Z(string s,vector<int>&z){
    int L = 0, R = 0;
    int n = s.size();
    for (int i = 1; i < n; i++) 
    {
        if (i > R) 
        {
            L = R = i;
            while (R < n && s[R-L] == s[R]) 
            {
                R++;
            }
            z[i] = R-L; 
            R--;
        } 
        else 
        {
            int k = i-L;
            if (z[k] < R-i+1) 
            {
                z[i] = z[k];
            } 
            else 
            {
                L = i;
                while (R < n && s[R-L] == s[R]) 
                {
                    R++;
                }
                z[i] = R-L; 
                R--;
            }
        }
    }
}
using namespace std;
class segmentTree{
public:
    vector<ll>segtree;
    vector<ll>inp;
    int mode; // 1-> sum, 2-> max , 3-> min, 4-> xor
    segmentTree(vector<ll>&ar,int m){
        mode = m;
        if(mode==1 || mode==4)segtree = vector<ll>(1000005,0);
        else if(mode==2)segtree = vector<ll>(1000005,INT_MIN);
        else segtree = vector<ll>(1000005,INT_MAX);
        inp = ar;
        maketree();
    }
    ll operation(ll a,ll b){
        if(mode==1)return a+b;
        if(mode==2)return max(a,b);
        if(mode==4) return a^b;
        return min(a,b);
    }
    void build(int ind,int l,int r){
        if(l>r)return;
        for(int i=l;i<=r;++i)segtree[ind] = operation(segtree[ind],inp[i]);
        if(l==r)return;
        build(ind*2+1, l, (r+l)/2);
        build(ind*2+2,(r+l)/2+1,r);
    }
    ll getres(int ql,int qr,int indl,int indr,int i){
        if((indl<ql && indr<ql) || (indl>qr && indr>qr) )return 0*(mode==1) + INT_MAX*(mode==3) + INT_MIN*(mode==2);
        if(indl>=ql && indr<=qr)return segtree[i];
        return operation(getres(ql,qr,indl,(indl+indr)/2, 2*i+1) , getres(ql,qr,(indl+indr)/2+1,indr,2*i+2));
    }
    ll updateTree(int ind,ll val,int i,int l,int r){
        if((l<ind && r<ind) || (l>r) || (l>ind && r>ind))return segtree[i];
        if(l==r){if(l==ind)segtree[i] = val; return segtree[i];}
        return segtree[i] = operation(updateTree(ind,val,2*i+1,l,(r+l)/2),updateTree(ind,val,2*i+2,(r+l)/2+1,r));
    }
    void maketree(){
        build(0,0,inp.size()-1); 
        // prntree();
    }
    void update(int ind , ll val){
        updateTree(ind,val,0,0,inp.size()-1);
        inp[ind] = val;
    }
    ll getresult(int ql,int qr){
        return getres(ql,qr,0,inp.size()-1,0);
    }
    void prntree(){
        fori(0,20)cout<<segtree[i] << " ";cout<<endl;
    }
};

void solve(){
    ll n,q;
    cin>>n>>q;
    vector<ll>a(n); fori(0,n)cin>>a[i];
    segmentTree tree(a,4);
    while(q--){
        int type, ql, qr;
        cin>>ql>>qr;
        cout<<tree.getresult(ql-1,qr-1)<<endl;
    }
}
int main(void) {
    io
    ll t;
    t = 1;
    // cin >> t;
    while (t--)solve();
    return 0;
}
