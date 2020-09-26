#include <bits/stdc++.h>
using namespace std;
struct data{
   int  num;
   struct data  *next;
 };
struct data  *creat( ){//创建链表
  int x;
  struct data *h,*p,*q;
  h=NULL;
  while(~scanf("%d", &x),x){
    p=(struct data *) malloc( sizeof(struct data) );
    p->num=x;  p->next=NULL;
    if(h==NULL) h=p,q=p;
    else q->next=p,q=p;
  }
  return h;
}
void printlist(struct data   *h){
  struct data *p;
     p=h;
  while(p){
    printf("%d-->",p->num);
    p=p->next;
  }
}
struct data *mergelist(struct data *LA,struct data *LB){//合并链表
	struct data *p,*q,*a,*h;
  struct data *A,*B;
  A=LA;
  B=LB;
	h=NULL;
  while(A){
		a=(struct data *) malloc( sizeof(struct data) );
		a->num = A->num;  a->next=NULL;
		if(h==NULL){
      h=a;
    }else if(h->num >= A->num){
	    a->next=h; h=a;
	  }else{
			p=h;
      while(p && p->num <= A->num) q=p,p=p->next;
      if(p==NULL)  q->next=a;
      else q->next=a,a->next=p;
    }
		A=A->next;
  }
  while(B){
		a=(struct data *) malloc( sizeof(struct data) );
		a->num = B->num;  a->next=NULL;
		if(h==NULL){
      h=a;
    }else if(h->num >= B->num){
	    a->next=h; h=a;
	  }else{
			p=h;
      while(p&&p->num <= B->num) q=p,p=p->next;
      if(p==NULL)  q->next=a;
      else q->next=a,a->next=p;
    }
		B=B->next;
  }
  return h;
}
int main(){
  struct data *head_LA;
  struct data *head_LB;
  struct data *head;
  head_LA=creat();
  head_LB=creat();
  head=mergelist(head_LA,head_LB);
  printlist(head);
}
