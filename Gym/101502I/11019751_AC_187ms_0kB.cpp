#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int>edges[255];
int level[255];

void bfs(int st)
{
    level[st] = 1;

    queue<int>current;

    current.push(st);

    while(!current.empty()){

        int u = current.front();
        current.pop();

        int si = edges[u].size();

        for(int i=0;i<si;i++){

            if(level[edges[u][i]]==0){

                level[edges[u][i]] = level[u] + 1;
                current.push(edges[u][i]);
            }
        }
    }
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        int n , st , en;

        scanf("%d %d %d",&n , &st , &en);

        vector<int>v[300];

        for(int i=0;i<n;++i){

            edges[i+1].clear();

            string ar;
            cin >> ar;

            int fr[10];
            memset(fr , 0 , sizeof(fr));

            for(int j=0;j<20;j++){

                fr[ar[j]-'0']++;
            }

            for(int j=0;j<=9;j++){

                v[i].push_back(fr[j]);
            }
        }

        for(int i=0;i<n;i++){


            for(int j=0;j<n;j++){

                int counter = 0;

                for(int k=0;k<=9;k++){

                    counter+=min(v[i][k] , v[j][k]);
                }

                if(counter==17){

                    edges[i+1].push_back(j+1);
                    edges[j+1].push_back(i+1);
                }
            }
        }

        memset(level , 0 , sizeof(level));

        bfs(st);

        if(level[en]==0)printf("-1\n");
        else printf("%d\n",level[en]-1);

    }
    return 0;
}
