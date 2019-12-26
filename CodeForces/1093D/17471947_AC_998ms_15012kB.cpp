// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 3e5+9;
const ll MOD = 998244353;

vector<int>edges[MAX+9];
int state[MAX+9] , odd , even;
ll two[MAX+9];
bool check;

void dfs(int u , int now)
{
    if(state[u]!=-1){

        if(state[u]!=now){

            check = false;
        }

        return ;
    }

    if(check==false)return ;

    state[u] = now;
    if(now==0)even++;
    else odd++;

    for(auto v : edges[u]){

        dfs(v , now^1);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    two[0] = 1;
    for(int i=1;i<=MAX;i++){

        two[i] = two[i-1]*2LL;
        two[i]%=MOD;
    }

    int t;
    cin >> t;
    while(t--){

        int n , m;
        cin >> n >> m;

        for(int i=0;i<=n;i++){

            edges[i].clear();
            state[i] = -1;
        }

        check = true;

        for(int i=0;i<m;i++){

            int in1 , in2;
            cin >> in1 >> in2;
            edges[in1].push_back(in2);
            edges[in2].push_back(in1);
        }

        ll ans = 1;

        for(int i=1;i<=n;i++){

            if(state[i]==-1){

                odd = 0 , even = 0;
                dfs(i , 0);

                ll now = (two[odd] + two[even])%MOD;
                ans*=now;
                ans%=MOD;
            }
        }

        if(check==false)cout << 0 << endl;
        else cout << ans << endl;
    }

    return 0;
}
