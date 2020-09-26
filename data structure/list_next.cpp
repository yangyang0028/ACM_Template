#include <stdio.h>
#include <stdlib.h>
struct List{
  int x;
  List* next;
};
List *head,*temp,*end;
void creat(int n){
  head=(List*)malloc(sizeof (List));
  end=head;
  while(n--){
    temp=(List*)malloc(sizeof (List));
    scanf("%d", &temp->x);
    end->next=temp;
    end=temp;
  }
  end->next=NULL;
}
void print(List *head){
  temp=head->next;
  while(temp){
    printf("%d-->", temp->x);
    temp=temp->next;
  }
  printf("\n");
}
void rm(int n){
  List *_temp=head;
  temp=head->next;
  while(temp){
    if(temp->x==n){
      _temp->next=temp->next;
      temp=temp->next;
    }else{
      _temp=temp;
      temp=temp->next;
    }
  }
  return ;
}
void push(int n){
  List *_temp=head;
  temp=head->next;
  List *new_=(List*)malloc(sizeof (List));
  new_->x=n;
  bool bo=true;
  while(temp){
    if(temp->x>n){
      _temp->next=new_;
      new_->next=temp;
      bo=false;
      break;
    }else{
      _temp=temp;
      temp=temp->next;
    }
  }
  if(bo){
    end->next=new_;
    end=new_;
    end->next=NULL;
  }
}
int main(){
  creat(10);
  print(head);
  push(11);
  print(head);
  rm(5);
  print(head);
  return 0;
}
