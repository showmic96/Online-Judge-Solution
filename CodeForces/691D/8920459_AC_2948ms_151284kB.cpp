// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e6;
vector<ll>edges[MAX+9];
priority_queue<ll>ans[MAX+9];

map<ll, ll>mp;
ll n , m , ar[MAX+9];

bool cmp(ll a, ll b){return a>b;}

void dfs(ll i , ll l)
{
    if(mp[i]!=0)return ;
    mp[i] = l;
    ans[l].push(ar[i]);//ans[l].push_back(ar[i]);
    //cout << ar[i] << endl;
    int si = edges[i].size();

    for(int j=0;j<si;j++){

        dfs(edges[i][j] , l);
    }
}

int main(void)
{
    scanf("%lld %lld",&n , &m);//cin >> n >> m;

    for(int i=1;i<=n;i++)scanf("%lld",&ar[i]);//cin >> ar[i];

    while(m--){

        ll in1 , in2;
        scanf("%lld %lld",&in1 , &in2);//cin >> in1 >> in2;

        edges[in1].push_back(in2);
        edges[in2].push_back(in1);
    }

    int c = 1;

    for(int i=1;i<=n;i++){

        if(mp[i]==0){

            //cout << "DFS " << endl;
            dfs(i , c);
            //sort(ans[c].begin() , ans[c].end() , cmp);
            c++;
        }
    }

    for(int i=1;i<=n;i++){

        ll value = ans[mp[i]].top();
        ans[mp[i]].pop();

        printf("%lld ",value);//cout << ans[mp[i]][0] << " ";
    }

    printf("\n");//cout << endl;

    return 0;
}
