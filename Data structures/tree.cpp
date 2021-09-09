#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define loop(k, n) for (ll i = k; i < n; i++)

struct treenode{
    treenode *lchild;
    int data;
    treenode *rchild;
}*root=0;

struct node{
    treenode *addres;
    node *next;
}*front=0,*rear=0;

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
        cout<<"Queue is empty";
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

void treecreate(){
    treenode *p=0,*t=0;
    int x;
    cout<<"enter root value - ";
    cin>>x;
    cout<<endl;
    root=new treenode;
    root->data=x;
    root->lchild=root->rchild=0;
    enqueue(root);
    while(!isempty()){
        p=dequeue();
        cout<<"enter left child of "<<p->data<<" - ";
        cin>>x;
        cout<<endl;
        if(x!=-1){
            t=new treenode;
            t->data=x;
            t->lchild=t->rchild=0;
            p->lchild=t;
            enqueue(t);
        }
        cout<<"enter right child of "<<p->data<<" - ";
        cin>>x;
        cout<<endl;
        if(x!=-1){
            t=new treenode;
            t->data=x;
            t->lchild=t->rchild=0;
            p->rchild=t;
            enqueue(t);
        }
    }
}

void preorder(treenode *p){
    if(p){
        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void inorder(treenode *p){
    if(p){
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }
}
void postorder(treenode *p){
    if(p){
        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data<<" ";
    }
}

void iter_preorder(treenode *t){
    while(t!=0 || isstackempty()==false){
        if(t!=0){
            cout<<t->data<<" ";
            push(t);
            t=t->lchild;
        }
        else{
            t=pop();
            t=t->rchild;
        }
    }
    cout<<endl;
}
void iter_inorder(treenode *t){
    while(t!=0 || isstackempty()==false){
        if(t!=0){
            push(t);
            t=t->lchild;
        }
        else{
            t=pop();
            cout<<t->data<<" ";
            t=t->rchild;
        }
    }
    cout<<endl;
}

void iter_postorder(treenode *p){
    treenode *curr=p;
    while(curr!=0 || !isstackempty()){
        if(curr!=0){
            push(curr);
            curr=curr->lchild;
        }
        else{
            treenode *temp=stacktop()->rchild;
            if(temp==0){
                temp=pop();
                cout<<temp->data<<" ";
                while(!isstackempty() && temp==stacktop()->rchild){
                    temp=pop();
                    cout<<temp->data<<" ";
                }
            }
            else
                curr=temp;
        }
    }
    cout<<endl;
}

void levelorder(treenode *t){
    if(t){
        cout<<t->data<<" ";
        enqueue(t);
        while(!isempty()){
            t=dequeue();
            if(t->lchild){
                cout<<t->lchild->data<<" ";
                enqueue(t->lchild);
            }
            if(t->rchild){
                cout<<t->rchild->data<<" ";
                enqueue(t->rchild);
            }
        }
    }
    cout<<endl;
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

int count_nodes(treenode *p){
    int x,y;
    if(p){
        x=count_nodes(p->lchild);
        y=count_nodes(p->rchild);
        return x+y+1;
    }
    return 0;
}

int search_inorder(int inorder[],int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(inorder[i]==curr)
            return i;
    }
    return -1;
}

treenode *buildtree_pre_in(int preorder[],int inorder[],int start,int end){
    if(start > end)
        return 0;
    static int index=0;
    int curr=preorder[index];
    index++;
    treenode *p=new treenode;
    p->data=curr;
    p->rchild=p->lchild=0;
    int pos=search_inorder(inorder,start,end,curr);
    p->lchild=buildtree_pre_in(preorder,inorder,start,pos-1);
    p->rchild=buildtree_pre_in(preorder,inorder,pos+1,end);
    return p;
}
treenode *buildtree_post_in(int postorder[],int inorder[],int start,int end){
    if(start > end)
        return 0;
    static int index=end;
    int curr=postorder[index];
    index--;
    treenode *p=new treenode;
    p->data=curr;
    p->rchild=p->lchild=0;
    int pos=search_inorder(inorder,start,end,curr);
    p->rchild=buildtree_post_in(postorder,inorder,pos+1,end);
    p->lchild=buildtree_post_in(postorder,inorder,start,pos-1);
    return p;
}

int main(){
    treecreate();
    cout<<endl;
    preorder(root);cout<<endl;
    inorder(root);cout<<endl;
    postorder(root);cout<<endl;
}

// 1 2 3 4 5 6 7 -1 -1 8 -1 -1 9 10 11 -1 -1 -1 -1 -1 -1 -1 -1
//level - 1 2 3 4 5 6 7 8 9 10 11
// post - 4,8,5,2,9,6,10,11,7,3,1
// pre  - 1,2,4,5,8,3,6,9,7,10,11
// in   - 4,2,8,5,1,6,9,3,10,7,11