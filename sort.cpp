#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define ll long long
#define loop(k,n) for(int i=k;i<n;i++)

void merge(int arr[],int low,int mid,int high){
    int n1=mid-low+1;
    int n2=high-mid;
    int left[n1],right[n2];
    loop(0,n1){
        left[i]=arr[low+i];
    }
    loop(0,n2){
        right[i]=arr[mid+1+i];
    }

    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            arr[k+low]=left[i];
            k++;
            i++;
        }
        else{
            arr[k+low]=right[j];
            k++;
            j++;
        }
    }
    while(i<n1){
        arr[k+low]=left[i];
        k++;
        i++;
    }
    while(j<n2){
        arr[k+low]=right[j];
        k++;
        j++;
    }
}

void mergesort(int arr[],int l,int r){
    if(r>l){
        int m=(r+l)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main(){
    int arr[]={7,10,15,8,12};
    mergesort(arr,0,(sizeof(arr)/sizeof(arr[0]))-1);
    loop(0,sizeof(arr)/sizeof(arr[0]))
        cout<<arr[i]<<" ";
}