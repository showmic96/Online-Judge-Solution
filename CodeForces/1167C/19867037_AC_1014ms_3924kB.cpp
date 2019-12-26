// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 5e5+9;
int par[MAX] , lvl[MAX];

int Find(int x)
{
    if(par[x]==x)return x;
    return par[x] = Find(par[x]);
}
void Union(int x , int y)
{
    int px = Find(x);
    int py = Find(y);
    if(px==py)return ;
    //if (lvl [px] < lvl [py]) swap (px, py);
    par[py] = px;
    lvl[px] += lvl[py];
}

int main(void)
{
    ios::sync_with_stdio();
    cin.tie(0);cout.tie(0);

    int n , m;
    cin >> n >> m;
    for(int i=0;i<=n;i++)par[i] = i , lvl[i] = 1;
    for(int i=0;i<m;i++){
        int k;
        cin >> k;
        if(k==0)continue;
        int now;
        cin >> now;
        for(int j=1;j<k;j++){
            int in;
            cin >> in;
            Union(now , in);
        }
    }
    for(int i=1;i<=n;i++){
        if(i>1)cout << " ";
        cout << lvl[Find(i)];
    }
    cout << endl;
    return 0;
}
