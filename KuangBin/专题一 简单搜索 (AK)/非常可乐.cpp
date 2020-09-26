#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int ans=0;
int a1,b1,c1;
int a,b,c;
int bfs(){
    while(a1!=c1){
        ans++;
        if(c1==0){
            c1=c;
            a1-=c;
        }else if(b1!=b){
            if(c1>(b-b1)){
            c1-=(b-b1);
            b1=b;
        }else{
            b1+=c1;
            c1=0;
        }
        }else if(b1==b){
            a1+=b1;
            b1=0;
        }
    }
    return ans;
}
int main()
{
    while(cin>>a>>b>>c&&(a&&b&&c))
    {
        ans=0;
        int g=gcd(b,c);
        a/=g;
        if(a&1)
            cout<<"NO"<<endl;
        else{
            int ma,mi;
            ma=max(b,c);
            mi=min(b,c);
            b=mi,c=ma;
            b/=g;
            c/=g;
            a1=a;
            c1=0;
            b1=0;
            bfs();
            printf("%d\n", ans);
        }
    }
    return 0;
}
