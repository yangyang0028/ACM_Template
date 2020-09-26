#include <iostream>
#include <algorithm>
#include <cstring>
#include<cstdio>
#include <queue>
#define INF 0x3f3f3f
#define maxn 1005
using namespace std;
int n,t;
int mp[maxn][maxn];
int spfa(int b,int e)
{
    bool color[maxn];
    int d[maxn];
    memset(color,0,sizeof(color));
    memset(d,INF,sizeof(d));
    d[b]=0;
    queue<int>q;
    q.push(b);
    color[b]=1;
    while(!q.empty())
    {
        int st=q.front();
        q.pop();
        color[st]=0;
        for(int i=1;i<=n;i++)
        {
            if(d[st]+mp[st][i]<d[i])
            {
              d[i]=d[st]+mp[st][i];
                if(!color[i])
                {
                    q.push(i);
                    color[i]=1;
                }
            }
        }
    }
    return d[e];
}
int main(){
    while(~scanf("%d %d", &t, &n)){
    memset(mp,INF,sizeof(mp));
    int u,v,k;
    for(int i=0;i<t;i++){
    scanf("%d %d %d", &u, &v, &k);
      mp[u][v]=min(k,mp[u][v]);
      mp[v][u]=min(k,mp[v][u]);
    }
    printf("%d\n", spfa(1,n));
  }
  return 0;
}
