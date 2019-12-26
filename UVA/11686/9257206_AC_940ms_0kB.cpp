// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 100;
vector<int>edges[MAX];
vector<int>ans;
int in_degree[MAX];
bool isVisited[MAX];

void setUp(int n)
{
    for(int i=0;i<=n;i++){

        edges[i].clear();
    }
}

void dfs(int i)
{

    int si = edges[i].size();

    for(int j=0;j<si;j++){

        int temp = edges[i][j];

        in_degree[temp]--;

        if(in_degree[temp]==0){

            ans.push_back(temp);
            isVisited[temp] = true;

            dfs(temp);
        }
    }

    return ;
}

int main(void)
{
    int n , m;
    while(cin >> n >> m){

        if(!n&&!m)break;

        setUp(n);

        memset(in_degree , 0 , sizeof(in_degree));
        memset(isVisited , false , sizeof(isVisited));

        for(int i=0;i<m;i++){

            int in1 , in2;
            cin >> in1 >> in2;

            edges[in1].push_back(in2);

            in_degree[in2]++;
        }

        ans.clear();

        for(int i=1;i<=n;i++){

            if(isVisited[i]==true)continue;

            if(in_degree[i]==0){

                ans.push_back(i);
                isVisited[i] = true;
                dfs(i);
            }
        }

        bool check = true;

        for(int i=1;i<=n;i++){

            if(isVisited[i]==false) check = false;
        }

        if(check==false)cout << "IMPOSSIBLE" << endl;
        else{

            int si = ans.size();

            for(int i=0;i<si;i++){

                cout << ans[i] << endl;
            }

        }

    }

    return 0;
}
