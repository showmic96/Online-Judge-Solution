// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 50000 + 9;

vector<int>edges[MAX+9] , rEdges[MAX+9] , ans[MAX];

int lvl[MAX+9] , counter;
bool vis[MAX+9];
stack<int>st;

int dfs(int i , int first)
{
    if(vis[i]==true)return lvl[i];
    vis[i] = true;

    lvl[i] = 0;

    int si = edges[i].size();

    int value = 0;

    for(int j=0;j<si;j++){

        value+=dfs(edges[i][j] , 0)+1;
    }

    return lvl[i] = value;
}

void dfs1(int i)
{
    if(vis[i]==true)return ;
    vis[i] = true;

    int si = edges[i].size();

    for(int j=0;j<si;j++){

        dfs1(edges[i][j]);
    }

    st.push(i);
}

void dfs2(int i , int p)
{
    if(vis[i]==true)return ;
    vis[i] = true;

    ans[p].push_back(i);

    int si = rEdges[i].size();

    for(int j=0;j<si;j++){

        dfs2(rEdges[i][j] , p);
    }
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        int n;
        scanf("%d",&n);

        memset(vis , false , sizeof(vis));
        memset(lvl , -1 , sizeof(lvl));

        for(int i=0;i<=n;i++){

            edges[i].clear();
            rEdges[i].clear();
            ans[i].clear();
        }

        for(int i=0;i<n;i++){

            int in1 , in2;
            scanf("%d %d", &in1 , &in2);

            edges[in1].push_back(in2);
            rEdges[in2].push_back(in1);
        }

        for(int i=1;i<=n;i++){

            if(vis[i]==false){

                dfs1(i);
            }
        }

        memset(vis , false , sizeof(vis));
        int now = 0;

        while(st.empty()==false){

            int u = st.top();
            st.pop();

            if(vis[u]==false){

                dfs2(u , now++);
            }
        }

        memset(vis , false , sizeof(vis));
        int mx = 0 , idx = -1;

        for(int i=0;i<now;i++){

            int si = ans[i].size();
            if(si<2)continue;

            for(int j=0;j<si;j++){

                lvl[ans[i][j]] = si;
                vis[ans[i][j]] = true;

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

            if(vis[i]==false){

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

        printf("Case %d: %d\n", ++c , idx);

        while(st.empty()==false)st.pop();
    }

    return 0;
}
