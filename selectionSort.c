#include<stdio.h>

void selectionsort(int v[],int n){
    int i,j,min_idx,temp;
    for(i=0;i<n-1;i++){
        min_idx=i;
        for(j=i+1;j<n;j++){
            if(v[j]<v[min_idx]){
                min_idx=j;
            }
        }
        if(i!=min_idx){
            temp=v[i];
            v[i]=v[min_idx];
            v[min_idx]=temp;
        }
    }
    return;
}
int main(){
    int arr[]={2,43,1,5,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionsort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}