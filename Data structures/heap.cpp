#include<iostream>
using namespace std;

void insert_in_heap(int arr[],int n){
    int temp=arr[n];
    while(n>1){
        if(arr[n/2] < temp){
            arr[n]=arr[n/2];
            n=n/2;
        }
        else
            break;
    }
    arr[n]=temp;
}

void delete_from_heap(int arr[],int n){
    int temp=arr[1];
    arr[1]=arr[n];
    arr[n]=temp;
    int i=1;
    int j=2*i;
    while(j<n){
        if(j<n-1){
            if(arr[j]<arr[j+1])
                j=j+1;
        }
        if(arr[j]>arr[i]){
            swap(arr[i],arr[j]);
            i=j;
            j=2*i;
        }
        else
            break;
    }
}

int main(){
    int arr[]={0,20,15,30,18};
    for(int i=2;i<(sizeof(arr)/sizeof(arr[0]));i++)
        insert_in_heap(arr,i);
    for(int i=1;i<(sizeof(arr)/sizeof(arr[0]));i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    for(int i=(sizeof(arr)/sizeof(arr[0]))-1;i>0;i--){
        delete_from_heap(arr,i);
    }
    for(int i=1;i<(sizeof(arr)/sizeof(arr[0]));i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

#include<iostream>
using namespace std;

void min_heapify(int arr[],int i,int n){
    int l=2*i;
    int r=l+1;
    int res;
    if(l<=n && arr[l]<arr[i])
        res=l;
    else
        res=i;
    if(r<=n && arr[r]<arr[res])
        res=r;
    if(res!=i){
        swap(arr[i],arr[res]);
        min_heapify(arr,res,n);
    }
}

void max_heapify(int arr[],int i,int n){
    int l=2*i;
    int r=l+1;
    int res;
    if(l<=n && arr[l]>arr[i])
        res=l;
    else
        res=i;
    if(r<=n && arr[r]>arr[res])
        res=r;
    if(res!=i){
        swap(arr[i],arr[res]);
        max_heapify(arr,res,n);
    }
}

int main(){
    int n;
    cin>>n;
    int *arr=new int[n+1];
    for(int i=1;i<n+1;i++)
        cin>>arr[i];
    for(int i=n;i>=1;i--){
        min_heapify(arr,i,n);
    }
    for(int i=1;i<=n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    for(int i=n;i>=1;i--){
        max_heapify(arr,i,n);
    }
    for(int i=1;i<=n;i++)
        cout<<arr[i]<<" ";
}