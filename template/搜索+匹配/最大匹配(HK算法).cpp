#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
 using namespace std;
 const int maxn=3030;// 最大点数
 const int INF=0x3f3f3f3f;// 距离初始值
 int bmap[maxn][maxn];//二分图
 int cx[maxn];//cx[i]表示左集合i顶点所匹配的右集合的顶点序号
 int cy[maxn]; //cy[i]表示右集合i顶点所匹配的左集合的顶点序号
 int nx,ny;
 int dx[maxn];
 int dy[maxn];
 int dis;
 bool bmask[maxn];
 //寻找 增广路径集
 bool searchpath(){
    queue<int>Q;
    dis=INF;
    memset(dx,-1,sizeof(dx));
    memset(dy,-1,sizeof(dy));
    for(int i=1;i<=nx;i++){
       //cx[i]表示左集合i顶点所匹配的右集合的顶点序号
       if(cx[i]==-1)
       {
          //将未遍历的节点 入队 并初始化次节点距离为0
          Q.push(i);
          dx[i]=0;
       }
    }
    //广度搜索增广路径
    while(!Q.empty())
    {
       int u=Q.front();
       Q.pop();
       if(dx[u]>dis) break;
       //取右侧节点
       for(int v=1;v<=ny;v++)
       {
          //右侧节点的增广路径的距离
          if(bmap[u][v]&&dy[v]==-1)
          {
             dy[v]=dx[u]+1; //v对应的距离 为u对应距离加1
             if(cy[v]==-1) dis=dy[v];     //如果该点未被匹配，那么增广路形成
             else                         //如果该点匹配了，那么接着往下搜
             {
                dx[cy[v]]=dy[v]+1;
                Q.push(cy[v]);
             }
          }
       }
    }
    return dis!=INF;
 }
 //寻找路径 深度搜索
 int findpath(int u)
 {
    for(int v=1;v<=ny;v++)
    {
       //如果该点没有被遍历过 并且距离为上一节点+1
       if(!bmask[v]&&bmap[u][v]&&dy[v]==dx[u]+1)
       {
          //对该点染色
          bmask[v]=1;
          if(cy[v]!=-1&&dy[v]==dis)   //如果该点已经被匹配了并且为最后一个匹配点，那么这条路径不是增广路。即是说这条路的结点已经匹配
          {
             continue;
          }
          if(cy[v]==-1||findpath(cy[v]))  //如果该点未匹配或者后面的点能腾出位置，那么这就是增广路
          {
             cy[v]=u;cx[u]=v;
             return 1;
          }
       }
    }
    return 0;
 }
 //得到最大匹配的数目
 int MaxMatch()
 {
    int res=0;
    memset(cx,-1,sizeof(cx));//cx[i]表示左集合i顶点所匹配的右集合的顶点序号
    memset(cy,-1,sizeof(cy));
    while(searchpath())    //如果存在增广路
    {
       memset(bmask,0,sizeof(bmask));
       for(int i=1;i<=nx;i++)
       {
          if(cx[i]==-1)
          {
             res+=findpath(i);
          }
       }
    }
    return res;
 }
 struct node{
 	 int x,y,s;
 	 void input1(){
 		 scanf("%d %d %d", &x, &y, &s);
 	 }
 	 void input2(){
 		 scanf("%d %d", &x, &y);
 	 }
 }p1[maxn],p2[maxn];
 int diss(node a,node b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
 int main(){
    int T,t;
    int iCase=0;
    scanf("%d", &T);
    while(T--){
       memset(bmap,0,sizeof(bmap));
       scanf("%d %d", &t, &nx);
       for(int i=1;i<=nx;i++){
   			p1[i].input1();
   		}
   		scanf("%d", &ny);
   		for(int i=1;i<=ny;i++){
   			p2[i].input2();
   		}
      for(int i=1;i<=nx;i++){
        for(int j=1;j<=ny;j++){
          if(diss(p1[i],p2[j])<=p1[i].s*t*p1[i].s*t)
            bmap[i][j]=1;
        }
      }
      printf("Scenario #%d:\n",++iCase);
      printf("%d\n\n",MaxMatch());
    }
    return 0;
 }
