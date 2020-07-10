

#include<iostream>
#include<math.h>
using namespace std;
#define inf 1e9

class datu{    // a class which will be used to maintain the heap
    public:
       double prob;
       int red;
       int vertex;
       bool operator < (const datu& a){   // operator overloading 
           return prob < a.prob;
       }
       bool operator > (const datu& a){
           return prob > a.prob;
       }
       bool operator == (const datu& a){
           return prob == a.prob;
       }
};
template<typename T>
class Heap{   // Heap class for heap
public:
    T ar[400000];
    int last_ind = 0;
    T operator[](int i){  return ar[i]; }  // operator overloading
    void recur_ins(T x,int i,int j){
        if(i==j){
            return;
        }
        if(ar[i] < ar[j]){
            swap(ar[i],ar[j]);
            i = j;
            j = (j-1)/2;
            recur_ins(x,i,j);
        }
    }
    bool khaali(){   // returns if the heap is empty or not
        if(last_ind == 0)return true;
        else return false;
    }
    void heapify(int i,int j){   // to trickle down the value at root at its desired position
        if(j >= last_ind)return;
        if(ar[i] > ar[j]){
            swap(ar[i],ar[j]);
            if(ar[2*j+1] < ar[2*j+2]){
                heapify(j,2*j+1);
            }
            else{
                heapify(j,2*j+2);
            }
        } else return;
    }
    void insert(T x){   // to insert an element in heap
        ar[last_ind] = x;
        last_ind++;
        recur_ins(x,last_ind-1,(last_ind-2)/2);   // to recursively take the value at its correct position
    }
    void del_min(){   // to delete the minimum value of the heap
        swap(ar[last_ind-1],ar[0]);
        ar[last_ind-1].prob = inf;
        last_ind--;
        if(ar[1] < ar[2]) return heapify(0,1);
        else return heapify(0,2);
    }
};
Heap<datu> heap; // initializing our heap here

void infize(datu ar[]){  // to initialise the heap entries with infinity
    for(int i=0;i<400000;i++){
        ar[i].prob = inf;
    }
}
template<typename T>
class List{  // A class like vectors to store the adjacency list 
    private:
        int size;
        int num_ele;
        T* arr;
    public:  
        List(){   // A basic constructor of this class
            arr = new T[5];
            size = 5;
            num_ele = 0;
        }
        List(int s){  // constructor with some initial size given
            arr = new T[s];
            size = s;
            num_ele = 0;
        } 
        ~List(){ // Destructor of the class List
            delete []arr;
        }
        int Size(){return size;}  // return size of the list
        int num_of_elements(){ return num_ele;}  // return number of elements in the list
        void pb(T val){  // to push a value in the list
            if(num_ele < size){arr[num_ele] = val; num_ele++; return ;}
            int temp = size;
            size = (3*size)/2;
            T* naya = new T[size];
            for(int i=0;i<num_ele;i++){
                naya[i] = arr[i];
            }
            naya[num_ele] = val;
            num_ele++;
            delete []arr;
            arr = naya; 
        }
        T operator[](int i){  // operator overloading
            return arr[i];
        }
};
double g; int k,n,m; // these are to be taken as input in the main
void bfs_type(Heap<datu>&heap,double travers[][1000],List<datu>list[1000],bool travermark[][1000]){ // the function which fills the distance we took to travers to a certain vertex with k number of red edges
   if(heap.khaali())return;
   datu top = heap[0];
   int ver = top.vertex;
   double dist = top.prob;
   int reds = top.red;
   travermark[ver][reds] = true;
   heap.del_min();
   if(reds > k){return bfs_type(heap,travers,list,travermark) ;}  // recursive call
   if(travers[top.vertex][reds] > top.prob)travers[top.vertex][reds] = top.prob;
   else{ return bfs_type(heap,travers,list,travermark);}     // recursive call
   for(int i=0;i<list[ver].num_of_elements();i++){
       datu a;
       a.prob = dist + list[ver][i].prob;
       a.red = reds + list[ver][i].red;
       a.vertex = list[ver][i].vertex;
       if(!travermark[a.vertex][a.red] && a.prob<=g && a.red <=k)
       heap.insert(a);
   }
   return bfs_type(heap,travers,list,travermark);  // recursive call
}
int main(){
    infize(heap.ar);
    cin>>g>>k>>n>>m; // taking g,k,n,m as input
    List<datu>list[1000];
    double travers[n+5][1000]; 
    bool travermark[n+5][1000]; // 2D boolean array to mark if a vertex is visited with some given number of red edges or not
    for(int i=0;i<=n;i++)for(int j=0;j<=k;j++){travers[i][j] = 1e13; travermark[i][j] = 0;}
    for(int i=0;i<m;i++){
        int v1,v2;
        double p;
        int c; 
        cin>>v1>>v2>>p>>c; // taking the n1(same as v1) , n2 (same as v2), p, c as input
        datu a,b;
        a.prob = -log10((double)(1-p)); 
        a.vertex = v1;
        a.red = c;
        b.prob = a.prob;
        b.vertex = v2;
        b.red = c;
        list[v2].pb(a);
        list[v1].pb(b);
    } 
    datu a; 
    a.prob = 0;
    a.red = 0;
    a.vertex = 1;
    heap.insert(a);
    bfs_type(heap,travers,list,travermark);
    bool y = 0;
        for(int j=0;j<=k;j++){
             if(travers[n][j]<=g)y = 1;
        }
    if(y)cout<<"Yes\n";
    else cout<<"No\n";
}
