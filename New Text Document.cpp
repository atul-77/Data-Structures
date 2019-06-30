#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll merge(ll a[],ll i,ll m , ll j){
    if(i==j){
        return 0;
    }
    ll inv = 0;
    ll p[j-i+1] ;
    ll k=0;
    ll p1=i ,p2=m+1;
    while(p1<=m && p2<=j){
        if(a[p1]<=a[p2]){
            p[k] = a[p1];
            k++; p1++;
        }
        else{
            inv += m - p1 + 1;
            p[k] = a[p2];
            k++ ; p2++;
        }
    }
  
        while(p1<=m){
          p[k] = a[p1];
          k++; p1++;
        }
    
         while(p2<=j){
          p[k] = a[p2];
          k++; p2++;
        }
    
    for(ll u=0;u<j-i+1;u++){
        a[u+i] = p[u];
        
    }
   // free(p);
    return inv;
}
ll mergesort(ll ar[],ll i,ll j){
    if(i==j)return 0;
    if(i<j){
        ll mid = i + (j-i)/2;
        ll a1 = mergesort(ar,i,mid);   ll a2 = mergesort(ar,mid+1,j);
        ll a =  merge(ar,i,mid,j);
        return a + a1 + a2;
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // int t;
    // cin>>t;
    // while(t--){
    //   ll n,q1,s=0,y,p,q,l,r,x;
    //   int type;
    //   cin>>n>>q1;
    //   unordered_map<ll,ll> a;
    //   for(ll i=0;i<n;i++)a.insert({i+1,i+1});
    //   for(ll i=0;i<q1;i++){
    //       cin>>type;
    //       if(type==1){
    //           cin>>y;
    //           x = (y + s);
    //           a[x] = 0;
    //       }
    //       else if(type==2){
    //           cin>>p>>q;
    //           l = (p + s);
    //           r = (q + s);
    //           ll temp = r;
    //           while(a[temp]==0 && temp>l){
    //               temp--;
    //           }
    //           s += a[temp];
    //           s = s%n;
    //           cout<<a[temp]<<"\n";
    //       }
    //   }
      
       
      
       
   // }
   
   ll ar[] = {8,4,3,2,1};
   cout<<mergesort(ar,0,4)<<"\n";
   for(ll i=0;i<5;i++)cout<<ar[i]<<" ";
  
}
