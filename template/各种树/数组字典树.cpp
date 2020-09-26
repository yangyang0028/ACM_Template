#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
struct node {
    int cnt;
    int child[26];
} trie[maxn * 30];
int tot, root;
int newnode() 
{
    tot++;
    trie[tot].cnt = 0;
    for(int i = 0; i < 26; i++) trie[tot].child[i] = -1;
    return tot;
}
void init()
{
    tot = -1;
    root = newnode();
}
void insert(const char s[])
{
    int now = root;
    for(int i = 0; s[i]; i++) {
        int go = s[i] - 'a';
        if(trie[now].child[go] == -1) trie[now].child[go] = newnode();
        now = trie[now].child[go];
        trie[now].cnt++;
    }
}
void del(const char s[])
{
    int now = root;
    for(int i = 0; s[i]; i++) {
        int go = s[i] - 'a';
        if(trie[trie[now].child[go]].cnt == 1) {
            trie[now].child[go] = -1;
            return;
        }
        now = trie[now].child[go];
        trie[now].cnt--;
    }
}
int query(const char s[])
{
    int now = root;
    for(int i = 0; s[i]; i++) {
        int go = s[i] - 'a';
        if(trie[now].child[go] == -1) return -1;
        now = trie[now].child[go];
    }
    return trie[now].cnt;
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
