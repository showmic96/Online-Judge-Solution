// In the name of Allah the most Merciful.

#include<bits/stdc++.h>
using namespace std;

char ar[110][110];

int counter , n , m;

void dfs(int i , int j)
{
    //cout << n << " " << m << endl;
    //if(ar[i][j]=='@')return;
    if(ar[i][j]=='#')return;
    if(i>=m||j>=n)return;
    //cout << "YES" << endl;
    if(i<0||j<0)return;
    //cout << "YES";
    ar[i][j] = '#';

    counter++;

    dfs(i+1 ,j);
    dfs(i-1 ,j);
    dfs(i ,j+1);
    dfs(i ,j-1);
}

int main(void)
{
    int t , x1 , y1 , x2 , y2 ;
    cin >> t;

    for(int i=0;i<t;i++){
        n = m = 0;
        cin >> n >> m;
        //cout << n  << " " << m << endl;
        for(int i=0;i<m;i++)cin >> ar[i];
        counter = 0;
        for(int i=0;i<m;i++){

            for(int j=0;j<n;j++){

                if(ar[i][j]=='@'){dfs(i , j);}
            }
        }

        printf("Case %d: ", i+1);

        cout << counter << endl;

    }

    return 0;
}
