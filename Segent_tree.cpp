#include<bits/stdc++.h>
using namespace std;
#define max 10000
#define ll long long int
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define endl "\n"
ll st[max] = {0};

void maketree(ll arr[],ll st[],ll i,ll l,ll r){
    if(l==r){
        st[i] = arr[l];
        return;
    }
    ll sum = 0;
    ll mx = INT_MAX;
    for(ll j=l;j<=r;j++)mx = min(mx,arr[j]);
    st[i] = mx;
    maketree(arr,st,2*i+1,l,(l + (r-l)/2)),maketree(arr,st,2*i+2,(l + (r-l)/2)+1,r);
}
ll getmin(ll st[],ll i,ll l,ll r,ll qs,ll qe){
    if(r<qs || qe<l)return -1;
    if(l>=qs && r<=qe)return st[i];
    return min(getmax(st,2*i+1,l,(l + (r-l)/2),qs,qe) , getmin(st,2*i+2,(l + (r-l)/2)+1,r,qs,qe));
}
void update(ll st[],ll si,ll rs, ll rend,ll i, ll change,ll seg_end){
   if(i<rs || i>rend)return;
   if(si > seg_end)return ;
   st[si] += change;
   update(st,si*2+1,rs,(rs+rend)/2,i,change,seg_end );
   update(st,si*2+2,(rs+rend)/2 + 1,rend,i,change,seg_end );
}
int main(){
    io
    ll ar[] = {1,3,5,7,9,11};
    int seg_end = 14;
    maketree(ar,st,0,0,5,seg_end);
    for(int i=0;i<seg_end;i++)cout<<st[i]<<" "; cout<<endl;
    // for(int i=0;i<seg_end;i++)cout<<i<<" ";
    update(st,0,0,seg_end,3,100,seg_end);
    for(int i=0;i<seg_end;i++)cout<<st[i]<<" ";
}
