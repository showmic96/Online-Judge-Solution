// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 2005+9;
int lvl[MAX];

vector<int>edges[MAX+9];

void bfs(int st)
{
    memset(lvl , 0 , sizeof(lvl));
    int u = st;
    queue<int>current;
    current.push(u);
    while(!current.empty()){

        u = current.front();
        current.pop();

        for(auto v : edges[u]){

            if(lvl[v]==0){

                lvl[v] = lvl[u]+1;
                if(v==st)return ;
                current.push(v);
            }
        }
    }
}

int main(void)
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){

        for(int j=1;j<=n;j++){

            int in;
            scanf("%d",&in);
            if(in==1)edges[i].push_back(j);
        }
    }

    for(int i=1;i<=n;i++){

        bfs(i);
        if(lvl[i]==0)printf("NO WAY\n");
        else printf("%d\n",lvl[i]);
    }

    return 0;
}
