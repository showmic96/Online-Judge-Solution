// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1505;

int n , m;
string ar[MAX+9];
bool vis[MAX+9][MAX+9] , ok = false;
pair<int , int> where[MAX+9][MAX+9];

void dfs(int ux , int uy)
{
    if(ok==true)return ;
    if(ar[(ux%n+n)%n][(uy%m+m)%m]=='#')return ;
    if(vis[(ux%n+n)%n][(uy%m+m)%m]==true){

        if(where[(ux%n+n)%n][(uy%m+m)%m].first==ux&&where[(ux%n+n)%n][(uy%m+m)%m].second==uy)return ;
        ok = true;
        return ;
    }
    vis[(ux%n+n)%n][(uy%m+m)%m] = true;
    where[(ux%n+n)%n][(uy%m+m)%m].first = ux;
    where[(ux%n+n)%n][(uy%m+m)%m].second = uy;

    for(int i=0;i<4;i++){

        int vx = ux;
        int vy = uy;

        if(i==0)vx++;
        if(i==1)vx--;
        if(i==2)vy++;
        if(i==3)vy--;

        dfs(vx , vy);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;

    for(int i=0;i<n;i++)cin >> ar[i];
    memset(vis , false , sizeof(vis));

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            if(ar[i][j]=='S')dfs(i , j);
        }
    }

    if(ok==false)cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}
