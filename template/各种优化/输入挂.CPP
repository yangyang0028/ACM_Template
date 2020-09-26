inline int read()//快读
{
    int x=0,f=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c)){x=x*10+c-48;c=getchar();}
    return x*f;
}

inline void put(int x)//快输
{
     if(x<0) putchar('-'),x=-x;
     if(x>9) put(x/10);
     putchar(x%10+'0');
}
