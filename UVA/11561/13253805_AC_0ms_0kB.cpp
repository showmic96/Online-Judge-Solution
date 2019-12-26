// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int n , m , counter;
string ar[55];
bool vis[55][55];

void dfs(int i , int j)
{
    if(vis[i][j])return ;
    vis[i][j] = true;
    if(ar[i][j]=='#')return ;

    if(ar[i][j]=='G')counter++;

    if(ar[i+1][j]=='T'||ar[i-1][j]=='T'||ar[i][j+1]=='T'||ar[i][j-1]=='T')return ;

    dfs(i+1 , j);
    dfs(i-1 , j);
    dfs(i , j+1);
    dfs(i , j-1);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin >> m >> n){

        for(int i=0;i<n;i++)cin >> ar[i];

        counter = 0;
        memset(vis , false , sizeof(vis));

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                if(ar[i][j]=='P')dfs(i , j);
            }
        }

        cout << counter << endl;
    }

    return 0;
}
