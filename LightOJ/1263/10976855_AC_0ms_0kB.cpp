// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e3 + 9;

int n , m;
vector<int>edges[MAX] , v;
bool visited[MAX];

ll counter , node;

void dfs(int i)
{
    if(visited[i]==true)return ;
    visited[i] = true;

    counter+=v[i-1];
    node++;

    int si = edges[i].size();

    for(int j=0;j<si;j++){

        dfs(edges[i][j]);
    }

    return ;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        scanf("%d %d",&n, &m);

        ll sum = 0;
        v.clear();

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            v.push_back(in);
            sum+=in;

            edges[i].clear();
        }

        edges[n].clear();

        printf("Case %d: ",++c);


        while(m--){

            int in1 , in2;
            scanf("%d %d", &in1 , &in2);

            edges[in1].push_back(in2);
            edges[in2].push_back(in1);
        }

        if(sum%n!=0)printf("No\n");

        else{

            memset(visited , false , sizeof(visited));
            counter = 0;
            node = 0;
            sum = sum/n;

            bool check = true;

            for(int i=1;i<=n;i++){

                if(visited[i]==false){

                    counter = 0;
                    node = 0;
                    dfs(i);

                    if(counter%node!=0)check = false;
                    if(counter/node!=sum)check = false;
                }
            }

            if(check==false)printf("No\n");
            else printf("Yes\n");
        }
    }
    return 0;
}
