#include <stdio.h>
#include <stdlib.h>
struct Stack{
  int x;
  Stack *next;
}*head,*temp;
void stack_build(){
  head=(Stack*)malloc(sizeof (Stack));
  head->next=NULL;
}
void stack_push(int n){
  temp=(Stack*)malloc(sizeof (Stack));
  temp->x=n;
  temp->next=head;
  head=temp;
}
int stack_top(){
  return head->x;
}
void stack_pop(){
  temp=head;
  if(head->next!=NULL){
    head=head->next;
    free(temp);
  }
}
void stack_clear(){
  temp=head;
  while(head->next!=NULL){
    head=head->next;
    free(temp);
  }
}
int main(){
  stack_build();
  stack_push(5);
  printf("%d\n", stack_top());
  stack_push(6);
  printf("%d\n", stack_top());
  stack_push(7);
  printf("%d\n", stack_top());
  stack_pop();
  printf("%d\n", stack_top());
  stack_clear();
  printf("%d\n", stack_top());
  return 0;
}
