/*
回文串
HYSBZ - 3676
https://cn.vjudge.net/problem/HYSBZ-3676
题意：给你一个字符串 s，求回文子串长度 * 该回文串子出现次数的最大值。
解法：回文树+拓扑序
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 3e5+100;
struct node
{
    int len, cnt;//该回文串的长度，该回文串出现的次数
    int next[26];//只有26个小写字母
    int fail;//指向等于最长后缀回文的前缀点
}a[N];
int top, last;
char s[N];
void Init_Tr()//初始化很重要
{
    top = 1, last = 0;
    a[0].len = 0, a[1].len = -1;
    a[0].fail = 1;
}
int i;//减少传参可以优化很大的时间复杂度
int get_id(int now)
{
    while(s[i] != s[i-a[now].len-1]) now = a[now].fail;//判断是否满足回文
    return now;
}
void Insert()
{
    int len = strlen(s+1);
    for(i = 1; i <= len; i++) {
        int t = s[i]-'a';
        int id = get_id(last);
        if(!a[id].next[t]) {
            a[++top].len = a[id].len + 2;//每次前后各增加一个点
            a[top].fail = a[get_id(a[id].fail)].next[t];
            a[id].next[t] = top;
        }
        last = a[id].next[t];//
        a[last].cnt++;
    }
}
ll solve()
{
    ll ans = 0;
    for(int i = top; i >= 2; i--) {//从后往前遍历相当于拓扑序
        a[a[i].fail].cnt += a[i].cnt;
        ans = max(ans, 1LL*a[i].cnt*a[i].len);
    }
    return ans;
}
int main()
{
    scanf("%s", s+1);
    Init_Tr();
    Insert();
    printf("%lld\n", solve());
    return 0;
}
