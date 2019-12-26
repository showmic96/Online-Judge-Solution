// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n , m;
string ar[505];
int level[505][505];

bool possible(int i , int j)
{
    if(i<0||j<0||i>=n||j>=m)return false;
    if(level[i][j])return false;
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

        int i = current.front();current.pop();
        int j = current.front();current.pop();

        int lim = ar[i][j] - '0';

        for(int i1=lim;i1<=lim;i1++){

            if(possible(i , j+i1)==true){

                current.push(i);
                current.push(j+i1);
                level[i][j+i1] = level[i][j]+1;
            }

            if(possible(i , j-i1)==true){

                current.push(i);
                current.push(j-i1);
                level[i][j-i1] = level[i][j]+1;
            }

            if(possible(i+i1 , j)==true){

                current.push(i+i1);
                current.push(j);
                level[i+i1][j] = level[i][j]+1;
            }

            if(possible(i-i1 , j)==true){

                current.push(i-i1);
                current.push(j);
                level[i-i1][j] = level[i][j]+1;
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i=0;i<n;i++)cin >> ar[i];

    bfs();

    int ans = level[n-1][m-1];

    printf("%d\n",ans-1);

    return 0;
}
