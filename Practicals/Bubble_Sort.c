#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
    
}
void Bubble_Sort(int arr[],int n){
int i,j;
bool flag;
for(i=0;i<n-1;i++){
    flag=false;
    for(j=0;j<n-i-1;j++){
        if (arr[j]>arr[j+1]){
            swap(&arr[j],&arr[j+1]);
            flag=true;
        }
    }
    if(swap==false){
        break;
    }
}
}
void PrintArray(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
int main(){
    int arr[]={5,4,3,2,1};
    int n=sizeof(arr)/sizeof(n);
    Bubble_Sort(arr,n);
    PrintArray(arr,n);
}