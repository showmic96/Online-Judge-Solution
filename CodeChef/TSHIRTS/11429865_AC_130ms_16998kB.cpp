// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n , si;

int fre[11][105];
ll dp[110][(1<<10)+9];
ll MOD = 1000000007;

vector<int>v;

int Set(int n , int pos)
{
    return n|(1<<pos);
}

bool Check(int n , int pos)
{
    return n&(1<<pos);
}

ll f(int i , int mask)
{
    if(i==si){

        if(mask==(1<<n)-1)return 1;
        return 0;
    }

    if(dp[i][mask]!=-1)return dp[i][mask];

    ll value = 0;

    value+=f(i+1 , mask);

    for(int j=0;j<n;j++){

        if(fre[j][v[i]]==1){

            if(Check(mask , j)==false)value+=f(i+1 , Set(mask , j));
            value%=MOD;
        }
    }

    return dp[i][mask] = value;
}

int main(void)
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    int t;
    cin >> t;
    while(t--){

        cin >> n;
        memset(fre , 0 , sizeof(fre));
        memset(dp , -1 , sizeof(dp));

        v.clear();
        map<int , int>mp;
        scanf("\n");
        for(int i=0;i<n;i++){

            string ar;
            getline(cin , ar);

            stringstream ss(ar);

            int in;

            while(ss >> in){

                fre[i][in] = 1;
                if(mp[in]==0)v.push_back(in);
                mp[in] = 1;
            }
        }

        si = v.size();

        printf("%lld\n",f(0 , 0));
    }

    return 0;
}
