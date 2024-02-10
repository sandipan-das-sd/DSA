
#include<stdio.h>
#include<stdlib.h>
#define N 10
struct Stack
{
    /* data */
    int data;
    struct stack *next;
};
struct Stack* head=NULL;
int count=0;
void push(){
    if(N==count){
        printf("Stack overflow!\n");
    }
    else
    {
        struct Stack* new_node=(struct Stack*)malloc(sizeof(struct Stack));
        if(new_node==NULL){
            printf("Stack allocation failure!\n");
        }
        else
        {
            int value;
            printf("Enter the data to insert:-");
            scanf("%d",&value);
            new_node->data=value;
            // connect the new node to the head
            new_node->next=head;
            //update the pointer to the new node
            head=new_node;
            if(new_node=head){
                printf(" %d Value Inserted.",new_node->data);
            }
            count++;
        }
      
    }
}
  void pop(){
            if(head==NULL){
                printf("Stack Underflow");
            }
            else
            {
                struct Stack* temp;
                temp=head;
                head=head->next;
                free(temp);
                printf("The Popped value is :-%d",temp->data);
                count--;
            }
        }
void peek(){
    struct Stack* ptr;
    ptr=head;
    printf("The Peek value is :-%d",ptr->data);
}
void display(){
    struct Stack* st;
    st=head;
    if(st==NULL){
        printf(" Empty Stack\n");
    }
    else
    {
       while(st!=NULL){
        printf("%d ",st->data); 
        st=st->next;
    }
}
}

int main(){
int option;
while(option!=5){
    printf("\n***********Stack Menu Using Linked list**************\n");
    printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
    printf("Enter your choice :-");
    scanf("%d",&option);
    switch (option)
    {
    case 1:
        push();
        break;
    case 2:
        pop();
        break;
    case 3:
        peek();
        break;
    case 4:
        display();
        break;
    case 5:
        printf("Thank You!\n");
        exit(0);
    
    default:
        printf("Invalid option %d \n",option );
        break;
    }
}
return 0;

}
