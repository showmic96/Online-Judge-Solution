#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll counter;
bool taken[25];
vector<int>v;
ll fact[25] , dp[2050][2050][12] , ans[100];

int Set(int n , int pos)
{
    return n|(1<<pos);
}
bool Check(int n , int pos)
{
    return n&(1<<pos);
}

void pre(int i, int now)
{
    if(i==n){

        if(now>0)v.push_back(now);
        return ;
    }

    pre(i+1 , Set(now , i));
    pre(i+1 , now);
}

ll f(int i , int mask , int len)
{
    if(i==v.size()){

        return fact[len];
    }

    if(dp[i][mask][len]!=-1)return dp[i][mask][len];

    ll value = f(i+1 , mask , len);

    bool check = true;
    for(int j=0;j<11;j++){

        if(Check(mask , j)==1&&Check(v[i] , j)==1){

            check = false;
            break;
        }
    }
    if(check)value+=f(i+1 , mask^v[i] , len+1);
    return dp[i][mask][len] = value;
}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    fact[0] = 1;
    for(ll i=1;i<=20;i++)fact[i] = fact[i-1] * i;
    memset(ans , -1 , sizeof(ans));

    int t , c = 0;
    cin >> t;
    while(t--){

        cin >> n;
        if(ans[n]==-1){

            v.clear();
            pre(0 , 0);

            memset(dp , -1 , sizeof(dp));
            ans[n] = f(0 , 0 , 0);
        }
        cout << ++c  << " " << n << " " << ans[n]-1 << endl;
    }

    return 0;
}
