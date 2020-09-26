#include <bits/stdc++.h>
using namespace std;
#define maxa 10000
#define maxn 100
int num=0;
struct node{
  char id[maxn];//ѧ��
  char name[maxn];//����
	char gender[maxn];//�Ա�
	char Birth_date[maxn];//��������
	int Chinese_language;//���ĳɼ�
	int mathematics;//��ѧ�ɼ�
	int English;//Ӣ��ɼ�
	int science;//��ѧ�ɼ�
	int sports;//�����ɼ�
	int bo;//�ж��Ƿ�ɾ��
}f[maxa];

bool cmp(node a,node b){
  return strcmp(a.id, b.id) < 0;
}

void solve_printf(){
  sort(f,f+num,cmp);
	printf("**********ѧ����Ϣ���**********\n");
	for(int i=0;i<num;i++){
		if(f[i].bo){
			printf("ѧ��%s	����%s 	�Ա�%s	 ��������%s \n", f[i].id, f[i].name, f[i].gender, f[i].Birth_date);
			printf("����%4d ��ѧ%4d Ӣ��%4d ��ѧ%4d ����%4d\n\n", f[i].Chinese_language, f[i].mathematics, f[i].English, f[i].science, f[i].sports);
		}
	}
	printf("ѧ����Ϣ������...\n");
}

void solve_printf_1(int m){
  printf("%d  ", m);
  printf("ѧ��%s ����%s �Ա�%s ��������%s \n", f[m].id, f[m].name, f[m].gender, f[m].Birth_date);
  printf("����%d ��ѧ%d Ӣ��%d ��ѧ%d ����%d\n", f[m].Chinese_language, f[m].mathematics, f[m].English, f[m].science, f[m].sports);
}
void solve_scanf_1(){
  int n;
  printf("������ѧ����������\n");
	scanf("%d", &n);
  printf("�밴�� ѧ��  ����   �Ա�  ��������  ����  ��ѧ  Ӣ��  ��ѧ  ���� \n");
	printf("��˳������ÿ��ѧ������Ϣ��\n");
  while(n--){
		scanf("%s %s %s %s", f[num].id, f[num].name, f[num].gender, f[num].Birth_date);
		scanf("%d %d %d %d %d", &f[num].Chinese_language, &f[num].mathematics, &f[num].English, &f[num].science, &f[num].sports);
		f[num].bo=1;//�������ѧ��û�б�ɾ��
		num++;
	}
  return ;
}

void solve_scanf_2(){
  int n;
  char name_txt[maxn];
  scanf("%s", name_txt);
  FILE *f1;
  f1=fopen(name_txt,"r+");
  fscanf(f1,"%d", &n);
  while(n--){
    fscanf(f1,"%s %s %s %s", f[num].id, f[num].name, f[num].gender, f[num].Birth_date);
    fscanf(f1,"%d %d %d %d %d", &f[num].Chinese_language, &f[num].mathematics, &f[num].English, &f[num].science, &f[num].sports);
    f[num].bo=1;
    num++;
  }
  fclose(f1);
  printf("��Ϣ��ȡ���!!!\n");
	return ;
}

void amend(int m){
  int n;
  char amend_c[maxn];
  int amend_i;
  printf("����ѡ�\n");
  printf("-------------------------------------------------\n");
  printf(" 1---�޸�ѧ��\n");
  printf(" 2---�޸�����\n");
  printf(" 3---�޸��Ա�\n");
  printf(" 4---�޸ĳ�������\n");
  printf(" 5---�޸����ĳɼ�\n");
  printf(" 6---�޸���ѧ�ɼ�\n");
  printf(" 7---�޸�Ӣ��ɼ�\n");
  printf(" 8---�޸Ŀ�ѧ�ɼ�\n");
  printf(" 9---�޸������ɼ�\n");
  printf("--------------------------------------------------\n");
  scanf("%d", &n);
  if(n==1){
    printf("�������޸ĺ��ѧ�ţ�");
    scanf("%s", amend_c);
    strcpy(f[m].id,amend_c);
  }else if(n==2){
    printf("�������޸ĺ��������");
    scanf("%s", amend_c);
    strcpy(f[m].name,amend_c);
  }else if(n==3){
    printf("�������޸ĺ���Ա�");
    scanf("%s", amend_c);
    strcpy(f[m].gender,amend_c);
  }else if(n==4){
    printf("�������޸ĺ�ĳ������£�");
    scanf("%s", amend_c);
    strcpy(f[m].Birth_date,amend_c);
  }else if(n==5){
    printf("�������޸ĺ�����ĳɼ���");
    scanf("%d", &amend_i);
    f[m].Chinese_language=amend_i;
  }else if(n==6){
    printf("�������޸ĺ����ѧ�ɼ���");
    scanf("%d", &amend_i);
    f[m].mathematics=amend_i;
  }else if(n==7){
    printf("�������޸ĺ��Ӣ��ɼ���");
    scanf("%d", &amend_i);
    f[m].English=amend_i;
  }else if(n==8){
    printf("�������޸ĺ�Ŀ�ѧ�ɼ���");
    scanf("%d", &amend_i);
    f[m].science=amend_i;
  }else if(n==9){
    printf("�������޸ĺ�������ɼ���");
    scanf("%d", &amend_i);
    f[m].sports=amend_i;
  }
  printf("�޸����\n");
  return ;
}

void delete_id(){
  char fine_id[maxn];
  int m=-1;
  printf("��ѡ���˰���ѧ�Ų��ң������......\n");
  printf("������ѧ����ѧ�ţ�\n");
  scanf("%s", fine_id);
  for(int i=0;i<num;i++){
    if(f[i].bo&&strcmp(f[i].id,fine_id)==0){
      m=i;
      break;
    }
  }
  if(m==-1){
    printf("δ�ҵ�ѧ����Ϣ\n");
    return ;
  }else{
    printf("�ҵ��ˣ�������Ϣ���£�\n");
    solve_printf_1(m);
    f[m].bo=false;
  }
  printf("����������\n");
  return ;
}

void delete_name(){
  char name[maxn];
	int m=-1;
	printf("��ѡ���˰����������ң������......\n");
	printf("������ѧ����������\n");
	scanf("%s", name);
	for(int i=0;i<num;i++){
		if(f[i].bo&&strcmp(f[i].name,name)==0){
			m=i;
			break;
		}
	}
	if(m==-1){
		printf("δ�ҵ�ѧ����Ϣ\n");
		return ;
	}else{
		printf("�ҵ��ˣ�������Ϣ���£�\n");
	  solve_printf_1(m);
    f[m].bo=false;
	}
	printf("����������\n");
	return ;
}

void find_id(){
  char fine_id[maxn];
  int m=-1;
  printf("��ѡ���˰���ѧ�Ų��ң������......\n");
  printf("������ѧ����ѧ�ţ�\n");
  scanf("%s", fine_id);
  for(int i=0;i<num;i++){
    if(f[i].bo&&strcmp(f[i].id,fine_id)==0){
      m=i;
      break;
    }
  }
  if(m==-1){
    printf("δ�ҵ�ѧ����Ϣ\n");
    return ;
  }else{
    printf("�ҵ��ˣ�������Ϣ���£�\n");
    solve_printf_1(m);
  }
  printf("����������\n");
  return ;
}

void find_name(){
  char name[maxn];
	int m=-1;
	printf("��ѡ���˰����������ң������......\n");
	printf("������ѧ����������\n");
	scanf("%s", name);
	for(int i=0;i<num;i++){
		if(f[i].bo&&strcmp(f[i].name,name)==0){
			m=i;
			break;
		}
	}
	if(m==-1){
		printf("δ�ҵ�ѧ����Ϣ\n");
		return ;
	}else{
		printf("�ҵ��ˣ�������Ϣ���£�\n");
	    solve_printf_1(m);
	}
	printf("����������\n");
	return ;
}

void solve_1(){
  int n;
	printf("**********ѧ����Ϣ�Ĵ���**********\n");
	printf("˵��������ʼ����ʱ��ѧ����ϢΪ��ʱ����ʱ��Ҫ����ѧ����Ϣ\n");
	printf("����ѡ�\n");
	printf("-------------------------------------------------\n");
	printf(" 1---�Ӽ�������������Ϣ\n");
	printf(" 2---���ļ���ȡ������Ϣ\n");
	printf("--------------------------------------------------\n");
	printf("������ѡ�1--2����\n");
	scanf("%d", &n);
	if(n==1){
    printf("\n��ѡ���˴Ӽ����������ݣ������......\n");
    solve_scanf_1();
  }else if(n==2){
    printf("\n��ѡ���˴��ļ��������ݣ������......\n");
    solve_scanf_2();
  }else printf("�������,�������˵�\n");
	return ;
}

void solve_2(){
  int n;
	printf("**********ѧ����Ϣ����**********\n");
	printf("����ѡ�\n");
	printf("-------------------------------------------------\n");
	printf(" 1---�Ӽ�������������Ϣ\n");
	printf(" 2---���ļ���ȡ������Ϣ\n");
	printf("--------------------------------------------------\n");
	printf("������ѡ�1--2����\n");
	scanf("%d", &n);
	if(n==1){
    printf("\n��ѡ���˴Ӽ����������ݣ������......\n");
    solve_scanf_1();
  }else if(n==2){
    printf("\n��ѡ���˴��ļ��������ݣ������......\n");
    solve_scanf_2();
  }
	else printf("�������,�������˵�\n");
	return ;
}

void solve_3(){//ѧ����Ϣ���
	solve_printf();
	return ;
}

void solve_4(){//�޸�ѧ����Ϣ����
	int n;
  char amend_c[maxn];
	int m=-1;
	printf("**********ѧ����Ϣ�޸�**********\n");
	printf("������Ҫ�޸ĵ�ѧ��ѧ��\n");
	scanf("%s", amend_c);
	for(int i=0;i<num;i++){
		if(f[i].bo&&strcmp(f[i].id,amend_c)==0){//�жϸ�ѧ���Ƿ�ɾ�������ж�ID�Ƿ����
			m=i;
			break;
		}
	}
	if(m==-1){
		printf("δ�ҵ�Ҫ�޸�ѧ����Ϣ���������˵�\n");
		return ;
	}
	printf("�ҵ�Ҫ�޸�ѧ����Ϣ,����\n");
	solve_printf_1(m);
  amend(m);
  return ;
}

void solve_5(){
  int n;
	printf(" **********ѧ����Ϣ�Ĳ���**********\n");
	printf("����ѡ� \n");
	printf("----------------------------------\n");
	printf("     1---����ѧ�Ų���\n");
	printf("     2---������������\n");
	printf("----------------------------------\n");
	printf("������ѡ�1--2����\n");
	scanf("%d", &n);
	if(n==1) find_id();
  else if(n==2) find_name();
	else printf("�������,�������˵�\n");
	return ;
}

void solve_6(){//ɾ��ѧ����Ϣ����
	int n;
	printf(" **********ɾ��ѧ����Ϣ**********\n");
	printf("����ѡ� \n");
	printf("----------------------------------\n");
	printf("     1---����ѧ�Ų���\n");
	printf("     2---������������\n");
	printf("----------------------------------\n");
	printf("������ѡ�1--2����\n");
	scanf("%d", &n);
	if(n==1) delete_id();
	else if(n==2) delete_name();
	else printf("�������,�������˵�\n");
	return ;
}

void solve_0(){
  char name_txt[maxn];
  scanf("%s", name_txt);
  FILE *f2;
	f2=fopen(name_txt,"w+");
  fprintf(f2,"%d\n", num);
  while(num--){
    if(f[num].bo){
      fprintf(f2,"%s %s %s %s ", f[num].id, f[num].name, f[num].gender, f[num].Birth_date);
      fprintf(f2,"%d %d %d %d %d ", f[num].Chinese_language, f[num].mathematics, f[num].English, f[num].science, f[num].sports);
    }
  }
  fclose(f2);
  return ;
}

int main(){
  int n;  
  while(1) {
    printf("========================================\n");
		printf("           ѧ����Ϣ����ϵͳ\n");
		printf("========================================\n");
		printf("����ѡ�\n");
		printf("   0---������Ϣ���˳�\n");
		printf("   1---����ѧ����Ϣ   2---����ѧ����Ϣ\n");
		printf("   3---���ѧ����Ϣ   4---�޸�ѧ����Ϣ\n");
		printf("   5---����ѧ����Ϣ   6---ɾ��ѧ����Ϣ\n");
		printf("========================================\n");
		printf("������ѡ�0--7��: \n");
		scanf("%d", &n);
    if(n==0){
      solve_0();
    }else if(n==1){
			solve_1();
			printf("\n\n\n");
		}else if(n==2){
			solve_2();
			printf("\n\n\n");
		}else if(n==3){
			solve_3();
			printf("\n\n\n");
		}else if(n==4){
			solve_4();
			printf("\n\n\n");
		}else if(n==5){
			solve_5();
			printf("\n\n\n");
		}else if(n==6){
			solve_6();
			printf("\n\n\n");
		}else printf("�������\n����������ѡ��\n");
  }
  return 0;
}

