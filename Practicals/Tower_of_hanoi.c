#include <stdio.h>
void towers(int,char,char,char);
int main(){
    int num;
    printf("Enter the nmber of disks:");
    scanf("%d",&num);
    printf("The sequence moves involved in the Tower of hanoi are:\n");
    towers(num,'A','C','B');
    return 0;
}
void towers(int num,char source,char destination,char aux){
    if(num==1){
        printf("\nMoves disks 1 from %c to ring %c",source,destination);
        return ;
    }
    else{
        towers(num-1,source,aux,destination);
        printf("\nMoves disks %d from %c to ring %c",num,source,destination);
        towers(num-1,aux,destination,source);
        


    }

}