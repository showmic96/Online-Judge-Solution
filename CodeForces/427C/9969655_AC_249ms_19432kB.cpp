// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5 + 9;

vector<ll>edges[MAX+9] , rEdges[MAX+9];

ll cost[MAX+9] , c;
bool visited[MAX+9];
stack<ll>st;
ll mi;
vector<ll>ans;

void dfs1(ll i)
{
    if(visited[i]==true)return ;
    visited[i] = true;

    ll si = edges[i].size();

    for(ll j=0;j<si;j++){

        dfs1(edges[i][j]);
    }

    st.push(i);
}

void dfs2(int i)
{
    if(visited[i]==true)return ;
    visited[i] = true;

    if(cost[i]<mi){

        mi = cost[i];
        c = 0;
        c++;
    }

    else if(cost[i]==mi){

        c++;
    }

    ll si = rEdges[i].size();

    for(ll j=0;j<si;j++){

        dfs2(rEdges[i][j]);
    }
}

int main(void)
{
    //freopen("input.txt","r",stdin);

    memset(visited , false, sizeof(visited));

    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++){

        scanf("%d",&cost[i]);
    }

    int m;
    scanf("%d",&m);

    for(int i=0;i<m;i++){

        int in1 , in2;
        scanf("%d %d",&in1 , &in2);

        edges[in1].push_back(in2);
        rEdges[in2].push_back(in1);
    }

    for(int i=1;i<=n;i++){

        if(visited[i]==false){

            dfs1(i);
        }
    }

    memset(visited , false , sizeof(visited));

    ll ans1 = 0 , ans2 = 1;

    while(st.empty()==false){

        int temp = st.top();
        st.pop();

        if(visited[temp]==false){

            mi = 123456789101112;
            c = 0;
            dfs2(temp);

            ans1+=mi;

            ans2*=c;
            ans2%=1000000007;
        }
    }

    printf("%lld %lld\n",ans1 , ans2);

    return 0;
}
