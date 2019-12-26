// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 123;
vector<int>edges[MAX];
int level[MAX] , ans , mx;

void setUp()
{
    for(int i=0;i<MAX;i++){

        edges[i].clear();
        level[i] = 0;
    }
}

void bfs(int i)
{
    queue<int>current;

    current.push(i);

    while(!current.empty()){

        int u = current.front();
        current.pop();

        int si = edges[u].size();

        for(int i=0;i<si;i++){

            if(level[edges[u][i]]<level[u]+1){

                level[edges[u][i]] = level[u] + 1;

                if(level[edges[u][i]]>mx){

                    mx = level[edges[u][i]];
                    ans = edges[u][i];
                }
                else if(level[edges[u][i]]==mx){
                    
                    ans = min(ans , edges[u][i]);
                }

                current.push(edges[u][i]);
            }
        }
    }
}

int main(void)
{
    int n;
    int c = 0;

    while(cin >> n){

        if(!n)break;

        setUp();
        int s ,in1 , in2;
        cin >> s;

        while(cin >> in1 >> in2){

            if(!in1&&!in2)break;

            edges[in1].push_back(in2);
        }

        mx = 0;

        bfs(s);

        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",++c ,s , mx , ans);

    }

    return 0;
}
