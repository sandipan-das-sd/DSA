#include <stdio.h>
#define n 20
int i,j,temp;
// this is the bubble sort for Decesding to ascending
void bubble_dec_asc_sort(int arr[], int size) {
// first for loop denotes steps if size=5 then steps will be up to 3
//second for loop dentes for each elements compare if n is 5 then the lops will be up to 3
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
//this is the bubble sort for ascending to desecding
void bubble_asc_dec_sort(int arr[], int size) {
// first for loop denotes steps if size=5 then steps will be up to 3
//second for loop dentes for each elements compare if n is 5 then the lops will be up to 3
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(){
    int arr[n],size,i;
    printf("Enter the  number of element to the array:-\n");
    scanf("%d",&size);
   
    for(i=0;i<size;i++){
        printf("Enter the %d th index element of the array:-",i);
        scanf("%d",&arr[i]);
    }
    printf("The array before sorting :-\n");
     for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    bubble_dec_asc_sort(arr,size);
    printf("\nThe array after sorting {Decesnding to Ascending} :-\n");
     for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    bubble_asc_dec_sort(arr,size);
    printf("\nThe array after sorting {Ascending to decending} :-\n");
     for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }

}
