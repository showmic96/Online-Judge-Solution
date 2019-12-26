// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[21][(1<<18)+5];
vector<ll>value;
vector<pair<ll , ll > > v[25];
int n , m , k;

int Set(int n , int pos)
{
    return n|(1<<pos);
}

bool Check(int n , int pos)
{
    return n&(1<<pos);
}

ll f(int idx , int mask)
{
    int counter = 0;
    for(int i=0;i<n;i++){

        if(Check(mask , i)==true)counter++;
    }

    if(counter==m)return 0;

    if(dp[idx][mask]!=-1)return dp[idx][mask];

    ll val = 0;

    for(int i=0;i<n;i++){

        if(Check(mask , i)==false){

            ll temp = 0;

            int si = v[i].size();

            for(int j=0;j<si;j++){

                if(idx==v[i][j].first){

                    temp+=v[i][j].second;
                }
            }

            val = max(val , (f(i , Set(mask , i))+temp+value[i]));
        }
    }

    return dp[idx][mask] = val;
}

int main(void)
{
    memset(dp , -1 , sizeof(dp));

    scanf("%d %d %d",&n , &m ,&k);

    for(int i=0;i<n;i++){

        ll in;
        scanf("%lld",&in);
        value.push_back(in);
    }

    for(int i=0;i<k;i++){

        ll in1 , in2 , in3;
        scanf("%lld %lld %lld",&in1 , &in2 , &in3);
        v[in1-1].push_back(make_pair(in2-1 , in3));
    }

    printf("%lld\n",f(20 , 0));

    return 0;
}
