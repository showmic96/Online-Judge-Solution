// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int>v;
ll dp[18][18][2][2];

void make(ll x)
{
    v.clear();
    while(x){

        v.push_back(x%10);
        x/=10;
    }

    if(v.size()==0)v.push_back(0);
    reverse(v.begin() , v.end());
}

ll f(int i , int c , int smaller , int zero)
{
    if(i==v.size()){

        if(zero==0)return 0;
        return c;
    }

    if(dp[i][c][smaller][zero]!=-1)return dp[i][c][smaller][zero];

    ll value = 0;
    int lim = v[i];
    if(smaller==1)lim = 9;

    for(int j=0;j<=lim;j++){

        int z = 0;
        if(j>0)z = 1;

        z = max(z , zero);

        if(j<lim){

            if(z==1)value+=f(i+1 , c+1 , 1 , max(zero , z));
            else value+=f(i+1 , c , 1 , z);
        }
        else{

            if(z==1)value+=f(i+1 , c+1 , smaller , max(zero , z));
            else value+=f(i+1 , c , smaller, z);
        }
    }

    return dp[i][c][smaller][zero]=value;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){

        ll n , x;
        cin >> n >> x;

        memset(dp , -1 , sizeof(dp));
        make(x-1);

        ll now = f(0 , 0 , 0 , 0);

        ll hi = 1e16 , low = 0 , mid , t = 200, ans = -1;

        while(t--){

            mid = (hi+low)/2;
            make(mid);
            memset(dp , -1 , sizeof(dp));
            ll temp = f(0 , 0 , 0 , 0);

            if(temp-now==n)ans = mid;

            if(temp-now>n){

                hi = mid-1;
            }
            else low = mid+1;
        }

        if(ans==-1)cout << -1 << endl;
        else cout << ans - x + 1 << endl;
    }

    return 0;
}
