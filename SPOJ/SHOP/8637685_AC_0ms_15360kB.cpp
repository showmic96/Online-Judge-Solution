// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 27;

int n , m;
char ar[MAX][MAX];
int level[MAX][MAX];
int ans;

void dfs(int i , int j , int value)
{
//cout << i << " " << j << " " << value << endl;
    if(i<0||j<0)return ;
    if(i>=n||j>=m)return ;
    if(ar[i][j]=='X')return;
    if(ar[i][j]=='S')return;
    int temp = ar[i][j] - '0';

    //return ;
    if(level[i][j]<=temp+value)return;
    //cout << i << " " << j << " " << value << " " << temp << " " << ar[i][j] << endl;

    if(ar[i][j]=='D'){ans = min(ans,value);return;}

    level[i][j] = temp+value;

    dfs(i , j+1 , value+temp);
    dfs(i , j-1 , value+temp);
    dfs(i+1 , j , value+temp);
    dfs(i-1 , j , value+temp);
}

void setUp()
{
    for(int i=0;i<MAX;i++)
        for(int j=0;j<MAX;j++){level[i][j] = 12345;ar[i][j]='X';}
}

int main(void)
{

    while(cin >> m >> n){

        if(!m&&!n)break;

        ans = 1234567;

        setUp();

        for(int i=0;i<n;i++)cin >> ar[i];

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                if(ar[i][j]=='S'){

                    dfs(i , j-1 , 0);
                    dfs(i , j+1 , 0);
                    dfs(i+1 , j , 0);
                    dfs(i-1 , j , 0);
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
