#include<stdio.h>
int i,j,temp,key,min_idx;
void bubble_sort(int arr[],int n){
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
//void insertion_sort(int arr[],int n){
//	for(i=1;i<n;i++){
//		key=arr[i];
//		j=i-1;
//		while(j>=0 && arr[j]>key){
//			arr[j+1]=arr[j];
//			j--;
//		}
//		arr[j+1]=key;
//	}
//}
//void selection_sort(int arr[],int n){
//	for(i=0;i<n-1;i++){
//		min_idx=i;
//		for(j=i+1;j<n;j++){
//			if(arr[j]<arr[min_idx]){
//				min_idx=j;
//			}
//			
//		}
//	}
//	
//	temp=min_idx;
//	arr[min_idx]=arr[j];
//	arr[j]=temp;
//}
int main(){
	int arr[]={5,47,3,9};
	int n=sizeof(arr)/(arr[0]);
	bubble_sort(arr,n);
//	insertion_sort(arr,n);
//	selection_sort(arr,n);
	printf("Sorted array: ");
    for ( i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

	return 0;
	
}
