// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int par[26];
char ar[1000005];

int Find(int x)
{
    if(par[x]==x)return x;
    return par[x] = Find(par[x]);
}

void Union(int x , int y)
{
    int px = Find(x);
    int py = Find(y);

    par[py] = px;
}

int main(void)
{
    int n;
    scanf("%d",&n);

    for(int i=0;i<26;i++)par[i] = i;

    scanf("%s",&ar);
    string s1(ar);

    scanf("%s",&ar);
    string s2(ar);

    vector<pair<char , char> > ans;

    for(int i=0;i<26;i++)par[i] = i;

    for(int i=0;i<n;i++){

        int x = s1[i]-'a';
        int y = s2[i]-'a';

        if(Find(x)==Find(y))continue;

        Union(x , y);

        ans.push_back(make_pair(x+'a' , y+'a'));
    }

    int si = ans.size();

    printf("%d\n",si);

    for(int i=0;i<si;i++){

        printf("%c %c\n",ans[i].first ,ans[i].second);
    }

    return 0;
}
