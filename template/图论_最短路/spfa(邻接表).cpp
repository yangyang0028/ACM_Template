#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
#include<queue>
#include<math.h>
#include<vector>
#include<iostream>
#define INF 0x3f3f3f3f
#define ll long long
#define N 100000+10
using namespace std;
int n,m;
int x,y,z;
struct node
{
    int y,z;
};
vector<node> mp[1000];
int spfa(int b,int e)
{
    bool color[1000];
    int d[1000];
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
        for(int i=0;i<mp[st].size();i++)
        {
            if(d[st]+mp[st][i].z<d[mp[st][i].y])
            {
                d[mp[st][i].y]=d[st]+mp[st][i].z;
                if(!color[mp[st][i].y])
                {
                    q.push(mp[st][i].y);
                    color[mp[st][i].y]=1;
                }
            }
        }
    }
    return d[e];
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
       mp[x].push_back((node){y,z});
    }
    cout<<spfa(1,n)<<endl;
}
