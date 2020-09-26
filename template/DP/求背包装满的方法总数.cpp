#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long ans[41];
int weight[21];
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i = 0;i<=40;i++)ans[i] = 0;
        ans[0] = 1;
        int w;
        for(int i = 1;i<=n;i++)
        {
            cin>>w;
            for(int v = 40;v>=w;v--)
            {
                ans[v] +=ans[v-w];
            }
        }
        cout<<ans[40]<<"\n";
    }
}
/*
题目描述
有一个神奇的口袋，总的容积是40，用这个口袋可以变出一些物品，这些物品的总体积必须是40。
John现在有n个想要得到的物品，每个物品的体积分别是a1，a2……an。John可以从这些物品中选择一些，
如果选出的物体的总体积是40，那么利用这个神奇的口袋，John就可以得到这些物品。
现在的问题是，John有多少种不同的选择物品的方式。

输入
3
20
20
20
输出

3

分析
实际就是求刚好装满背包时的方法总数
递推公式为：
f[i,v] = f[i-1,v] + f[i,v-Ci]分别表示选了和未选第i件的方法数，可以看到，跟单纯的背包最大的地推公式非常像
初始化为0
只有f[0]=1

*/
