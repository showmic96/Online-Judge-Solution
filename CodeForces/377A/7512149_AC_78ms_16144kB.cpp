// In the name of Allah the Lord of the worlds .

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 510;

bool isVisited[MAX+7][MAX+7];
char ar[MAX+7][MAX+7];

int counter , total , n , m;

void setUp(int a)
{
    for(int i=0;i<=a;i++){

        for(int j=0;j<=a;j++){

            isVisited[i][j]=false;
        }
    }
}

int yes;

void dfs(int i , int j)
{
    if(i<0||j<0)return;
    if(i>=m||j>=n)return;

    if(isVisited[i][j]==true)return;
    if(ar[i][j]=='#')return;

    if(counter==yes)ar[i][j]='X';
    else counter++;

    isVisited[i][j]=true;
    dfs(i , j+1);
    dfs(i , j-1);
    dfs(i+1 , j);
    dfs(i-1 , j);
}

int main(void)
{
    int t ;
    cin >> m >> n >> t;
    int c = 0;
    counter = 0;

    for(int i=0;i<m;i++){
        cin >> ar[i];

        int si = strlen(ar[i]);

        for(int j=0;j<si;j++){

            if(ar[i][j]=='.')c++;
        }
    }
    //cout  << c << endl;
    yes = c - t;
    bool check = false;

    for(int i=0;i<m;i++){

        for(int j=0;j<n;j++){

            if(ar[i][j]=='.'){dfs(i , j);check = true;break;}
        }

        if(check==true)break;
    }

    for(int i=0;i<m;i++)cout << ar[i] << endl;

    return 0;
}
