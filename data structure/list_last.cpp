#include <stdio.h>
#include <stdlib.h>
struct Stack{
  int x;
  Stack *last;
}*head,*temp;
void creat(int n){
  head=(Stack*)malloc(sizeof (Stack));
  head=NULL;
  while(n--){
    temp=(Stack*)malloc(sizeof (Stack));
    scanf("%d", &temp->x);
    temp->last=head;
    head=temp;
  }
}
void print(Stack *head){
  temp=head;
  while(temp){
    printf("%d-->", temp->x);
    temp=temp->last;
  }
  printf("\n");
}
int main(){
  creat(5);
  print(head);
  return 0;
}
