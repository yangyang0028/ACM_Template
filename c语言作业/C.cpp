#include <bits/stdc++.h>
using namespace std;
#define maxa 10000
#define maxn 100
int num=0;
struct node{
  char id[maxn];//学号
  char name[maxn];//姓名
	char gender[maxn];//性别
	char Birth_date[maxn];//出生日期
	int Chinese_language;//语文成绩
	int mathematics;//数学成绩
	int English;//英语成绩
	int science;//科学成绩
	int sports;//体育成绩
	int bo;//判断是否被删除
}f[maxa];

bool cmp(node a,node b){
  return strcmp(a.id, b.id) < 0;
}

void solve_printf(){
  sort(f,f+num,cmp);
	printf("**********学生信息浏览**********\n");
	for(int i=0;i<num;i++){
		if(f[i].bo){
			printf("学号%s	姓名%s 	性别%s	 出生年月%s \n", f[i].id, f[i].name, f[i].gender, f[i].Birth_date);
			printf("语文%4d 数学%4d 英语%4d 科学%4d 体育%4d\n\n", f[i].Chinese_language, f[i].mathematics, f[i].English, f[i].science, f[i].sports);
		}
	}
	printf("学生信息浏览完毕...\n");
}

void solve_printf_1(int m){
  printf("%d  ", m);
  printf("学号%s 姓名%s 性别%s 出生年月%s \n", f[m].id, f[m].name, f[m].gender, f[m].Birth_date);
  printf("语文%d 数学%d 英语%d 科学%d 体育%d\n", f[m].Chinese_language, f[m].mathematics, f[m].English, f[m].science, f[m].sports);
}
void solve_scanf_1(){
  int n;
  printf("请输入学生的人数：\n");
	scanf("%d", &n);
  printf("请按照 学号  姓名   性别  出生日期  语文  数学  英语  科学  体育 \n");
	printf("的顺序输入每个学生的信息：\n");
  while(n--){
		scanf("%s %s %s %s", f[num].id, f[num].name, f[num].gender, f[num].Birth_date);
		scanf("%d %d %d %d %d", &f[num].Chinese_language, &f[num].mathematics, &f[num].English, &f[num].science, &f[num].sports);
		f[num].bo=1;//标记这名学生没有被删除
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
  printf("信息读取完成!!!\n");
	return ;
}

void amend(int m){
  int n;
  char amend_c[maxn];
  int amend_i;
  printf("功能选项：\n");
  printf("-------------------------------------------------\n");
  printf(" 1---修改学号\n");
  printf(" 2---修改姓名\n");
  printf(" 3---修改性别\n");
  printf(" 4---修改出生年月\n");
  printf(" 5---修改语文成绩\n");
  printf(" 6---修改数学成绩\n");
  printf(" 7---修改英语成绩\n");
  printf(" 8---修改科学成绩\n");
  printf(" 9---修改体育成绩\n");
  printf("--------------------------------------------------\n");
  scanf("%d", &n);
  if(n==1){
    printf("请输入修改后的学号：");
    scanf("%s", amend_c);
    strcpy(f[m].id,amend_c);
  }else if(n==2){
    printf("请输入修改后的姓名：");
    scanf("%s", amend_c);
    strcpy(f[m].name,amend_c);
  }else if(n==3){
    printf("请输入修改后的性别：");
    scanf("%s", amend_c);
    strcpy(f[m].gender,amend_c);
  }else if(n==4){
    printf("请输入修改后的出生年月：");
    scanf("%s", amend_c);
    strcpy(f[m].Birth_date,amend_c);
  }else if(n==5){
    printf("请输入修改后的语文成绩：");
    scanf("%d", &amend_i);
    f[m].Chinese_language=amend_i;
  }else if(n==6){
    printf("请输入修改后的数学成绩：");
    scanf("%d", &amend_i);
    f[m].mathematics=amend_i;
  }else if(n==7){
    printf("请输入修改后的英语成绩：");
    scanf("%d", &amend_i);
    f[m].English=amend_i;
  }else if(n==8){
    printf("请输入修改后的科学成绩：");
    scanf("%d", &amend_i);
    f[m].science=amend_i;
  }else if(n==9){
    printf("请输入修改后的体育成绩：");
    scanf("%d", &amend_i);
    f[m].sports=amend_i;
  }
  printf("修改完毕\n");
  return ;
}

void delete_id(){
  char fine_id[maxn];
  int m=-1;
  printf("你选择了按照学号查找，请继续......\n");
  printf("请输入学生的学号：\n");
  scanf("%s", fine_id);
  for(int i=0;i<num;i++){
    if(f[i].bo&&strcmp(f[i].id,fine_id)==0){
      m=i;
      break;
    }
  }
  if(m==-1){
    printf("未找到学生信息\n");
    return ;
  }else{
    printf("找到了，具体信息如下：\n");
    solve_printf_1(m);
    f[m].bo=false;
  }
  printf("返回主界面\n");
  return ;
}

void delete_name(){
  char name[maxn];
	int m=-1;
	printf("你选择了按照姓名查找，请继续......\n");
	printf("请输入学生的姓名：\n");
	scanf("%s", name);
	for(int i=0;i<num;i++){
		if(f[i].bo&&strcmp(f[i].name,name)==0){
			m=i;
			break;
		}
	}
	if(m==-1){
		printf("未找到学生信息\n");
		return ;
	}else{
		printf("找到了，具体信息如下：\n");
	  solve_printf_1(m);
    f[m].bo=false;
	}
	printf("返回主界面\n");
	return ;
}

void find_id(){
  char fine_id[maxn];
  int m=-1;
  printf("你选择了按照学号查找，请继续......\n");
  printf("请输入学生的学号：\n");
  scanf("%s", fine_id);
  for(int i=0;i<num;i++){
    if(f[i].bo&&strcmp(f[i].id,fine_id)==0){
      m=i;
      break;
    }
  }
  if(m==-1){
    printf("未找到学生信息\n");
    return ;
  }else{
    printf("找到了，具体信息如下：\n");
    solve_printf_1(m);
  }
  printf("返回主界面\n");
  return ;
}

void find_name(){
  char name[maxn];
	int m=-1;
	printf("你选择了按照姓名查找，请继续......\n");
	printf("请输入学生的姓名：\n");
	scanf("%s", name);
	for(int i=0;i<num;i++){
		if(f[i].bo&&strcmp(f[i].name,name)==0){
			m=i;
			break;
		}
	}
	if(m==-1){
		printf("未找到学生信息\n");
		return ;
	}else{
		printf("找到了，具体信息如下：\n");
	    solve_printf_1(m);
	}
	printf("返回主界面\n");
	return ;
}

void solve_1(){
  int n;
	printf("**********学生信息的创建**********\n");
	printf("说明：程序开始运行时，学生信息为空时，这时需要创建学生信息\n");
	printf("功能选项：\n");
	printf("-------------------------------------------------\n");
	printf(" 1---从键盘输入数据信息\n");
	printf(" 2---从文件读取数据信息\n");
	printf("--------------------------------------------------\n");
	printf("请输入选项（1--2）：\n");
	scanf("%d", &n);
	if(n==1){
    printf("\n你选择了从键盘输入数据，请继续......\n");
    solve_scanf_1();
  }else if(n==2){
    printf("\n你选择了从文件输入数据，请继续......\n");
    solve_scanf_2();
  }else printf("输入错误,返回主菜单\n");
	return ;
}

void solve_2(){
  int n;
	printf("**********学生信息增添**********\n");
	printf("功能选项：\n");
	printf("-------------------------------------------------\n");
	printf(" 1---从键盘输入数据信息\n");
	printf(" 2---从文件读取数据信息\n");
	printf("--------------------------------------------------\n");
	printf("请输入选项（1--2）：\n");
	scanf("%d", &n);
	if(n==1){
    printf("\n你选择了从键盘输入数据，请继续......\n");
    solve_scanf_1();
  }else if(n==2){
    printf("\n你选择了从文件输入数据，请继续......\n");
    solve_scanf_2();
  }
	else printf("输入错误,返回主菜单\n");
	return ;
}

void solve_3(){//学生信息浏览
	solve_printf();
	return ;
}

void solve_4(){//修改学生信息界面
	int n;
  char amend_c[maxn];
	int m=-1;
	printf("**********学生信息修改**********\n");
	printf("请输入要修改的学生学号\n");
	scanf("%s", amend_c);
	for(int i=0;i<num;i++){
		if(f[i].bo&&strcmp(f[i].id,amend_c)==0){//判断该学生是否被删除并且判断ID是否相等
			m=i;
			break;
		}
	}
	if(m==-1){
		printf("未找到要修改学生信息，返回主菜单\n");
		return ;
	}
	printf("找到要修改学生信息,如下\n");
	solve_printf_1(m);
  amend(m);
  return ;
}

void solve_5(){
  int n;
	printf(" **********学生信息的查找**********\n");
	printf("功能选项： \n");
	printf("----------------------------------\n");
	printf("     1---按照学号查找\n");
	printf("     2---按照姓名查找\n");
	printf("----------------------------------\n");
	printf("请输入选项（1--2）：\n");
	scanf("%d", &n);
	if(n==1) find_id();
  else if(n==2) find_name();
	else printf("输入错误,返回主菜单\n");
	return ;
}

void solve_6(){//删除学生信息界面
	int n;
	printf(" **********删除学生信息**********\n");
	printf("功能选项： \n");
	printf("----------------------------------\n");
	printf("     1---按照学号查找\n");
	printf("     2---按照姓名查找\n");
	printf("----------------------------------\n");
	printf("请输入选项（1--2）：\n");
	scanf("%d", &n);
	if(n==1) delete_id();
	else if(n==2) delete_name();
	else printf("输入错误,返回主菜单\n");
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
		printf("           学生信息管理系统\n");
		printf("========================================\n");
		printf("功能选项：\n");
		printf("   0---保存信息并退出\n");
		printf("   1---创建学生信息   2---增加学生信息\n");
		printf("   3---浏览学生信息   4---修改学生信息\n");
		printf("   5---查找学生信息   6---删除学生信息\n");
		printf("========================================\n");
		printf("请输入选项（0--7）: \n");
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
		}else printf("输入错误\n请重新输入选项\n");
  }
  return 0;
}

