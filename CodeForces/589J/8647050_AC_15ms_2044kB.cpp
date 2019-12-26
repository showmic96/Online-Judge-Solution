#include<bits/stdc++.h>
using namespace std;

const int MAX = 15;

char ar[MAX][MAX];
bool isVisited[MAX][MAX];
char direction[MAX][MAX];

int counter = 0;
int lim = 1e5;
int n , m;

bool isPossible(int i , int j , char x)
{
    if(i<0||j<0)return false;
    if(i>=n||j>=m)return false;
    if(ar[i][j]=='*')return false;
    if(isVisited[i][j]==true){

        //if(direction[i][j]==x)return false;
    }

    return true;
}
void dfs(int i , int j , char c)
{

    if(isVisited[i][j]==false)counter++;
    else{

        if(direction[i][j]==c)return;
    }
    direction[i][j] = c;
    isVisited[i][j] = true;
    //cout << i << " " << j << " " << c << endl;

    if(c=='U'){

        if(isPossible(i-1 , j , 'U')==true)dfs(i-1 , j , 'U');
        else if(isPossible(i , j+1 , 'R')==true)dfs(i , j+1 , 'R');
        else if(isPossible(i+1 , j , 'D')==true)dfs(i+1 , j , 'D');
        else if(isPossible(i , j-1 , 'L')==true)dfs(i , j-1 , 'L');
    }

    if(c=='D'){

        if(isPossible(i+1 , j , 'D')==true)dfs(i+1 , j , 'D');
        else if(isPossible(i , j-1 , 'L')==true)dfs(i , j-1 , 'L');
        else if(isPossible(i-1 , j , 'U')==true)dfs(i-1 , j , 'U');
        else if(isPossible(i , j+1 , 'R')==true)dfs(i , j+1 , 'R');
    }

    if(c=='L'){

        if(isPossible(i , j-1 , 'L')==true)dfs(i , j-1 , 'L');
        else if(isPossible(i-1 , j , 'U')==true)dfs(i-1 , j , 'U');
        else if(isPossible(i , j+1 , 'R')==true)dfs(i , j+1 , 'R');
        else if(isPossible(i+1 , j , 'D')==true)dfs(i+1 , j , 'D');
    }

    if(c=='R'){

        if(isPossible(i , j+1 , 'R')==true)dfs(i , j+1 , 'R');
        else if(isPossible(i+1 , j , 'D')==true)dfs(i+1 , j , 'D');
        else if(isPossible(i , j-1 , 'L')==true)dfs(i , j-1 , 'L');
        else if(isPossible(i-1 , j , 'U')==true)dfs(i-1 , j , 'U');
    }
}

int main(void)
{
    memset(isVisited , false, sizeof(isVisited));


    cin >> n >> m;

    for(int i=0;i<n;i++)cin >> ar[i];

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            if(ar[i][j]=='U'||ar[i][j]=='D'||ar[i][j]=='L'||ar[i][j]=='R'){

                dfs(i, j , ar[i][j]);
            }
        }
    }

    cout << counter << endl;

    return 0;
}
