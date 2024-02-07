#include<stdio.h>

void insertionsort(int v[],int n){
    for(int i=1;i<n;i++){
        int curr=v[i];
        int j=i-1;
        while(j>=0 && v[j]>curr){
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=curr;
    }
    return;
}
int main(){
    int arr[]={2,43,1,5,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionsort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}