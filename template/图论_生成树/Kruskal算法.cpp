#include<bits/stdc++.h>
using namespace std;
const int L=1e5+7;
const int inf=0x3f3f3f3f;
const int maxn=1000+7;
int father[maxn],n,m,num[maxn],nPos;//父节点（并查集），点数，边数，最小生成树点集 当前访问方位
struct node{
    int s,y,w;//左端点，右端点，权值
}edge[L];
void init(){//初始化并查集
    for(int i=0;i<=n;i++)
        father[i]=i;
}
int root(int x){//并查集，构造父节点
    return father[x]==x?x:father[x]=root(father[x]);
}
void unite(int x,int y){//并查集，合并两个联通图
    x=root(x);
    y=root(y);
    if(x!=y)
        father[y]=x;
}
int alike(int x,int y){	//并查集，判断是否为同一连通图
    return root(x)==root(y);
}
int cmp(node a,node b){
    return a.w<b.w;
}
int kruskal(){//最小生成树
    init();
    sort(edge,edge+m,cmp);  		//对边进行权值排序
    int sum=0,cnt=0;
    for(int i=0;i<m;i++)    		//每次选择最小且未访问过的一条边
    {
        if(cnt==n-1)
            break;
        if(!alike(edge[i].s,edge[i].y)){
            unite(edge[i].s,edge[i].y);
            cout<<edge[i].s<<"  "<<edge[i].y<<endl;
            sum+=edge[i].w;
            cnt++;
            num[++nPos]=i;
        }
    }
    return cnt!=n-1?-1:sum;	       //判断边是否大于等于n-1，否则输出-1
}
void read(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
        scanf("%d %d %d",&edge[i].s,&edge[i].y,&edge[i].w);
}
void solve(){
    nPos=0;
    int mst=kruskal();
}
int main(){
    read();
    solve();
    return 0;
}
