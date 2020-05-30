// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string ar[111];
int n , m;
int level[111][111];

bool possible(int i , int j)
{
    if(i<0||j<0)return false;
    if(i>=n||j>=m)return false;
    if(ar[i][j]=='#')return false;
    if(level[i][j]!=0)return false;
    return true;
}

void bfs()
{
    memset(level , 0 , sizeof(level));
    level[0][0] = 1;

    queue<int>current;
    current.push(0);
    current.push(0);

    while(!current.empty()){

        int i = current.front();
        current.pop();
        int j = current.front();
        current.pop();

        if(possible(i+1 , j)){

            level[i+1][j] = level[i][j]+1;
            current.push(i+1);
            current.push(j);
        }

        if(possible(i-1 , j)){

            level[i-1][j] = level[i][j]+1;
            current.push(i-1);
            current.push(j);
        }

        if(possible(i , j+1)){

            level[i][j+1] = level[i][j]+1;
            current.push(i);
            current.push(j+1);
        }

        if(possible(i , j-1)){

            level[i][j-1] = level[i][j]+1;
            current.push(i);
            current.push(j-1);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i=0;i<n;i++){

        cin >> ar[i];
    }

    int counter = 0;

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            if(ar[i][j]=='#')counter++;
        }
    }

    bfs();

    if(level[n-1][m-1]==0)cout << -1 << endl;
    else cout << n*m-counter-level[n-1][m-1] << endl;

    return 0;
}
