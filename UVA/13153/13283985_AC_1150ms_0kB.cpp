// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1e6+7;

bitset<MAX>isPrime;
vector<ll>primes;
vector<int>edges[MAX+9] , v1 , v2;
bool visited[MAX+9];

void seive()
{
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;

    for(int i=2;i<MAX;i++){

        if(isPrime[i]){

            for(int j=2*i;j<MAX;j+=i){

                isPrime[j] = 0;
            }

            primes.push_back(i);
        }
    }
}

void dfs(int u)
{
    visited[u] = true;

    int si = edges[u].size();

    for(int i=0;i<si;i++){

        if(!visited[edges[u][i]])dfs(edges[u][i]);
    }
}

void make(ll x)
{
    ll n = x;

    for(int i=0;primes[i]*primes[i]<=n;i++){

        if(n%primes[i]==0){

            while(n%primes[i]==0){

                n/=primes[i];
            }

            edges[x].push_back(primes[i]);
            edges[primes[i]].push_back(x);
        }
    }

    if(n>1){

        edges[x].push_back(n);
        edges[n].push_back(x);
    }
}

int main(void)
{
    seive();
    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        v1.clear();v2.clear();
        for(int i=0;i<=1000005;i++)edges[i].clear();

        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            if(isPrime[in])v1.push_back(in);
            else v2.push_back(in);
        }

        for(int i=0;i<v2.size();i++){

            make(v2[i]);
        }

        int counter = 0;
        memset(visited , false , sizeof(visited));

        for(int i=0;i<v1.size();i++){

            if(visited[v1[i]]==false){

                dfs(v1[i]);
                counter++;
            }
        }

        for(int i=0;i<v2.size();i++){

            if(visited[v2[i]]==false){

                dfs(v2[i]);
                counter++;
            }

            else if(v2[i]==1)counter++;
        }

        printf("Case %d: %d\n",++c , counter);
    }

    return 0;
}
