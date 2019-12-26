// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 2345;
vector<int>edges[2345+9];
vector<int>root;
int ans = 1 , level[MAX+9];

void bfs(int i)
{
    queue<int>current;

    current.push(i);

    level[i] = 1;

    while(!current.empty()){

        i = current.front();
        current.pop();

        int si =edges[i].size();

        for(int j=0;j<si;j++){

            if(level[edges[i][j]]==0){

                level[edges[i][j]] = level[i]+1;

                ans = max(ans , level[edges[i][j]]);

                current.push(edges[i][j]);
            }
        }
    }

}

void setUp()
{
    for(int i=0;i<MAX;i++)level[i] = 0;
}

int main(void)
{
    int n;
    scanf("%d",&n);//cin >> n;
    for(int i=1;i<=n;i++){

        int in;
        scanf("%d",&in);//cin >> in;
        if(in==-1){

            root.push_back(i);
        }
        else{

            edges[in].push_back(i);
        }
    }

    setUp();

    int si = root.size();

    for(int i=0;i<si;i++){

        bfs(root[i]);
    }

    printf("%d\n",ans);

    return 0;
}
