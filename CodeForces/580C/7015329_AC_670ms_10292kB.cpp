#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10 , INF = 1e9;

int level[MAX+1];
vector<int>edges[MAX+1];
set<int>leaf;
set<int>::iterator it;
map<int,int>isVisited;

void bfs(int m)
{
    queue<int>current;

    current.push(1);

    while(!current.empty()){

        int temp = current.front();
        current.pop();

        int si = edges[temp].size();

        if(si==1&&temp!=1)leaf.insert(temp);

        for(int i=0;i<si;i++){

            if(!isVisited[edges[temp][i]]){

                isVisited[edges[temp][i]] = 1;
                if(level[edges[temp][i]]!=0)level[edges[temp][i]]+=level[temp];
                if(level[edges[temp][i]]<=m)current.push(edges[temp][i]);
            }
        }
    }

}

int main(void)
{
    int n , m;

    cin >> n >> m;

    int in , in1 , in2;

    for(int i = 1;i<=n;i++){

        cin >> in;
        level[i] = in;
    }

    for(int i=1;i<n;i++){

        cin >> in1 >> in2;

        edges[in1].push_back(in2);
        edges[in2].push_back(in1);
    }

    bfs(m);

    int counter = 0;

    //cout << leaf.size();

    for(it = leaf.begin();it!=leaf.end();it++){

        if(level[*it]<=m)counter++;
    }

    cout << counter << endl;

    return 0;
}
