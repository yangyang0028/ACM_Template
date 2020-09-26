#include <bits/stdc++.h>
using namespace std;
struct node {
    int cnt;
    node* child[26];
};
node* root;
void init()
{
    root=new node();
}
void insert(const char s[])
{
    node* now=root;
    for(int i=0;s[i];i++){
        int go=s[i]-'a';
        if(now->child[go]==NULL)
            now->child[go]=new node();
        now=now->child[go];
        now->cnt++;
    }
}
int query(const char s[])
{
    node* now=root;
    for(int i=0;s[i];i++){
        int go=s[i]-'a';
        if(now->child[go]==NULL) return -1;
        now=now->child[go];
    }
    return now->cnt;
}
void del(const char s[])
{
    node* now=root;
    for(int i=0;s[i];i++){
        int go=s[i]-'a';
        if(now->child[go]->cnt==1){
            now->child[go]=NULL;
            return;
        }
        now=now->child[go];
        now->cnt--;
    }
}
int main()
{
    init();
    insert("abcdef");
    insert("abccba");
    cout << query("abc") << endl;
    cout << query("abcc") << endl;
    cout << query("abs") << endl;
    cout << query("abcdef") << endl;
    del("abcdef");
    cout << query("abcdef") << endl;
    cout<<query("abc")<<endl;
    return 0;
}
