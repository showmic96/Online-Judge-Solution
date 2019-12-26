// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1234;

int n , m;
char ar[MAX][MAX];
int level[MAX][MAX];

bool possible(int i , int j)
{
    if(i>=n||j>=m||i<0||j<0)return false;
    return true;
}

void bfs()
{
    deque<int>current;
    current.push_back(0);
    current.push_back(0);

    level[0][0] = 0;

    while(!current.empty()){

        int u = current.front();
        current.pop_front();
        int v = current.front();
        current.pop_front();

        if(possible(u+1 , v)==true&&level[u+1][v]>level[u][v]&&ar[u][v]==ar[u+1][v]){

            current.push_front(v);
            current.push_front(u+1);

            level[u+1][v] = level[u][v];
        }

        if(possible(u-1 , v)==true&&level[u-1][v]>level[u][v]&&ar[u][v]==ar[u-1][v]){

            current.push_front(v);
            current.push_front(u-1);

            level[u-1][v] = level[u][v];
        }

        if(possible(u , v+1)==true&&level[u][v+1]>level[u][v]&&ar[u][v]==ar[u][v+1]){

            current.push_front(v+1);
            current.push_front(u);

            level[u][v+1] = level[u][v];
        }

        if(possible(u , v-1)==true&&level[u][v-1]>level[u][v]&&ar[u][v]==ar[u][v-1]){

            current.push_front(v-1);
            current.push_front(u);

            level[u][v-1] = level[u][v];
        }

        if(possible(u+1 , v)==true&&level[u+1][v]>level[u][v]+1&&ar[u][v]!=ar[u+1][v]){

            current.push_back(u+1);
            current.push_back(v);

            level[u+1][v] = level[u][v]+1;
        }

        if(possible(u-1 , v)==true&&level[u-1][v]>level[u][v]+1&&ar[u][v]!=ar[u-1][v]){

            current.push_back(u-1);
            current.push_back(v);

            level[u-1][v] = level[u][v]+1;
        }

        if(possible(u , v+1)==true&&level[u][v+1]>level[u][v]+1&&ar[u][v]!=ar[u][v+1]){

            current.push_back(u);
            current.push_back(v+1);

            level[u][v+1] = level[u][v]+1;
        }

        if(possible(u , v-1)==true&&level[u][v-1]>level[u][v]+1&&ar[u][v]!=ar[u][v-1]){

            current.push_back(u);
            current.push_back(v-1);

            level[u][v-1] = level[u][v]+1;
        }
    }
}

void setUp(int n , int m)
{
    for(int i=0;i<=n;i++)

        for(int j=0;j<=m;j++){

            level[i][j] = 12345;
        }
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        scanf("%d %d",&n , &m);
        setUp(n , m);

        for(int i=0;i<n;i++)scanf("%s",&ar[i]);
        bfs();


        printf("%d\n",level[n-1][m-1]);
    }

    return 0;
}
