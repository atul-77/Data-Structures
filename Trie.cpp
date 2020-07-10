/*
 NAME : ATUL KUMAR TIWARI
 ENTRY NO: 2018CSB1077
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define endl "\n"
int sum = 0;
class node{ // node class
    private:
        int count; 
        node* one;
        node* zero;
        node* parent;
        int finish;
    public:
        node(){
            count = 0; 
            one = NULL;
            zero = NULL;
            parent = NULL;
            finish = false;
        }
        int getcount(){return count;}
        void incrcount(){count++;}
        void decrcount(){count--;}
        node* getone(){return one;}
        node* getparent(){return parent;}
        void setparent(node* ptr){parent = ptr;}
        void setone(node* ptr){one = ptr;}
        node* getzero(){return zero;}
        void setzero(node* ptr){zero = ptr;}
        int getfinish(){return finish;}
        void setfinish(int val){finish = val;}
};

class trie{   // trie class
    private:
        node* root;
    public:
        trie(){
            root = new node();
        }
        node* getroot(){return root;}  
        int search(string str,int i,int strsize,node* thisnode){
            if(thisnode==NULL)return 0;
            if(i==strsize){
                if(thisnode->getfinish()){
                    return 1;
                }
                else{
                    return 0;
                }
            }
            if(str[i]=='1'){
                thisnode = thisnode->getone();
                return search(str,i+1,strsize,thisnode);
            }
            else if(str[i]=='0'){
                thisnode = thisnode->getzero();
                return search(str,i+1,strsize,thisnode);
            }
        }
        void increment(node* ptr){ // increments the value of node, value is number of strings below this node
            if(ptr == NULL)return;
            ptr->incrcount();
            increment(ptr->getparent());
        }
        void decrement(node* ptr){ // node value decrementor
            if(ptr == NULL)return ;
            if(ptr->getcount()) ptr->decrcount();
            decrement(ptr->getparent());
        }
        int insertinator(string str, int i,int strsize, node* thisnode){ // insert function utility 
            if(i==strsize){
     
                    thisnode->setfinish(thisnode->getfinish()+1);
                    increment(thisnode);
                    return 1;
          
            }
            if(str[i] == '1'){
                if(thisnode->getone() == NULL){
                    node* a = new node();
                    thisnode->setone(a);
                    a->setparent(thisnode);
                }
                return insertinator(str,i+1,strsize,thisnode->getone());
            }
            else if(str[i] == '0'){
                if(thisnode->getzero() == NULL){
                    node* a = new node();
                    thisnode->setzero(a);
                    a->setparent(thisnode);
                }
                return insertinator(str,i+1,strsize,thisnode->getzero());
            }
        }
        int removeinator(string str,int i,int strsize,node* thisnode){ // remove function utility
            if(thisnode == NULL)return 0; 
            if(i==strsize){
                    thisnode->setfinish(thisnode->getfinish() - 1);
                    decrement(thisnode);
                    return 1;
            }
            if(str[i] == '1'){
                return removeinator(str,i+1,strsize,thisnode->getone());
            }
            else if(str[i] == '0'){
                return removeinator(str,i+1,strsize,thisnode->getzero());
            }
        }
        int search1(string p,int i,int psize,node* thisnode){ // search 1 utility
            if(thisnode == NULL){return 0;}
            if(i==psize){
                return thisnode->getcount();
            }
            if(p[i] == '1'){
                return search1(p,i+1,psize,thisnode->getone());
            }
            else if(p[i] == '0'){
                return search1(p,i+1,psize,thisnode->getzero());
            }
        }
        void s2(string p,int i,int psize,node* thisnode,int level){
            if(thisnode == NULL){return;} 
            if(i==psize){ sum += thisnode->getcount();return ;}
            if(i!=0)sum += thisnode->getcount();
            if(p[i] == '?'){
                s2(p,i+1,psize,thisnode->getone(),level+1);
                s2(p,i+1,psize,thisnode->getzero(),level+1);
            }
            else if(p[i] == '1'){s2(p,i+1,psize,thisnode->getone(),level+1);}
            else if(p[i]=='0'){ s2(p,i+1,psize,thisnode->getzero(),level+1);}
            return;
        }
        int result(){
            int res = sum;
            sum = 0;
            return res;
        }
        int search2(string p){
            s2(p,0,p.size(),root,0);
            int res = result();
            sum = 0;
            return res;
        }
        void suffix_inserter(string s,int i,node* thisnode){
            if(i == s.size())return;
            insertinator(s,i,s.size(),root);
            suffix_inserter(s,i+1,thisnode);
        }

};
trie S,suffs;  // two tries suffs contains all the suffix, S is the set of all strings
int insert(string s){ // insert function
    if(S.search(s,0,s.size(),S.getroot()))return 0;
    else if(S.insertinator(s,0,s.size(),S.getroot())){
        suffs.suffix_inserter(s,0,suffs.getroot());
        return 1;
    }
    else return 0;
}
int search_one(string s){ // search 1
    return suffs.search1(s,0,s.size(),suffs.getroot());
}
int search_two(string s){ // search 2
    return S.search2(s);
}
int removestr(string s){
    if(!S.search(s,0,32,S.getroot()))return 0;
    S.removeinator(s,0,s.size(),S.getroot());
    for(int i=0;i<s.size();i++){
        suffs.removeinator(s,i,s.size(),suffs.getroot());
    }
    return 1;
}
int main(){
    int m;
    cin>>m;
    while(m--){
        int fn; 
        cin>>fn;
        if(fn==1){
            string p; 
            cin>>p;
            insert(p);
        }
        else if(fn==2){
            string p;
            cin>>p;
            removestr(p);
        }
        else if(fn==3){
            string p; 
            cin>>p;
            cout<<search_one(p)<<endl;
        }
        else if(fn==4){
            string p;
            cin>>p;
            cout<<search_two(p)<<endl;
        }
        else{
            cout<<"function can either 1 ,2, 3, or 4 only\n";
        }
    }
}
