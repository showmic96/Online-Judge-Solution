// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n , m , k;
int level1[505][505] , level2[505][505];
string ar[505] , br[505];

bool possible(int i , int j , int k)
{
    if(i<0||j<0||i>=n||j>=m)return false;
    if(k==1)if(ar[i][j]=='x')return false;
    if(k==2)if(br[i][j]=='x')return false;

    if(k==1)if(level1[i][j]==-1)return true;
    if(k==2)if(level2[i][j]==-1)return true;
    return false;
}

void bfs1()
{
    memset(level1 , -1 , sizeof(level1));
    queue<int>current;

    level1[0][0] = 1;

    current.push(0);
    current.push(0);

    while(!current.empty()){

        int i = current.front();current.pop();
        int j = current.front();current.pop();

        if(possible(i+1 , j , 1)==true){

            current.push(i+1);
            current.push(j);

            level1[i+1][j] = level1[i][j]+1;
        }

        if(possible(i-1 , j , 1)==true){

            current.push(i-1);
            current.push(j);

            level1[i-1][j] = level1[i][j]+1;
        }

        if(possible(i , j+1 , 1)==true){

            current.push(i);
            current.push(j+1);

            level1[i][j+1] = level1[i][j]+1;
        }

        if(possible(i , j-1 , 1)==true){

            current.push(i);
            current.push(j-1);

            level1[i][j-1] = level1[i][j]+1;
        }
    }
}

void bfs2()
{
    memset(level2 , -1 , sizeof(level2));
    queue<int>current;

    level2[0][0] = 1;

    current.push(0);
    current.push(0);

    while(!current.empty()){

        int i = current.front();current.pop();
        int j = current.front();current.pop();

        if(possible(i+1 , j , 2)==true){

            current.push(i+1);
            current.push(j);

            level2[i+1][j] = level2[i][j]+1;
        }

        if(possible(i-1 , j , 2)==true){

            current.push(i-1);
            current.push(j);

            level2[i-1][j] = level2[i][j]+1;
        }

        if(possible(i , j+1 , 2)==true){

            current.push(i);
            current.push(j+1);

            level2[i][j+1] = level2[i][j]+1;
        }

        if(possible(i , j-1 , 2)==true){

            current.push(i);
            current.push(j-1);

            level2[i][j-1] = level2[i][j]+1;
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    for(int i=0;i<n;i++){

        cin >> ar[i];
        br[i] = ar[i];
    }

    for(int i=0;i<k;i++){

        int in1 , in2;
        cin >> in1 >> in2;
        br[in1][in2] = '.';
    }

    bfs1();
    bfs2();

    if(level1[n-1][m-1]==-1&&level2[n-1][m-1]==-1)cout << "NO" << endl;
    else if(level1[n-1][m-1]==-1)cout << "YES" << endl;
    else if(level1[n-1][m-1]-5<=level2[n-1][m-1])cout << "NO" << endl;
    else cout << "YES" << endl;

    return 0;
}
