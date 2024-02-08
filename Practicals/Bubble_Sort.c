// #include<stdio.h>
// #include<stdlib.h>
// #include<math.h>
// #include<stdbool.h>
// void swap(int *a,int *b){
//     int temp;
//     temp=*a;
//     *a=*b;
//     *b=temp;
    
// }
// void Bubble_Sort(int arr[],int n){
// int i,j;
// bool flag;
// for(i=0;i<n-1;i++){
//     flag=false;
//     for(j=0;j<n-i-1;j++){
//         if (arr[j]>arr[j+1]){
//             swap(&arr[j],&arr[j+1]);
//             flag=true;
//         }
//     }
//     if(swap==false){
//         break;
//     }
// }
// }
// void PrintArray(int arr[],int n){
//     int i;
//     for(i=0;i<n;i++){
//         printf("%d ",arr[i]);
//     }
// }
// int main(){
//     int arr[]={5,4,3,2,1};
//     int n=sizeof(arr)/sizeof(n);
//     Bubble_Sort(arr,n);
//     PrintArray(arr,n);
// }
// Bubble sort in C

#include <stdio.h>

// perform the bubble sort
void bubbleSort(int array[], int size) {

  // loop to access each array element
  for (int step = 1; step <= size ; ++step) {
      
    // loop to compare array elements
    for (int i = 0; i < size - step - 1; ++i) {
      
      // compare two adjacent elements
      // change > to < to sort in descending order
      if (array[i] > array[i + 1]) {
        
        // swapping occurs if elements
        // are not in the intended order
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}

// print array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
  int data[] = {-2, 45, 0, 11, -9};
  
  // find the array's length
  int size = sizeof(data) / sizeof(data[0]);

  bubbleSort(data, size);
  
  printf("Sorted Array in Ascending Order:\n");
  printArray(data, size);
}