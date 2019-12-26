// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 50000 + 9;

vector<int>edges[MAX+9] , rEdges[MAX+9] , ans[MAX];
int level[MAX+9];
bool visited[MAX+9];
stack<int>st;

int counter;

void reset(int n)
{
    for(int i=0;i<=n;i++){

        edges[i].clear();
        rEdges[i].clear();
        ans[i].clear();
    }

    while(st.empty()==false)st.pop();
}

int dfs(int i , int first)
{
    if(visited[i]==true)return level[i];
    visited[i] = true;

    level[i] = 0;

    int si = edges[i].size();

    int value = 0;

    for(int j=0;j<si;j++){

        value+=dfs(edges[i][j] , 0)+1;
    }

    return level[i] = value;
}

void dfs1(int i)
{
    if(visited[i]==true)return ;
    visited[i] = true;

    int si = edges[i].size();

    for(int j=0;j<si;j++){

        dfs1(edges[i][j]);
    }

    st.push(i);
}

void dfs2(int i , int p)
{
    if(visited[i]==true)return ;
    visited[i] = true;

    ans[p].push_back(i);

    int si = rEdges[i].size();

    for(int j=0;j<si;j++){

        dfs2(rEdges[i][j] , p);
    }
}

int main(void)
{
    int t , tc = 0;
    scanf("%d",&t);

    while(t--){

        int n;
        scanf("%d",&n);

        memset(visited , false , sizeof(visited));
        memset(level , -1 , sizeof(level));
        reset(n);

        for(int i=0;i<n;i++){

            int in1 , in2;
            scanf("%d %d", &in1 , &in2);

            edges[in1].push_back(in2);
            rEdges[in2].push_back(in1);
        }

        for(int i=1;i<=n;i++){

            if(visited[i]==false){

                dfs1(i);
            }
        }

        memset(visited , false , sizeof(visited));
        int c = 0;

        while(st.empty()==false){

            int u = st.top();
            st.pop();

            if(visited[u]==false){

                dfs2(u , c++);
            }
        }

        memset(visited , false , sizeof(visited));
        int mx = 0 , idx = -1;

        for(int i=0;i<c;i++){

            int si = ans[i].size();
            if(si<2)continue;

            for(int j=0;j<si;j++){

                level[ans[i][j]] = si;
                visited[ans[i][j]] = true;

                if(si==mx){

                    idx = min(idx , ans[i][j]);
                }

                if(si>mx){

                    mx = si;
                    idx = ans[i][j];
                }
            }
        }

        for(int i=1;i<=n;i++){

            if(visited[i]==false){

                counter = dfs(i , 1);

                if(counter==mx){

                    idx = min(idx,  i);
                }

                if(counter>mx){

                    mx = counter;
                    idx = i;
                }
            }
        }

        printf("Case %d: %d\n", ++tc , idx);
    }

    return 0;
}
