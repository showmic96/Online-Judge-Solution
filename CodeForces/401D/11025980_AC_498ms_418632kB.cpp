// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[(1<<18)+10][102][2];

string ar;
int mod , n;


int Set(int n , int pos)
{
    return n|(1<<pos);
}

bool Check(int n , int pos)
{
    return n&(1<<pos);
}

ll f(int mask , int m , int zero)
{
    if(mask==(1<<n)-1){

        if(m==0)return 1;
        return 0;
    }

    if(dp[mask][m][zero]!=-1)return dp[mask][m][zero];

    ll value = 0;
    int mp[10];
    memset(mp , 0 , sizeof(mp));

    for(int i=0;i<n;i++){

        if(ar[i]=='0'&&zero==0)continue;

        if(Check(mask , i)==false){

            if(mp[ar[i]-'0']==1)continue;

            value+=f(Set(mask , i) , (m*10+(ar[i]-'0'))%mod , 1);

            mp[ar[i]-'0']=1;
        }
    }

    return dp[mask][m][zero] = value;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(dp , -1 , sizeof(dp));

    cin >> ar >> mod;

    n = ar.size();

    cout << f(0 , 0 , 0) << endl;

    return 0;
}
