// 2018CSB1077
#include<iostream>
using namespace std;
#define mAx 10000
#define inf 9999999


int curr_time = 0;
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
    int PosBack;
    int PosFront;
    double x; // its x0 calculated as x-vt
    double t; /// last updated time ;
    int h; // height of the subtree from the current node including the node itself.
    double velocity;
    Node<T> *left;
    Node<T> *right;
    Node<T> *parent;
public:
    Node(){
        h = 0;
        PosBack = -1;
        PosFront = -1;
    right = NULL;
      left = NULL;
    parent = NULL;
    }
    double get_x(){
        return x;
    }
    int get_PosBack(){
        return PosBack;
    }
    int get_PosFront(){
        return PosFront;
    }
    int get_vel(){
        return velocity;
    }
    double get_t(){
        return t;
    }
    void set_t(double tyo){
        t = tyo;
    }
    void set_PosBack(int newpos){
        PosBack = newpos;
    }
    void set_PosFront(int newpos){
        PosFront = newpos;
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
    void set_vel(int newvel){               ///
        velocity = newvel;
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
class hp_int{    //struct for heaps
    public:
    double priority;  // (x1-x2)/(v1-v2)
    Node<int>* Rback;
    Node<int>* Rfront;
    void clear(){
        priority = inf+1;
        Rback = NULL; Rfront = NULL;
    }
};
void swap(hp_int &a, hp_int &b){
    hp_int temp = a;
    a = b; b = temp;
}
class min_heap{    /// this is a perfectly working heap class, please give marks
    private: 
        hp_int hp_arr[mAx];
        int hp_ind; // initialised with 0
    public:
        min_heap(){
             for(int i=0;i<mAx;i++)hp_arr[i].clear();
            hp_ind = 0;
        }
        int get_hp_ind(){
            return hp_ind;
        }
        hp_int get_headIdx(int i){
            return hp_arr[i];
        }
        void trickle_down(int i){
             while(i<=mAx){
                if(hp_arr[i].priority > hp_arr[2*i + 1].priority && hp_arr[2*i +1].priority < hp_arr[2*i+2].priority){
                    swap(hp_arr[i], hp_arr[2*i+1]);
                    i = 2*i+1;
                }
                else if(hp_arr[i].priority > hp_arr[2*i + 2].priority){
                    swap(hp_arr[i], hp_arr[2*i+2]);
                    i = 2*i+2;
                }
                else break;
            }
        }
        int insert_minhp(hp_int val){
            hp_arr[hp_ind] = val;
            int i = hp_ind;
            hp_ind ++;
            while(i>0 && hp_arr[i].priority<hp_arr[(i-1)/2].priority){
                swap(hp_arr[i],hp_arr[(i-1)/2]);
                i = (i-1)/2;
            }
            return i;
        }
        void del_min(){
            if(hp_ind == 0)return ;
            swap(hp_arr[0],hp_arr[hp_ind-1]);
            hp_ind--;
            hp_arr[hp_ind].clear();

            int i = 0;
            trickle_down(i);
        }
        void remove_hpnode(int i){
            hp_ind--;
            swap(hp_arr[i],hp_arr[hp_ind]);
            hp_arr[hp_ind].clear();
            trickle_down(i);
        }
         void prntheap(){
             for(int i=0;i<hp_ind;i++){
                 cout<<hp_arr[i].priority<<" ";
             }
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
 Node<T>* search(T x,Node<T>*root){         ///function to search a node with val x+v*t
     if((*root).get_regist_num() == NULL){
         return 0;
     }
     else if((*root).get_x()+root->get_vel()*curr_time == x){
         return root;
     }
     else if((*root).get_x()+root->get_vel()*curr_time > x){
      root = root->get_left();
     }
     else if((*root).get_x()+root->get_vel()*curr_time < x){
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
Node<T>* return_upper_of_xvt(double x,double v,int r,Node<T>*toot){  ///function to return upper bound of x+v*t
    if(toot == NULL){
        return NULL;
    }
    else if(toot->get_x()+toot->get_vel()*curr_time < x)toot = toot->get_right();
    else if(toot->get_x()+toot->get_vel()*curr_time == x){
        if(toot->get_regist_num() == r)toot = toot->get_right();
        else if(toot->get_vel()>v){
            if(toot->get_left()!=NULL && toot->get_left()->get_x() + toot->get_left()->get_vel()*curr_time == x && toot->get_left()->get_vel()>v)toot = toot->get_left();
            else return toot;
        }
        else if(toot->get_vel() < v){
            toot = toot->get_right();
        }
    }
     else if(toot->get_x()+toot->get_vel()*curr_time > x){
        double temp;
        if(toot->get_left()!=NULL && (temp=(toot->get_left()->get_x() + toot->get_left()->get_vel()*curr_time)) == x && toot->get_left()->get_vel() > v){
            toot = toot->get_left();
        }
        else if(toot->get_left()!=NULL && temp>x)toot = toot->get_left();
        else return toot;
    }
     return return_upper_of_xvt(x,v,r,toot);
}
///
Node<T>* return_lower_of_xvt(double x,double v,int r,Node<T>*toot){  ///function to return upper bound of x+v*t
    if(toot == NULL){
        return NULL;
    }
    else if(toot->get_x()+toot->get_vel()*curr_time > x)toot = toot->get_left();
    else if(toot->get_x()+toot->get_vel()*curr_time == x){
        if(toot->get_regist_num() == r)toot = toot->get_left();
        else if(toot->get_vel()<v){
            if(toot->get_right()!=NULL && toot->get_right()->get_x()+toot->get_right()->get_vel()*curr_time == x && toot->get_right()->get_vel()<v)toot = toot->get_right();
            else return toot;
        }
        else if(toot->get_vel() > v){
            toot = toot->get_left();
        }
    }
     else if(toot->get_x()+toot->get_vel()*curr_time < x){
        double temp;
        if(toot->get_right()!=NULL && (temp=(toot->get_right()->get_x() + toot->get_right()->get_vel()*curr_time)) == x && toot->get_left()->get_vel() < v){
            toot = toot->get_right();
        }
        else if(toot->get_right()!=NULL && temp<x)toot = toot->get_right();
        else return toot;
    }
     return return_lower_of_xvt(x,v,r,toot);
}

void rightrotate(Node<T>*temproot){                 ///function to rotate the subtree clockwise(right) from a given node
        if(temproot==NULL)return;
        Node<T>*nowroot = temproot->get_left();
        Node<T>*father = temproot->get_par();
        if(father!=NULL && father->get_right() == temproot)father->rchange(nowroot);
        else if(father!=NULL && father->get_left() == temproot)father->lefchange(nowroot);
        nowroot->parchange(father);
        temproot->lefchange(nowroot->get_right());
        nowroot->rchange(temproot);
        temproot->parchange(nowroot);
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
        Node<T>*father = temproot->get_par();
        if(father!=NULL && father->get_right() == temproot)father->rchange(nowroot);
        else if(father!=NULL && father->get_left() == temproot)father->lefchange(nowroot);
        nowroot->parchange(father);
        temproot->rchange(nowroot->get_left());
        nowroot->lefchange(temproot);
        temproot->parchange(nowroot);
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
///
Node<T>* Insert_reg(T r,double X,double vel, Node<T>*toot){   ///insert function for registration_number tree
    if(toot == NULL){
        
        Node<T>* root = new Node<T>();
         // return 0;
        (*root).set_regist_num(r);
       
        (*root).set_x(X);
        
        (*root).set_vel(vel);
        root->set_h(1);
        root->set_t(curr_time);
        return 0;
        //root->set_n(1);
        (*root).lefchange(NULL);
        (*root).rchange(NULL);
        (*root).parchange(NULL);
        rootchange(root);
        return root;
    }
    if((toot)->get_regist_num() == r){
            return NULL;
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
        a->set_x(X); a->set_vel(vel); a->set_t(curr_time);
        (toot)->rchange(a);
         Node<T>*temptoot = toot;
        toot = temptoot;
        toot = toot->get_right();
        while(toot->get_par()!=NULL && toot->get_h() == toot->get_par()->get_h()){
                toot = toot->get_par();
                toot->incrh();
        }

        balancetree(temptoot);

        return a;
    }

    else if((toot)->get_regist_num() > r && (toot)->get_left()==NULL){
        
        Node<T>*a = new Node<T>();

        a->set_regist_num(r);
        a->parchange(toot);
        a->lefchange(NULL);
        a->rchange(NULL);
        a->set_h(1);
        a->set_x(X);
        a->set_vel(vel);
        a->set_t(curr_time);
        (toot)->lefchange(a);

        Node<T>*temptoot = toot;
        toot = temptoot;
        toot = toot->get_left();
        while(toot->get_par()!=NULL && toot->get_h() == toot->get_par()->get_h()){
                toot = toot->get_par();
                toot->incrh();
        }
        balancetree(temptoot);
        return a;
    }
    return Insert_reg(r,X,vel,toot);

}
/// X is x0
int Insert_xvt(T r,double X,int vel, Node<T>*toot){                     ///insert function for registration_number tree
    if(toot == NULL){
        root = new Node<T>();
        (*root).set_regist_num(r);
        (*root).set_x(X);
        (*root).set_vel(vel);
        root->set_h(1);
        root->set_t(curr_time);
        //root->set_n(1);
        (*root).lefchange(NULL);
        (*root).rchange(NULL);
        (*root).parchange(NULL);
        return 1;
    }
    if((toot)->get_x() + toot->get_vel()*curr_time == X + vel*curr_time){
            if(toot->get_regist_num() == r)return 0;
            else{
                if(toot->get_vel() < vel){
                    toot = toot->get_right();
                }
                else{
                    toot = toot->get_left();
                }
            }
    }
    else if((toot)->get_x() + toot->get_vel()*curr_time < X + vel*curr_time && (toot)->get_right()!=NULL){
            (toot) = (toot)->get_right();

    }
    else if((toot)->get_x() + toot->get_vel()*curr_time < X + vel*curr_time && (toot)->get_left()!=NULL){
        (toot) = (toot)->get_left();
    }
    else if((toot)->get_x() + toot->get_vel()*curr_time < X + vel*curr_time && (toot)->get_right()==NULL){
        Node<T>*a = new Node<T>();
        a->set_regist_num(r);
        a->parchange(toot);
        a->lefchange(NULL);
        a->rchange(NULL);
        a->set_h(1);
        a->set_x(X); a->set_vel(vel); a->set_t(curr_time);
        (toot)->rchange(a);
         Node<T>*temptoot = toot;
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
        a->set_vel(vel);
        a->set_t(curr_time);
        (toot)->lefchange(a);
        Node<T>*temptoot = toot;
        toot = temptoot;
        toot = toot->get_left();
        while(toot->get_par()!=NULL && toot->get_h() == toot->get_par()->get_h()){
                toot = toot->get_par();
                toot->incrh();
        }
        balancetree(temptoot);
        return 1;
    }
    return Insert_xvt(r,X,vel,toot);

}

 };
 avl_tree<int> regtree; /// tree with balance parameter as registration number
 avl_tree<int> xvt;    /// tree with balance parameter as x coordinate of cars going left
 min_heap H;

int insert(int r, double x, double vel){
    x -= vel*curr_time;
    int b = x+vel*curr_time;
    Node<int>* a = regtree.Insert_reg(r,x,vel,regtree.get_root());
     if(a!=NULL)xvt.Insert_xvt(r,x,vel,xvt.get_root());
     else return 0;
     hp_int k;
     Node<int>* Psuccessor = xvt.return_upper_of_xvt(b,vel,r,xvt.get_root());
     Node<int>* Pprev = xvt.return_lower_of_xvt(b,vel,r,xvt.get_root());
     if(Psuccessor!=NULL){
             int i = Psuccessor->get_PosBack();
             if(i>=0)H.remove_hpnode(i);
     }
     if(Pprev!=NULL){
          int i = Pprev->get_PosFront();
          if(i>=0)H.remove_hpnode(i);
     }
    if(Psuccessor!=NULL){
         double x2 = Psuccessor->get_x();
         double x1 = x;
         double v1 = vel;
         double v2 = Psuccessor->get_vel();
         k.priority = (x2-x1)/(v2-v1);
         if(k.priority < 0)k.priority = -1*k.priority;
         k.Rback = a;
         k.Rfront = Psuccessor;
         int idx = H.insert_minhp(k);
         Psuccessor->set_PosFront(idx);
         a->set_PosBack(idx);
    }
    if(Pprev!=NULL){
        double x2 = x;double v2 = vel;
         double x1 = Pprev->get_x();double v1 = Pprev->get_vel();
         k.priority = (x2-x1)/(v2-v1);
         if(k.priority < 0)k.priority = -1*k.priority;
         k.Rback = Pprev;
         k.Rfront = a;
         int idx2 = H.insert_minhp(k);
         Pprev->set_PosBack(idx2);
         a->set_PosFront(idx2);


     }
}
int remove(int r){
    return 0;
}
int next_crossing(){
    int i = H.get_hp_ind();
    if(i==0){
            return 0;
    }
    hp_int topnode = H.get_headIdx(0);
    Node<int>* carback = topnode.Rback;
    Node<int>* carfront = topnode.Rfront;
    double time_left = topnode.priority;
    double x_of_collision = carback->get_x() + carback->get_vel()*time_left;
    cout<<x_of_collision<<" "<<min(carback->get_regist_num(), carfront->get_regist_num())<<" "<<max(carback->get_regist_num(), carfront->get_regist_num())<<endl;
    curr_time += time_left;
    H.del_min();
    while(H.get_headIdx(0).priority == time_left){
        hp_int topnode = H.get_headIdx(0);
        Node<int>* carback = topnode.Rback;
        Node<int>* carfront = topnode.Rfront;
        double x_of_collision = carback->get_x() + carback->get_vel()*time_left;
        cout<<x_of_collision<<" "<<min(carback->get_regist_num(), carfront->get_regist_num())<<" "<<max(carback->get_regist_num(), carfront->get_regist_num())<<endl;
        H.del_min();
    }
}
int main(){
    int m;
    cin>>m;
    while(m--){
        int f; 
        cin>>f;
        if(f==1){
            int r, double x, double v;
            cin>>r>>x>>v;
            insert(r,x,v);
        }
        else if(f==2){
            int r;
            cin>>r;
            remove(r);
        }
        else{
                next_crossing();        
        }
    }
}
