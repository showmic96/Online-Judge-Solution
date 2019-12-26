// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;

ll dp[2005][2005][2];
string ar;

ll n , m , d;

bool Check(string ar)
{
    if(ar=="0")return false;
    if(ar.size()==1&&d==0&&(ar[0]-'0')%m==0)return true;

    ll mod = 0;

    for(int i=0;i<n;i++){

        if(i%2)if(ar[i]!='0'+d)return false;
        if(!(i%2))if(ar[i]=='0'+d)return false;

        mod*=10;
        mod+=ar[i]-'0';
        mod%=m;
    }

    if(mod==0)return true;
    return false;
}

ll f(int i , int mod , int smaller)
{
    if(i==n){

        if(mod==0)return 1;
        return 0;
    }

    if(dp[i][mod][smaller]!=-1)return dp[i][mod][smaller];

    ll value = 0;

    int st = 0 , en = ar[i]-'0';
    if(smaller)en = 9;
    if(!i)st = 1;

    for(int j=st;j<=en;j++){

        if(i%2==0&&j==d)continue;
        if(i%2==1&&j!=d)continue;

        if(j==en){

            value+=f(i+1 , (mod*10+j)%m , smaller);
        }
        else{

            value+=f(i+1 , (mod*10+j)%m , 1);
        }
    }

    return dp[i][mod][smaller] = value%MOD;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    string s1 , s2;
    cin >> m >> d >> s1 >> s2;

    n = s1.size();

    ar = s1;
    memset(dp , -1 , sizeof(dp));

    ll ans1 = f(0 , 0 , 0);

    if(Check(s1)==true)ans1--;

    ar = s2;
    memset(dp , -1 , sizeof(dp));

    ll ans2 = f(0 , 0 , 0);

    cout << (ans2-ans1+MOD)%MOD << endl;

    return 0;
}
