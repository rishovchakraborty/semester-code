#include<stdio.h>
#include<stdlib.h>

int binarySearch( int arr[],int left, int right,int target){
 while(left<=right){
        int mid= left + (right-left)/2;
    if(target==arr[mid]){
        return mid;
    }
    else if(target>arr[mid]){
        left=mid+1;
    }else right=mid-1;
}
 
 return -1;
}

int main(){
    int arr[]={1,4,7,33,78,101};
    int target=7;
    int size= sizeof(arr)/sizeof(arr[0]);
    int result= binarySearch(arr,0,size,target);
    if(result==-1) printf("ele isnt present");
    else printf("ele is there at index = %d",result);
}