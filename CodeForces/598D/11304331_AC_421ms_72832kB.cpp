// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e3 + 9;

string ar[MAX];

int n , m , k;

int parent[1000005];
int level[1000005];
bool visited[MAX][MAX];
int counter = 0;

void init()
{
    for(int i=0;i<1000005;i++){

        parent[i] = i;
        level[i] = 0;
    }
}

int get(int x , int y)
{
    return (x*m + y);
}

int Find(int x)
{
    if(x==parent[x])return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x , int y)
{
    int px = Find(x);
    int py = Find(y);

    //if(px==py)return ;

    //if(level[px]<level[py])swap(px , py);

    parent[py] = px;
    //level[px]+=level[py];
}

void dfs(int i , int j , int p)
{
    if(i>=n||j>=m)return ;
    if(i<0||j<0)return ;

    if(ar[i][j]=='*'){

        //if(parent[get(i,j)]==p)return ;
        //parent[get(i , j)] = p;
        level[Find(p)]++;
    }

    if(ar[i][j]!='.')return ;

    if(visited[i][j]==true)return ;
    visited[i][j]=true;

    Union(p , get(i , j));

    dfs(i+1 , j , p );
    dfs(i-1 , j , p );
    dfs(i , j+1 , p );
    dfs(i , j-1 , p );

}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    memset(visited , false , sizeof(visited));
    init();

    for(int i=0;i<n;i++)cin >> ar[i];

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            if(ar[i][j]=='.'&&visited[i][j]==false){

                dfs(i , j , get(i , j));
            }
        }
    }

    while(k--){

        int in1 , in2;
        cin >> in1 >> in2;

        cout << level[Find(get(in1-1 , in2-1))] << endl;
    }

    return 0;
}
