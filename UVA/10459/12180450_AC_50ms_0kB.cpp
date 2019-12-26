// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 5000+9;

vector<int>edges[MAX+9];
int level[MAX+9] , level1[MAX+9] , level2[MAX+9];

int bfs()
{
    queue<int>current;
    level[1] = 1;
    current.push(1);

    int last = 1;

    while(!current.empty()){

        int u = current.front();
        current.pop();

        last = u;

        int si = edges[u].size();

        for(int i=0;i<si;i++){

            if(level[edges[u][i]]==0){

                level[edges[u][i]] = level[u] + 1;
                current.push(edges[u][i]);
            }
        }
    }

    return last;
}

int bfs1(int v)
{
    queue<int>current;
    level1[v] = 1;
    current.push(v);

    int last = 1;

    while(!current.empty()){

        int u = current.front();
        current.pop();

        int si = edges[u].size();

        for(int i=0;i<si;i++){

            if(level1[edges[u][i]]==0){

                level1[edges[u][i]] = level1[u] + 1;
                current.push(edges[u][i]);

                last = max(last , level1[edges[u][i]]);
            }
        }
    }

    return last;
}

int bfs2(int v)
{
    queue<int>current;
    level2[v] = 1;
    current.push(v);

    int last = 1;

    while(!current.empty()){

        int u = current.front();
        current.pop();

        last = u;

        int si = edges[u].size();

        for(int i=0;i<si;i++){

            if(level2[edges[u][i]]==0){

                level2[edges[u][i]] = level2[u] + 1;
                current.push(edges[u][i]);
            }
        }
    }

    return last;
}

int main(void)
{
    int n;
    while(scanf("%d",&n)==1){

        memset(level , 0 , sizeof(level));
        memset(level1 , 0 , sizeof(level1));
        memset(level2 , 0 , sizeof(level2));

        for(int i=0;i<=n;i++)edges[i].clear();

        for(int i=1;i<=n;i++){

            int si;
            scanf("%d",&si);

            for(int j=0;j<si;j++){

                int in;
                scanf("%d",&in);
                edges[i].push_back(in);
            }
        }

        set<int>best , worst;
        set<int>:: iterator it;

        int last = bfs();

        int mx = bfs1(last);
        int mxx = mx/2;

        if(mx%2==1)mxx++;

        for(int i=1;i<=n;i++){

            if(level1[i]==mx){

                worst.insert(i);
            }
        }

        for(it=worst.begin();it!=worst.end();it++){

            bfs2(*it);
            break;
        }

        for(int i=1;i<=n;i++){

            if(level2[i]==mx){

                worst.insert(i);
            }

            if(mx%2==0){

                if(level2[i]==mxx&&level1[i]==mxx+1){

                    best.insert(i);
                }

                if(level2[i]==mxx+1&&level1[i]==mxx){

                    best.insert(i);
                }
            }

            else{

                if(level1[i]==mxx&&level1[i]==level2[i]){

                    best.insert(i);
                }
            }
        }

        printf("Best Roots  :");

        for(it=best.begin();it!=best.end();it++){

            int temp = *it;

            printf(" %d",temp);
        }

        printf("\nWorst Roots :");

        for(it=worst.begin();it!=worst.end();it++){

            int temp = *it;

            printf(" %d",temp);
        }

        printf("\n");
    }

    return 0;
}
