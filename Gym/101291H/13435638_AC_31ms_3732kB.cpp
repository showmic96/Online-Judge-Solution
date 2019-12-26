// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string ar[55];
int n , m;
bool vis[55][55];

void dfs(int i , int j)
{
    if(i<0||j<0||i>=n||j>=m)return ;
    if(vis[i][j])return ;
    vis[i][j] = true;

    if(ar[i][j]=='W')return ;

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

    memset(vis , false , sizeof(vis));

    cin >> n >> m;

    for(int i=0;i<n;i++)cin >> ar[i];

    int counter = 0;

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            if(ar[i][j]=='L'&&vis[i][j]==false){

                counter++;
                dfs(i , j);
            }
        }
    }

    cout << counter << endl;

    return 0;
}
