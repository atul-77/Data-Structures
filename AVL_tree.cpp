#include<iostream>

using namespace std;
#define R (*root)

template<typename T>
class Node{ //a node of the tree
private:
T val;
int h; // height of the subtree from the current node including the node itself.
Node<T> *left;
Node<T> *right;
Node<T> *parent;
public:
Node(){
val = NULL;
right = NULL;
  left = NULL;
parent = NULL;
}
int geth(){
    return h;
}
void seth(int newh){
    h = newh;
}
void incrh(){
    h++;
}
T getval(){
return val;
}
Node<T>* getleft(){
return left;
}
Node<T>* getright(){
return right;
}
Node<T>* getpar(){
return parent;
}
void setval(T input){
val = input;
}
void lefchange(Node<T> *newleft){
left = newleft;
}
void rchange(Node<T> *newright){
right = newright;
}
void parchange(Node<T> *newpar){
parent = newpar;
}
};

template <typename T>
class bst{
private:
Node<T> *root;// =  new Node<T>;
int n; //total numof nodes
public:
bst(T v){
root = new Node<T>;
(*root).setval(v);
root->seth(1);
(*root).lefchange(NULL);
(*root).rchange(NULL);
(*root).parchange(NULL);
}
void rootchange(Node<T>* arb){        //function to change the root
    root = arb;
    return;
}
Node<T>* getroot(){                 
    return root;
}
Node<T>** getrootpointer(){
    Node<T>** loot = &root;
    return loot;
}
int getLh(Node<T>*the_node){            //function to get height of  left subtree
    if(the_node->getleft()==NULL)return 0;
    else return the_node->getleft()->geth();
}
int getRh(Node<T>*the_node){            //function to get height of  right subtree
    if(the_node->getright()==NULL)return 0;
    else return the_node->getright()->geth();
}
int search(T x,Node<T>*root){         //funciton to search a node with value x
if((*root).getval() == NULL){
cout<<"not found"<<endl;
return 0;
}
    else if((*root).getval() == x){
cout<<"found!"<<endl;
return 1;
}
else if((*root).getval() > x){
 root = root->getleft();
}
else if((*root).getval() < x){
   root = root->getright();
}
 return search(x,root);
}
void printinord(Node<T>*temp){                      //function to print the tree via in-order travesal
    if(temp == NULL)return;
    printinord(temp->getleft());
    cout<<temp->getval()<<" and "<<temp->geth()<<"  ,  ";
    printinord(temp->getright());
}
void rightrotate(Node<T>*temproot){                 //function to rotate the subtree clockwise(right) from a given node
    if(temproot==NULL)return;
    Node<T>*nowroot = temproot->getleft();
    Node<T>*baap = temproot->getpar();
    if(baap!=NULL && baap->getright() == temproot)baap->rchange(nowroot);
    else if(baap!=NULL && baap->getleft() == temproot)baap->lefchange(nowroot);
    nowroot->parchange(baap);
    temproot->lefchange(nowroot->getright());
    nowroot->rchange(temproot);
    temproot->parchange(nowroot);
    ///heights adjust
    temproot->seth(max(getLh(temproot),getRh(temproot))+1);
    nowroot->seth(max(getLh(nowroot),getRh(nowroot))+1);
    if(baap==NULL){
        rootchange(nowroot);
    }
    else{
         baap->seth(max(getLh(baap),getRh(baap))+1);
    }
}
  void leftrotate(Node<T>*temproot){                      //function to rotate the subtree anti-clockwise(left) from a given node
    if(temproot==NULL)return;
    Node<T>*nowroot = temproot->getright();
    Node<T>*baap = temproot->getpar();
    if(baap!=NULL && baap->getright() == temproot)baap->rchange(nowroot);
    else if(baap!=NULL && baap->getleft() == temproot)baap->lefchange(nowroot);
    nowroot->parchange(baap);
    temproot->rchange(nowroot->getleft());
    nowroot->lefchange(temproot);
    temproot->parchange(nowroot);
     ///heights adjust
    temproot->seth(max(getLh(temproot),getRh(temproot))+1);
    nowroot->seth(max(getLh(nowroot),getRh(nowroot))+1);
    if(baap==NULL){
        rootchange(nowroot);
    }
    else{
        baap->seth(max(getLh(baap),getRh(baap))+1);
    }
}
void leftleft(Node<T>*temproot){                  //If left-subtree of left-child is greater
    if(temproot==NULL)return;
    rightrotate(temproot);
}
void leftright(Node<T>*temproot){                  //If right-subtree of left-child is greater
    if(temproot==NULL)return;
    Node<T>*temp = temproot->getleft();
    leftrotate(temp);
    rightrotate(temproot);
}
void rightright(Node<T>*temproot){                //If right-subtree of right-child is greater
    if(temproot==NULL)return;
    leftrotate(temproot);
}
void rightleft(Node<T>*temproot){                 //If left-subtree of right-child is greater
    if(temproot==NULL)return;
    Node<T>*temp;
    temp = temproot->getright();
    rightrotate(temp);
    leftrotate(temproot);
}

  void balancetree(Node<T>*the_node){              //function to balance the tree
    if(the_node == NULL)return;
    if(getLh(the_node)-getRh(the_node) >= 2){
        if(getLh(the_node->getleft()) >= getRh(the_node->getleft())){
            leftleft(the_node);
        }
        else if(getLh(the_node->getleft()) < getRh(the_node->getleft())){
            leftright(the_node);
        }
    }
    else if(getRh(the_node)-getLh(the_node) >= 2){
        if(getLh(the_node->getright()) >= getRh(the_node->getright())){
            rightleft(the_node);
        }
        else if(getLh(the_node->getright()) < getRh(the_node->getright())){
            rightright(the_node);
        }
    }
    balancetree(the_node->getpar());
}
int insert(T x,Node<T>*toot){                     ///insert function
if((toot)->getval() == x){
        return 0;
    }
else if((toot)->getval() < x && (toot)->getright()!=NULL){
        (toot) = (toot)->getright();

}
else if((toot)->getval() > x && (toot)->getleft()!=NULL){
    (toot) = (toot)->getleft();
}
else if((toot)->getval() < x && (toot)->getright()==NULL){
    Node<T>*a = new Node<T>;
    a->setval(x);
    a->parchange(toot);
    a->lefchange(NULL);
    a->rchange(NULL);
    a->seth(1);
    (toot)->rchange(a);
     Node<T>*temptoot = toot;
     toot = toot->getright();
    while(toot->getpar()!=NULL && toot->geth() == toot->getpar()->geth()){
            toot = toot->getpar();
            toot->incrh();
    }
    balancetree(temptoot);
    return 1;
}
else if((toot)->getval() > x && (toot)->getleft()==NULL){
     Node<T>*a = new Node<T>;
     a->setval(x);
    a->parchange(toot);
    a->lefchange(NULL);
    a->rchange(NULL);
    a->seth(1);
    (toot)->lefchange(a);
    Node<T>*temptoot = toot;
    toot = toot->getleft();
    while(toot->getpar()!=NULL && toot->geth() == toot->getpar()->geth()){
            toot = toot->getpar();
            toot->incrh();
    }
    balancetree(temptoot);
    return 1;
}
return insert(x,toot);

}

};
int main(){

    bst<int> tree(2);
    for(int i=1;i<=60;i++){
        tree.insert(i,tree.getroot());
        //cout<<(*tree.getrootpointer())->getval()<<" ";
    }
    //tree.printinord(tree.getroot());
    cout<<endl;
    cout<<tree.getroot()->getval();
    cout<<endl;
    tree.search(37,tree.getroot());




}
