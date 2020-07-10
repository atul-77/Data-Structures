// 2018CSB1077

#include<bits/stdc++.h>

using namespace std;
#define endl "\n"

struct twoints{
    double first;
    int second;
};

double _min(double a, double b){
    if(a<b)return a;
    else return b;
}

double _max(double a, double b){
    if(a>b)return a;
    else return b;
}
bool are_equal(double a, double b){
    if(a+0.0000000001 > b && a-0.0000000001 < b)return 1;
    else return 0;
}
int abs_minus(int a,int b){
    if(a>b)return  a-b;
    else return b-a;
}
template <typename T>
class Node{ //a node of the tree
private:
    T regist_num;
    double x;
    double t; /// time of insertion;
    int direction;
    int h; // height of the subtree from the current node including the node itself.
    int n;
    Node<T> *left;
    Node<T> *right;
    Node<T> *parent;
public:
    Node(){
        h = 0;
    right = NULL;
      left = NULL;
    parent = NULL;
    }
    double get_x(){
        return x;
    }
    int get_n(){
        return n;
    }
    double get_t(){
        return t;
    }
    int get_direction(){
        return direction;
    }
    void set_t(double tyo){
        t = tyo;
    }
    void set_direction(int newd){
        direction = newd;
    }
    int get_h(){
        return h;
    }
    void set_h(int newh){
        h = newh;
    }
    void set_x(double new_x){
        x = new_x;
    }
    void set_n(int newn){               ///
        n = newn;
    }
    void incr_n(){
        n++;
    }
    void incrh(){
        h++;
    }
    T get_regist_num(){                          /// to get registration number of  a given node
    return regist_num;
    }
    Node<T>* get_left(){                         /// to get pointer left child
    return left;
    }
    Node<T>* get_right(){                      /// to get pointer right child
    return right;
    }
    Node<T>* get_par(){                        /// to get pointer to the parent node
    return parent;
    }
    void set_regist_num(T input){           /// to change the registration number of a given node
    regist_num = input;
    }
    void lefchange(Node<T> *newleft){       /// to change the left child of a given node
    left = newleft;
    }
    void rchange(Node<T> *newright){      /// to change the right child of a given node
    right = newright;
    }
    void parchange(Node<T> *newpar){       /// to change the parent of a given node
    parent = newpar;
    }
};


template <typename T>
class avl_tree{
private:
    Node<T> *root;// =  new Node<T>;
    int type;
public:
    avl_tree(){
       root = NULL;
    }
    void rootchange(Node<T>* arb){        //function to change the root
        root = arb;
        return;
    }
    Node<T>* get_root(){
        return root;
    }
    Node<T>** get_rootpointer(){
        Node<T>** loot = &root;
        return loot;
    }
    int get_Lh(Node<T>*the_node){            //function to get_ height of  left subtree
        if(the_node->get_left()==NULL)return 0;
        else return the_node->get_left()->get_h();
    }
    int get_Rh(Node<T>*the_node){            //function to get_ height of  right subtree
        if(the_node->get_right()==NULL)return 0;
        else return the_node->get_right()->get_h();
    }
int search(T x,Node<T>*root){         ///function to search a node with regist_numbuer x
    if((*root).get_regist_num() == NULL){
        return 0;
    }
    else if((*root).get_regist_num() == x){
        return 1;
    }
    else if((*root).get_regist_num() > x){
     root = root->get_left();
    }
    else if((*root).get_regist_num() < x){
       root = root->get_right();
    }
     return search(x,root);
}
Node<T>* return_pointer_reg(T x,Node<T>*toot){         ///function to search a node with regist_numbuer x
    if(toot == NULL){
        return NULL;
    }
    else if((*toot).get_regist_num() == x){
        return toot;
    }
    else if((*toot).get_regist_num() > x){
     toot = toot->get_left();
    }
    else if((*toot).get_regist_num() < x){
       toot = toot->get_right();
    }
     return return_pointer_reg(x,toot);
}
double get_the_x(Node<T>* toot){
    if(toot == NULL)return NULL;
    else return toot->get_x();
}
int get_the_dir(Node<T>* toot){
    if(toot == NULL)return 2;
    else return toot->get_direction();
}
Node<T>* return_pointer_x(double x,Node<T>*root){         ///function to search a node with regist_numbuer x
    if(root == NULL){
        return NULL;
    }
    else if((*root).get_x() == x){
        return root;
    }
    else if((*root).get_x() > x){
     root = root->get_left();
    }
    else if((*root).get_x() < x){
       root = root->get_right();
    }
     return return_pointer_reg(x,root);
}
Node<T>* return_upper_of_x(double x,Node<T>*toot){  ///function to return upper bound of x
    if(toot == NULL){
        return NULL;
    }else if(((*toot).get_x()+0.000001) > x && (toot->get_x()-0.000001) < x){
        return toot;
    } else if((*toot).get_x() > x ){
     if(toot->get_left()!=NULL && toot->get_left()->get_x() <= x)return toot;
     else if(toot->get_left()==NULL)return toot;
     toot = toot->get_left();
    }else if((*toot).get_x() < x){
       toot = toot->get_right();
    }
     return return_upper_of_x(x,toot);
}
Node<T>* return_lower_of_x(double x,Node<T>*toot){  ///function to return lower bound of x
    if(toot == NULL){
        return NULL;
    }else if(((*toot).get_x()+0.0000001) > x && (toot->get_x()-0.0000001) < x){
        return toot;
    } else if((*toot).get_x() < x ){
        if(toot->get_right()!=NULL && toot->get_right()->get_x() >= x)return toot;
        else if(toot->get_right()==NULL)return toot;
        toot = toot->get_right();
    }else if((*toot).get_x() > x){
       toot = toot->get_left();
    }
     return return_lower_of_x(x,toot);
}
void rightrotate(Node<T>*temproot){                 ///function to rotate the subtree clockwise(right) from a given node
        if(temproot==NULL)return;
        Node<T>*nowroot = temproot->get_left();
        ///
         int i1=0,i2=0;
                if(nowroot->get_left()!=NULL)i1 = nowroot->get_left()->get_n();
                if(nowroot->get_right()!=NULL)i2 = nowroot->get_right()->get_n();
                nowroot->set_n(i1+i2+1);
         i1 =0, i2=0;
                if(temproot->get_left()!=NULL)i1 = temproot->get_left()->get_n();
                if(temproot->get_right()!=NULL)i2 = temproot->get_right()->get_n();
                temproot->set_n(i1+i2+1);
        ///
        Node<T>*father = temproot->get_par();
        if(father!=NULL && father->get_right() == temproot)father->rchange(nowroot);
        else if(father!=NULL && father->get_left() == temproot)father->lefchange(nowroot);
        nowroot->parchange(father);
        temproot->lefchange(nowroot->get_right());
        nowroot->rchange(temproot);
        temproot->parchange(nowroot);
        ///number of nodes in subtree update
        i1=0,i2=0;
                if(temproot->get_left()!=NULL)i1 = temproot->get_left()->get_n();
                if(temproot->get_right()!=NULL)i2 = temproot->get_right()->get_n();
                temproot->set_n(i1+i2+1);

        i1 =0, i2=0;
                if(nowroot->get_left()!=NULL)i1 = nowroot->get_left()->get_n();
                if(nowroot->get_right()!=NULL)i2 = nowroot->get_right()->get_n();
                nowroot->set_n(i1+i2+1);
        ///heights adjust
        temproot->set_h(max(get_Lh(temproot),get_Rh(temproot))+1);
        nowroot->set_h(max(get_Lh(nowroot),get_Rh(nowroot))+1);
        if(father==NULL){
            rootchange(nowroot);
        }
        else{
             father->set_h(max(get_Lh(father),get_Rh(father))+1);
             while(father->get_par()!=NULL){
            father = father->get_par();
            father->set_h(max(get_Lh(father),get_Rh(father))+1);
            }
        }

}
void leftrotate(Node<T>*temproot){                      ///function to rotate the subtree anti-clockwise(left) from a given node
        if(temproot==NULL)return;
        Node<T>*nowroot = temproot->get_right();
        ///
         int   i1=0,i2=0;
                if(nowroot->get_left()!=NULL)i1 = nowroot->get_left()->get_n();
                if(nowroot->get_right()!=NULL)i2 = nowroot->get_right()->get_n();
                nowroot->set_n(i1+i2+1);
         i1 =0, i2=0;
                if(temproot->get_left()!=NULL)i1 = temproot->get_left()->get_n();
                if(temproot->get_right()!=NULL)i2 = temproot->get_right()->get_n();
                temproot->set_n(i1+i2+1);
        ///
        Node<T>*father = temproot->get_par();
        if(father!=NULL && father->get_right() == temproot)father->rchange(nowroot);
        else if(father!=NULL && father->get_left() == temproot)father->lefchange(nowroot);
        nowroot->parchange(father);
        temproot->rchange(nowroot->get_left());
        nowroot->lefchange(temproot);
        temproot->parchange(nowroot);
         ///number of nodes in subtree update
         i1=0,i2=0;
                if(temproot->get_left()!=NULL)i1 = temproot->get_left()->get_n();
                if(temproot->get_right()!=NULL)i2 = temproot->get_right()->get_n();
                temproot->set_n(i1+i2+1);

        i1 =0, i2=0;
                if(nowroot->get_left()!=NULL)i1 = nowroot->get_left()->get_n();
                if(nowroot->get_right()!=NULL)i2 = nowroot->get_right()->get_n();
                nowroot->set_n(i1+i2+1);
         ///heights adjust
        temproot->set_h(max(get_Lh(temproot),get_Rh(temproot))+1);
        nowroot->set_h(max(get_Lh(nowroot),get_Rh(nowroot))+1);
        if(father==NULL){
            rootchange(nowroot);
        }
        else{
            father->set_h(max(get_Lh(father),get_Rh(father))+1);
             while(father->get_par()!=NULL){
            father = father->get_par();
            father->set_h(max(get_Lh(father),get_Rh(father))+1);
            }
        }

    }
void leftleft(Node<T>*temproot){                  ///If left-subtree of left-child is greater
        if(temproot==NULL)return;
        rightrotate(temproot);
}
void leftright(Node<T>*temproot){                  ///If right-subtree of left-child is greater
        if(temproot==NULL)return;
        Node<T>*temp = temproot->get_left();
        leftrotate(temp);
        rightrotate(temproot);
    }
void rightright(Node<T>*temproot){                ///If right-subtree of right-child is greater
        if(temproot==NULL)return;
        leftrotate(temproot);
    }
void rightleft(Node<T>*temproot){                 ///If left-subtree of right-child is greater
        if(temproot==NULL)return;
        Node<T>*temp;
        temp = temproot->get_right();
        rightrotate(temp);
        leftrotate(temproot);
    }
void balancetree(Node<T>*the_node){              ///function to balance the tree
        if(the_node == NULL)return;
        if(get_Lh(the_node)-get_Rh(the_node) >= 2){
            if(get_Lh(the_node->get_left()) >= get_Rh(the_node->get_left())){
                leftleft(the_node);
            }
            else if(get_Lh(the_node->get_left()) < get_Rh(the_node->get_left())){
                leftright(the_node);
            }
        }
        else if(get_Rh(the_node)-get_Lh(the_node) >= 2){
            if(get_Lh(the_node->get_right()) >= get_Rh(the_node->get_right())){
                rightleft(the_node);
            }
            else if(get_Lh(the_node->get_right()) < get_Rh(the_node->get_right())){
                rightright(the_node);
            }
        }
        balancetree(the_node->get_par());
    }
int Insert1(T r,double X,double t, int D, Node<T>*toot){                     ///insert function for registration_number tree
    if(toot == NULL){
        root = new Node<T>();
        (*root).set_regist_num(r);
        (*root).set_x(X);
        (*root).set_direction(D);
        root->set_h(1);
        root->set_t(0);
        root->set_n(1);
        (*root).lefchange(NULL);
        (*root).rchange(NULL);
        (*root).parchange(NULL);
        return 1;
    }
    if((toot)->get_regist_num() == r){
            return 0;
        }
    else if((toot)->get_regist_num() < r && (toot)->get_right()!=NULL){
            (toot) = (toot)->get_right();

    }
    else if((toot)->get_regist_num() > r && (toot)->get_left()!=NULL){
        (toot) = (toot)->get_left();
    }
    else if((toot)->get_regist_num() < r && (toot)->get_right()==NULL){
        Node<T>*a = new Node<T>();
        a->set_regist_num(r);
        a->parchange(toot);
        a->lefchange(NULL);
        a->rchange(NULL);
        a->set_h(1);
        a->set_x(X); a->set_direction(D); a->set_t(t);
        a->set_n(1);
        (toot)->rchange(a);
         Node<T>*temptoot = toot;
         while(toot!=NULL){
                toot->incr_n();
                toot = toot->get_par();
        }
        toot = temptoot;
        toot = toot->get_right();
        while(toot->get_par()!=NULL && toot->get_h() == toot->get_par()->get_h()){
                toot = toot->get_par();
                toot->incrh();
        }
        balancetree(temptoot);
        return 1;
    }
    else if((toot)->get_regist_num() > r && (toot)->get_left()==NULL){
         Node<T>*a = new Node<T>();
         a->set_regist_num(r);
        a->parchange(toot);
        a->lefchange(NULL);
        a->rchange(NULL);
        a->set_h(1);
        a->set_x(X);
        a->set_direction(D);
        a->set_t(0);
        a->set_n(1);
        (toot)->lefchange(a);
        Node<T>*temptoot = toot;
         while(toot!=NULL){
                toot->incr_n();
                toot = toot->get_par();

        }
        toot = temptoot;
        toot = toot->get_left();
        while(toot->get_par()!=NULL && toot->get_h() == toot->get_par()->get_h()){
                toot = toot->get_par();
                toot->incrh();
        }
        balancetree(temptoot);
        return 1;
    }
    return Insert1(r,X,t,D,toot);

}
int Insert2or3(T r,double X,double t, int D, Node<T>*toot){///insert function X is x0
        if(toot == NULL){
             root = new Node<T>;
            (*root).set_regist_num(r);
            (*root).set_x(X);
            (*root).set_direction(D);
            root->set_h(1); //type = typ;
            root->set_t(0);
            root->set_n(1);
            (*root).lefchange(NULL);
            (*root).rchange(NULL);
            (*root).parchange(NULL);
            return 1;
        }
        if((toot)->get_x() == X){
            return 0;
        }
else if((toot)->get_x() < X && (toot)->get_right()!=NULL){
            (toot) = (toot)->get_right();

    }
else if((toot)->get_x() > X && (toot)->get_left()!=NULL){
        (toot) = (toot)->get_left();
    }
else if((toot)->get_x() < X && (toot)->get_right()==NULL){
        Node<T>*a = new Node<T>;
        a->set_regist_num(r);
        a->parchange(toot);
        a->lefchange(NULL);
        a->rchange(NULL);
        a->set_h(1);
        a->set_x(X); a->set_direction(D); a->set_t(0);
        a->set_n(1);
        (toot)->rchange(a);
         Node<T>*temptoot = toot;
          while(toot!=NULL){
                toot->incr_n();
                toot = toot->get_par();
            }
        toot = temptoot;
        toot = toot->get_right();
        while(toot->get_par()!=NULL && toot->get_h() == toot->get_par()->get_h()){
                toot = toot->get_par();
                toot->incrh();
        }
        balancetree(temptoot);
        return 1;
    }
else if((toot)->get_x() > X && (toot)->get_left()==NULL){
         Node<T>*a = new Node<T>;
         a->set_regist_num(r);
        a->parchange(toot);
        a->lefchange(NULL);
        a->rchange(NULL);
        a->set_h(1);
        a->set_x(X); a->set_direction(D); a->set_t(0);
        a->set_n(1);
        (toot)->lefchange(a);

        Node<T>*temptoot = toot;
         while(toot!=NULL){
                toot->incr_n();
                toot = toot->get_par();
        }
        toot = temptoot;
        toot = toot->get_left();
        while(toot->get_par()!=NULL && toot->get_h() == toot->get_par()->get_h()){
                toot = toot->get_par();
                toot->incrh();
        }

        balancetree(temptoot);
        return 1;
    }
    return Insert2or3(r,X,t,D,toot);

}
int Delete2or3(T r,double X,Node<T>* toot){     ///r,t
        if(toot == NULL)return 0;
        else if(toot->get_x() < X)toot = toot->get_right();
        else if(toot->get_x() > X)toot = toot->get_left();
        else if(toot->get_x() == X){
          //  Node<T>* father = toot->get_par();
            Node<T>* ttcpy =  toot;
          if(ttcpy->get_right() != NULL){
                 ttcpy = ttcpy->get_right();
                while(ttcpy->get_left() != NULL)ttcpy = ttcpy->get_left();
                T rval = ttcpy->get_regist_num(); double xval = ttcpy->get_x(); int dirval = ttcpy->get_direction();
                Node<T>* ttcpy_ka_father = ttcpy->get_par();
                if(ttcpy_ka_father != NULL){
                     bool tell_me; if(ttcpy == ttcpy_ka_father->get_left())tell_me = 0;
                else tell_me = 1;
               delete(ttcpy);
                if(tell_me)ttcpy_ka_father->rchange(ttcpy->get_right());
                else ttcpy_ka_father->lefchange(ttcpy->get_right());
                }
                toot->set_direction(dirval); toot->set_x(xval); toot->set_regist_num(rval);
                Node<T>* father_copy = ttcpy_ka_father;
                ///
                while(father_copy!=NULL){
                    int n_new = father_copy->get_n()-1;
                    father_copy->set_n(n_new);
                    father_copy = father_copy->get_par();
                }
                ///
                balancetree(ttcpy_ka_father);
          }
          else {
                Node<T>* ttcpy_ka_father = ttcpy->get_par();
                if(ttcpy_ka_father != NULL){
                    if(ttcpy_ka_father->get_left() == ttcpy){
                        ttcpy_ka_father->lefchange(ttcpy->get_left());
                        delete(ttcpy);
                    }
                    else {
                        ttcpy_ka_father->rchange(ttcpy->get_left());
                        delete(ttcpy);
                    }
                    ///
                     Node<T>* father_copy = ttcpy_ka_father;
                while(father_copy!=NULL){
                    int n_new = father_copy->get_n() -1;
                    father_copy->set_n(n_new);
                    father_copy = father_copy->get_par();
                }
                ///
                    balancetree(ttcpy_ka_father);

                }
                else {
                    rootchange(ttcpy->get_left());
                }
          }
            return 1;
        }
        return Delete2or3(r,X,toot);
    }
twoints Delete1(T r,Node<T>* toot){     ///r,t
        if(toot == NULL)return {0,0};
        else if(toot->get_regist_num() < r)toot = toot->get_right();
        else if(toot->get_regist_num() > r)toot = toot->get_left();
        else if(toot->get_regist_num() == r){
            Node<T>* ttcpy =  toot;
            twoints a;
            a.first = ttcpy->get_x();
            a.second = ttcpy->get_direction();
          if(ttcpy->get_right() != NULL){
                 ttcpy = ttcpy->get_right();
                while(ttcpy->get_left() != NULL)ttcpy = ttcpy->get_left();
                T rval = ttcpy->get_regist_num(); double xval = ttcpy->get_x(); int dirval = ttcpy->get_direction();
                Node<T>* ttcpy_ka_father = ttcpy->get_par();
                if(ttcpy_ka_father != NULL){
                    bool tell_me; if(ttcpy == ttcpy_ka_father->get_left())tell_me = 0;
                    else tell_me = 1;
                    delete(ttcpy);
                    if(tell_me)ttcpy_ka_father->rchange(ttcpy->get_right());
                    else ttcpy_ka_father->lefchange(ttcpy->get_right());
                }
                ////////////////////////////
                Node<T>* father_copy = ttcpy_ka_father;
                while(father_copy!=NULL){
                    int n_new = father_copy->get_n() -1;
                    father_copy->set_n(n_new);
                    father_copy = father_copy->get_par();
                }
                ////////////////////////////
                toot->set_direction(dirval); toot->set_x(xval); toot->set_regist_num(rval);

                balancetree(ttcpy_ka_father);
          }
          else {
                Node<T>* ttcpy_ka_father = ttcpy->get_par();
                if(ttcpy_ka_father != NULL){
                    if(ttcpy_ka_father->get_left() == ttcpy){
                        ttcpy_ka_father->lefchange(ttcpy->get_left());
                        delete(ttcpy);
                    }
                    else {
                        ttcpy_ka_father->rchange(ttcpy->get_left());
                        delete(ttcpy);
                    }
                    ////////////////////////////
               Node<T>* father_copy = ttcpy_ka_father;
                while(father_copy!=NULL){
                    int n_new = father_copy->get_n() -1;
                    father_copy->set_n(n_new);
                    father_copy = father_copy->get_par();
                }
                ///////////////////////////
                balancetree(ttcpy_ka_father); /////////////------------------------------------------------------

                }
                else {
                    rootchange(ttcpy->get_left());
                }
          }
            return a;
        }
        return Delete1(r,toot);
    }
};
avl_tree<int> regtree; /// tree with balance parameter as registration number
avl_tree<int> xleft;    /// tree with balance parameter as x coordinate of cars going left
avl_tree<int> xright;   /// tree with balance parameter as x coordinate of cars going right
int curr = 0;
int count_smaller(double x,Node<int>*Ptree,int smaller){ /// to find numbers of car with x coordinate smaller than x
    if(Ptree == NULL)return smaller;
    if(Ptree->get_x() < x){
        smaller += Ptree->get_n();
        if(Ptree->get_right()!=NULL)smaller -= Ptree->get_right()->get_n();
        Ptree = Ptree->get_right();
    }
    else Ptree = Ptree->get_left();
    return count_smaller(x,Ptree,smaller);
}
int count_greater(double x,Node<int>*Ptree,int great){
     if(Ptree == NULL)return great;
     if(Ptree->get_x() > x){
        great += Ptree->get_n();
        if(Ptree->get_left()!=NULL)great -= Ptree->get_left()->get_n();
        Ptree = Ptree->get_left();
     }
     else Ptree = Ptree->get_right();
     return count_greater(x,Ptree,great);
}
int insert(int r,double x, double t, int d){   /// function to insert a car with registration  number r
    if(d==0){
        regtree.Insert1(r,x+t,t,d,regtree.get_root());
        // if(r==2) return 1;
        return xleft.Insert2or3(r,x+t,t,d,xleft.get_root());

    }
    else{
        regtree.Insert1(r,x-t,t,d,regtree.get_root());
       return  xright.Insert2or3(r,x-t,t,d,xright.get_root());
    }
}
int remove(int r, double t){            /// function to remove a car with registration  number r
    twoints a = regtree.Delete1(r,regtree.get_root());
    double x = a.first; int dir = a.second;
    if(dir==0)return xleft.Delete2or3(r,x,xleft.get_root());
    else return xright.Delete2or3(r,x,xleft.get_root());
}
int find_immediate_left(int r, double t){  /// function to find immediate left car of the car with given registration number
    Node<int>* P = regtree.return_pointer_reg(r,regtree.get_root());
    if(P== NULL){return -1;}
    double x = P->get_x();
    int dir = P->get_direction();
    if(dir)x += t;
    else x -= t;
    Node<int>*Pright = xright.return_lower_of_x(x-t,xright.get_root());
    Node<int>*Pleft = xleft.return_lower_of_x(x+t,xleft.get_root());
    if(Pright!=NULL && Pright->get_regist_num() == r){
            Pright = Pright->get_left();
    }
    if(Pleft!=NULL &&  Pleft->get_regist_num() == r){
            Pleft = Pleft->get_left();
    }
    int i1 = -1;
    if(Pright!=NULL)i1 = Pright->get_regist_num();
    int i2 = -1;
    if(Pleft!=NULL)i2 = Pleft->get_regist_num();
    if(i1 == i2 && i1 !=-1){
            cout<<_min(i1,i2)<<" ";

    }
    return _max(i1,i2);
}
int find_immediate_right(int r, double t){   /// find the car just to right of given car, default output = -1 if no car found
    Node<int>* P = regtree.return_pointer_reg(r,regtree.get_root());
    if(P== NULL){return -1;}
    double x = P->get_x();
    int dir = P->get_direction();
    if(dir)x += t;
    else x -= t;
    int mn = 0, its_r = -1, mn2 = 0, its_r2 = -1;
    Node<int>*Pright = xright.return_upper_of_x(x-t,xright.get_root());
    Node<int>*Pleft = xleft.return_upper_of_x(x+t,xleft.get_root());
    if(Pright!=NULL && Pright->get_regist_num() == r)Pright = Pright->get_right();
    if(Pleft!=NULL &&  Pleft->get_regist_num() == r)Pleft = Pleft->get_right();
    int i1 = -1;
    if(Pright!=NULL)i1 = Pright->get_regist_num();
    int i2 = -1;
    if(Pleft!=NULL)i2 = Pleft->get_regist_num();
    if(i1 == i2 && i1 !=-1){
            cout<<_min(i1,i2)<<" ";

    }
    return _max(i1,i2);
}
int count_left(int r, double t){            /// function to count cars at the left of a given car
    Node<int>* P = (regtree.return_pointer_reg(r,regtree.get_root()));
    if(P==NULL)return 0;
    double x = P->get_x();
    if(P->get_direction())x += t;
    else x -= t;
    Node<int>*Pxright = xright.get_root();
    Node<int>*Pleft = xleft.get_root();
    int LEFT = 0;
    LEFT += count_smaller(x-t,Pxright,0);
    LEFT += count_smaller(x+t,Pleft,0);
    return LEFT;

}
int count_right(int r, double t){          /// function to count cars at the right of a given car
    Node<int>* P = (regtree.return_pointer_reg(r,regtree.get_root()));
    if(P==NULL)return 0;
    double x = P->get_x();
    if(P->get_direction())x += t;
    else x -= t;
    Node<int>*Pxright = xright.get_root();
    Node<int>*Pleft = xleft.get_root();
    int LEFT = 0;
    LEFT += count_greater(x-t,Pxright,0);
    LEFT += count_greater(x+t,Pleft,0);
    return LEFT;

}
int number_of_crossing(int r, double t){  /// function to output number of crossings
    Node<int>* P = regtree.return_pointer_reg(r,regtree.get_root());
    if(P==NULL)return 0;
    if(regtree.get_root() == NULL)return 0;
    int tot_cars = regtree.get_root()->get_n();
    int dir = P->get_direction();
    int carlef0 = count_left(r,curr);
    int carlef1 = count_left(r,t);
    int carrt0  = count_right(r,curr);
    int carrt1  = count_right(r,t);
    int ans = 0;
    if(P->get_direction()){
        if(((carlef0 + carrt0 )< (tot_cars-1))){
            ans  = abs_minus(carlef1,carlef0)-1;
            if(ans>0)return ans;
            else return 0;

        }
        else  return abs_minus(carlef1,carlef0);
    }
   else {
        if(((carlef0 + carrt0 )< (tot_cars-1))){
            ans  = abs_minus(carrt1,carrt0)-1;
            if(ans>0)return ans;
            else return 0;
        }
        else  return abs_minus(carrt1,carrt0);

   }
}
int main(){
 int q;
 cin>>q;
 while(q--){
    int f;
    int r,d;
    double x,t;
    cin>>f;
    if(f==1){
        cin>>r>>x>>t>>d;
        insert(r,x,t,d);
        curr = t;
    }
    else if(f==2){
        cin>>r>>t;
        remove(r,t);
        curr = t;
    }
    else if(f==3){
        cin>>r>>t;
        cout<<find_immediate_left(r,t)<<endl;
    }
    else if(f==4){
        cin>>r>>t;
        cout<<find_immediate_right(r,t)<<endl;
    }
    else if(f==5){
        cin>>r>>t;
        cout<<count_left(r,t)<<endl;
    }
    else if(f==6){
        cin>>r>>t;
        cout<<count_right(r,t)<<endl;
    }
    else{
        cin>>r>>t;
        cout<<number_of_crossing(r,t)<<endl;
    }

 }
}


