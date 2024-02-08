#include<stdio.h>

void reverse(int v[],int start,int end){
    while(start<end){
        int temp=v[start];
        v[start]=v[end];
        v[end]=temp;
        start++;
        end--;
    }
}

void rotate(int v[],int n,int k){
    k=k%n;

    reverse(v,0,n-1);
    reverse(v,0,k);
    reverse(v,k,n-1);
}

void display(int v[],int n){
    for(int i=0;i<n;i++){
        printf("%d",v[i]);
    }
}
int main(){
    int d[]={3,7,4,2};
    int n=4;
    rotate(d,n,2);
    display(d,n);
}