#include<iostream>
using namespace std;

struct treenode{
    treenode *lchild;
    int data;
    treenode *rchild;
}*root=0;

struct node{
    treenode *addres;
    node *next;
};

struct queue{
    node *front=0,*rear=0;

    void enqueue(treenode *x){
        node *t=new node;
        if(t==0)
            return;
        else{
            t->addres=x;
            t->next=0;
            if(front==0)
                front=rear=t;
            else{
                rear->next=t;
                rear=t;
            }
        }
    }

    treenode *dequeue(){
        treenode *x=NULL;
        node *t;
        if(front==0)
            return 0;
        else{
            x=front->addres;
            t=front;
            front=front->next;
            delete t;
        }
        return x;
    }

    bool isempty(){
        if(front==0)
            return true;
        return false;
    }
};

struct stack{
    node *top=0;

    void push(treenode *x){
        node *t=new node;
        if(t==0)
            return;
        else{
            t->addres=x;
            t->next=top;
            top=t;
        }
    }

    treenode *pop(){
        node *t;
        treenode *x=0;
        if(top==0)
            return x;
        else{
            t=top;
            top=top->next;
            x=t->addres;
            delete t;
        }
        return x;
    }

    bool isstackempty(){
        if(top==0)
            return true;
        return false;
    }

    treenode* stacktop(){
        if(top==0)
            return 0;
        return top->addres;
    }
};

treenode *search(treenode *p,int key){
    if(p==0)
        return 0;
    while(p){
        if(p->data==key)
            return p;
        else if(p->data < key)
            p=p->rchild;
        else
            p=p->lchild;
    }
    return 0;
}

void iter_insert(treenode *p,int n){
    treenode *t=new treenode;
    t->data=n;
    t->lchild=t->rchild=0;
    if(p==0){
        root=t;
        return;
    }
    treenode *q=0;
    while(p){
        q=p;
        if(p->data==n)
            return;
        else if(p->data > n)
            p=p->lchild;
        else
            p=p->rchild;
    }
    if(n > q->data)
        q->rchild=t;
    else
        q->lchild=t;
}

treenode* recur_insert(treenode *p,int n){
    if(p==0){
        treenode *t;
        t=new treenode;
        t->data=n;
        t->lchild=t->rchild=0;
        return t;
    }
    if(n < p->data)
        p->lchild=recur_insert(p->lchild,n);
    else if(n > p->data)
        p->rchild=recur_insert(p->rchild,n);
    return p;
}

void inorder(treenode *p){
    if(p){
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }
}

int height(treenode *p){
    int x,y;
    if(p){
        x=height(p->lchild);
        y=height(p->rchild);
        if(x>y)
            return x+1;
        else
            return y+1;
    }
    return 0;
}

treenode *in_pred(treenode *p){
    if(p==0 || p->lchild==0)
        return 0;
    p=p->lchild;
    while(p->rchild)
        p=p->rchild;
    return p;
}

treenode *in_succ(treenode *p){
    if(p==0 || p->rchild==0)
        return 0;
    p=p->rchild;
    while(p->lchild)
        p=p->lchild;
    return p;
}

treenode *deletenode(treenode *p,int n){
    if(p==0)
        return 0;
    if(p->lchild==0 && p->rchild==0){
        if(p==root)
            root=0;
        delete p;
        return 0;
    }
    if(n < p->data)
        p->lchild=deletenode(p->lchild,n);
    else if(n > p->data)
        p->rchild=deletenode(p->rchild,n);
    else if(n==p->data){
        if(height(p->lchild)>= height(p->rchild)){
            int temp=in_pred(p)->data;
            p->data=temp;
            p->lchild=deletenode(p->lchild,temp);
        }
        else{
            int temp=in_succ(p)->data;
            p->data=temp;
            p->rchild=deletenode(p->rchild,temp);
        }
    }
    return p;
}

int main(){
    int arr[]={35,20,60,10,25,40,70,21,32,28,33,30,29,31};
    for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++)
        iter_insert(root,arr[i]);
    inorder(root);
    cout<<endl;
    deletenode(root,25);
    inorder(root);
}