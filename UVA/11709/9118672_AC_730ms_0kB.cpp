// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e4+10;
vector<int>edges[MAX+9] , edges2[MAX+9] , node;
bool isVisited[MAX+9];

void setUp()
{
    node.clear();

    for(int i=0;i<MAX;i++){

        edges[i].clear();
        edges2[i].clear();
        isVisited[i] = false;
    }
}

void dfs1(int u)
{
    if(isVisited[u]==true)return ;
    isVisited[u] = true;

    int si = edges[u].size();

    for(int i=0;i<si;i++){

        dfs1(edges[u][i]);
    }

    node.push_back(u);
}

void dfs2(int u)
{
    if(isVisited[u]==true)return ;
    isVisited[u] = true;

    int si = edges2[u].size();

    for(int i=0;i<si;i++){

        dfs2(edges2[u][i]);
    }

}


int main(void)
{
    int n , m;

    while(cin >> n >> m){

        if(!n&&!m)break;
        scanf("\n");
        setUp();
        map<string , int>mp;

        for(int i=0;i<n;i++){

            string ar;

            getline(cin , ar);
            mp[ar] = i+1;
        }

        while(m--){

            string ar , br;
            getline(cin , ar);
            getline(cin , br);

            edges[mp[ar]].push_back(mp[br]);
            edges2[mp[br]].push_back(mp[ar]);
        }

        for(int i=1;i<=n;i++){

            if(isVisited[i]==false){

                dfs1(i);
            }
        }

        memset(isVisited , false ,sizeof(isVisited));

        int ans = 0;

        int si = node.size();
        reverse(node.begin() , node.end());

        for(int i=0;i<si;i++){

            if(isVisited[node[i]]==false){

                dfs2(node[i]);
                ans++;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
