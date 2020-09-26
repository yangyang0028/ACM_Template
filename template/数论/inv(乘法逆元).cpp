(a/b)%MOD=(a*inv(b,MOD))%MOD
-----------------------------------------------
#define ll long long
ll exgcd(ll a,ll b,ll &x,ll &y){
    if(a%b==0){
        x=0ll;y=1ll;
        return b;
    }
    ll v,tx,ty;
    v=exgcd(b,a%b,tx,ty);
    x=ty;
    y=tx-a/b*ty;
    return v;
}

ll inv(ll a,ll p){
    if(!a) return 0ll;
    ll x,y;
    exgcd(a,p,x,y);
    x=(x%p+p)%p;
    return x;
}
----------------------------------------------------------
ll quick_pow(ll a,ll b,ll mod){
    ll ans=1;
    while(b)
    {
        if(b&1) ans=(ans*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}
ll inv(ll x,ll mod){
    return quick_pow(x,mod-2,mod);
}
---------------------------------------------------------
