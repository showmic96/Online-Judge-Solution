// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 9;
vector<int>edges[MAX+9] , ans;
bool visited[MAX+9];
int parent[MAX+9];

void gen(int x)
{

    if(parent[x]==x)return ;

    ans.push_back(x);

    gen(parent[x]);
}

void bfs(int st , int en)
{
    queue<int>current;

    current.push(st);
    visited[st] = true;

    while(!current.empty()){

        int u = current.front();
        current.pop();

        int si = edges[u].size();

        for(int i=0;i<si;i++){

            if(visited[edges[u][i]]==false){

                visited[edges[u][i]] = true;

                parent[edges[u][i]] = u;

                current.push(edges[u][i]);

                if(edges[u][i]==en){

                    gen(en);
                    return;
                }
            }
        }
    }
}

int main(void)
{
    int t;
    cin >> t;
    bool space = false;
    while(t--){

        if(space)cout << endl;space = true;
        int m , q;
        cin >> m >> q;
        int c = 0;

        map<string , int>mp;
        map<int , string>demap;

        for(int i=0;i<MAX;i++)edges[i].clear();

        while(m--){

            string ar , br;
            cin >> ar >> br;

            if(mp[ar]==0){

                mp[ar] = ++c;
                demap[c] = ar;
            }

            if(mp[br]==0){

                mp[br] = ++c;

                demap[c] = br;
            }

            edges[mp[ar]].push_back(mp[br]);
            edges[mp[br]].push_back(mp[ar]);
        }

        while(q--){

            string ar , br;
            cin >> ar >> br;

            ans.clear();
            memset(visited , false , sizeof(visited));

            for(int i=0;i<MAX;i++)parent[i] = i;

            bfs(mp[ar] , mp[br]);

            int si = ans.size();

            cout << ar[0];
            reverse(ans.begin(),ans.end());

            for(int i=0;i<si;i++){

                cout << demap[ans[i]][0];
            }

            cout << endl;
        }
    }
    return 0;
}
