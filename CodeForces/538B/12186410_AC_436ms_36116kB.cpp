// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int dp[1000005];

struct node{

    int value;
    vector<int>v;

    node(int _value , vector<int>_v){

        value = _value;
        v = _v;
    }
};

vector<int>edges;

void f(int value)
{
    if(value>1e6)return ;
    edges.push_back(value);
    f(value*10+1);
    f(value*10+0);
}

void bfs(int u)
{
    queue<node>current;
    dp[u] = 0;
    vector<int>temp;

    current.push(node(u , temp));

    while(!current.empty()){

        u = current.front().value;
        temp = current.front().v;

        current.pop();

        dp[u] = 1;

        if(u==0){

            int si = temp.size();
            printf("%d\n",si);
            for(int i=0;i<si;i++){

                if(i>0)printf(" ");
                printf("%d",temp[i]);
            }

            printf("\n");
            return ;
        }

        for(int i=63;i>=1;i--){

            if(u-edges[i]>=0){

                if(dp[u-edges[i]]==1)continue;
                dp[u-edges[i]] = 1;

                vector<int>t = temp;
                t.push_back(edges[i]);
                current.push(node(u-edges[i] , t));
            }
        }

        if(u<10){

            vector<int>t = temp;
            t.push_back(edges[0]);
            current.push(node(u-edges[0] , t));
        }
    }
}

int main(void)
{
    memset(dp , 0 , sizeof(dp));

    f(1);
    sort(edges.begin() , edges.end());

    int n;
    scanf("%d",&n);

    bfs(n);

    return 0;
}
