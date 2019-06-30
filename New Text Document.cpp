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
    
   // Example array , ar[] :- 
   ll ar[] = {8,4,3,2,1};
   cout<<mergesort(ar,0,4)<<"\n";
   for(ll i=0;i<5;i++)cout<<ar[i]<<" ";
  
}
