// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX =  1000+9;

bitset<MAX+9>bs;
vector<ll>primes , ans;
int lvl[MAX+9];

void sieve()
{
    bs&=0;
    for(int i=2;i<=MAX;i++){

        if(bs[i]==0){

            primes.push_back(i);
            for(int j=2*i;j<=MAX;j+=i)bs[j] = 1;
        }
    }
}

int bfs(int s , int t)
{
    if(s==t)return 0;

    queue<int>current;
    current.push(s);
    memset(lvl , 0 , sizeof(lvl));
    lvl[s] = 1;

    while(!current.empty()){

        int u = current.front();
        current.pop();

        vector<int>temp;

        int now = u;
        for(int i=0;primes[i]*primes[i]<=now;i++){

            if(now%primes[i]==0){

                temp.push_back(primes[i]);
                while(now%primes[i]==0){

                    now/=primes[i];
                }
            }
        }

        if(now>1&&now<u)temp.push_back(now);

        for(int i=0;i<temp.size();i++){

            int t1 = u+temp[i];
            if(t1==t)return lvl[u];
            if(t1>MAX)continue;

            if(lvl[t1]==0){

                lvl[t1] = lvl[u]+1;
                current.push(t1);
            }
        }
    }

    return -1;
}

int main(void)
{
    int a , b , c = 0;
    sieve();
    while(scanf("%d %d",&a , &b)==2){

        if(a==0&&b==0)break;

        int ans = bfs(a , b);
        printf("Case %d: %d\n",++c , ans);
    }
    return 0;
}
