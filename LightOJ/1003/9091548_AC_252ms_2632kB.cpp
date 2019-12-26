// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 10000 + 9;
vector<int>edges[MAX+9];

int in_deg[MAX+9];

bool bfs(int d)
{
    queue<int>current;

    for(int i=1;i<=d;i++){

        if(in_deg[i]==0)current.push(i);
    }

    while(!current.empty()){

        int temp = current.front();
        current.pop();

        int si = edges[temp].size();

        for(int i=0;i<si;i++){

            in_deg[edges[temp][i]]--;
            if(in_deg[edges[temp][i]]==0)current.push(edges[temp][i]);
        }
    }

    for(int i=1;i<=d;i++){

        if(in_deg[i]!=0)return false;
    }

    return true;
}

void setUp()
{
    for(int i=0;i<=MAX;i++){

        edges[i].clear();
        in_deg[i] = 0;
    }
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        setUp();
        map<string , int>mp;

        int d = 0;

        int m;
        scanf("%d",&m);

        while(m--){

            string ar , br;
            cin >> ar >> br;

            if(mp[ar]==0){

                mp[ar] = ++d;
            }

            if(mp[br]==0){

                mp[br] = ++d;
            }

            edges[mp[ar]].push_back(mp[br]);

            in_deg[mp[br]]++;
        }

        if(bfs(d)==true)printf("Case %d: Yes\n",++c);
        else printf("Case %d: No\n",++c);

    }

    return 0;
}

