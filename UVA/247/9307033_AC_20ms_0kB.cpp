// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5+9;
vector<int>edges[MAX+9];
vector<int>edgesr[MAX+9];
bool visited[MAX+9];
stack<int>store;
vector<int>ans[MAX+9];
int c1;

void dfs1(int u)
{
    if(visited[u]==true)return ;
    visited[u] = true;

    int si = edges[u].size();

    for(int i=0;i<si;i++){

        dfs1(edges[u][i]);
    }

    store.push(u);
}

void dfs2(int u)
{
    if(visited[u]==true)return ;
    visited[u] = true;

    ans[c1].push_back(u);

    int si = edgesr[u].size();

    for(int i=0;i<si;i++){

        dfs2(edgesr[u][i]);
    }
}

int main(void)
{
    int n , m , k = 0;

    while(scanf("%d %d",&n , &m)==2){

        if(!n&&!m)break;
        if(k!=0)printf("\n");
        //store.clear();

        for(int i=0;i<=n;i++){

            edges[i].clear();
            edgesr[i].clear();
            ans[i].clear();
        }

        map<string,int>mp;
        map<int,string>mp2;

        int c = 0;

        while(m--){

            string ar , br;
            cin >> ar >> br;

            if(mp[ar]==0){

                mp[ar] = ++c;
                mp2[c] = ar;
            }

            if(mp[br]==0){

                mp[br] = ++c;
                mp2[c] = br;
            }

            edges[mp[ar]].push_back(mp[br]);
            edgesr[mp[br]].push_back(mp[ar]);
        }

        memset(visited , false ,sizeof(visited));

        for(int i=1;i<=n;i++){

            if(visited[i]==false)dfs1(i);
        }

        memset(visited , false , sizeof(visited));

        c1 = -1;

        while(!store.empty()){

            int temp = store.top();
            store.pop();

            if(visited[temp]==false){

                c1++;
                dfs2(temp);
            }
        }

        printf("Calling circles for data set %d:\n",++k);

        for(int i=0;i<=c1;i++){

            int si = ans[i].size();

            for(int j=0;j<si;j++){
                //cout << i << " " << j << endl;
                if(j>0)cout << ", ";
                cout << mp2[ans[i][j]];
            }

            printf("\n");
        }
    }
    return 0;
}
