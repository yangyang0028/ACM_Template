#include <stdio.h>
#include <stdlib.h>
struct Queue{
  int x;
  Queue *next;
}*head,*temp,*end;
void Queue_build(){
  head=(Queue*)malloc(sizeof (Queue));
  end=head;
}
void Queue_push(int n){
  temp=(Queue*)malloc(sizeof (Queue));
  temp->x=n;
  temp->next=NULL;
  end->next=temp;
  end=temp;
}
int Queue_top(){
  temp=head->next;
  return temp->x;
}
void Queue_pop(){
  if(head!=end){
    temp=head;
    head=head->next;
    free(temp);
  }
}
void Queue_clear(){
  while(head!=end){
    temp=head;
    head=head->next;
    free(temp);
  }
}
int main(){
  Queue_build();
  Queue_push(1);
  Queue_push(2);
  Queue_push(3);
  Queue_push(4);
  printf("%d\n", Queue_top());
  Queue_pop();
  printf("%d\n", Queue_top());
  Queue_clear();
  Queue_push(5);
  printf("%d\n", Queue_top());
}
