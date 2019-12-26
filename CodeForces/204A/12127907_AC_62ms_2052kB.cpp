// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int>v;
int si;

void make(ll x)
{
    v.clear();

    while(x!=0){

        v.push_back(x%10);
        x/=10;
    }

    reverse(v.begin() , v.end());
}

ll dp[20][2][10][10];


ll f(int i , int smaller , int first , int last)
{
    if(i==si){

        if(first==last)return 1;
        return 0;
    }

    if(dp[i][smaller][first][last]!=-1)return dp[i][smaller][first][last];

    int lim = v[i];

    if(smaller==1)lim = 9;

    ll value = 0;

    for(int j=0;j<=lim;j++){

        if(j==lim){

            if(first==0)value+=f(i+1 , smaller , j , j);
            else value+=f(i+1 , smaller , first , j);
        }

        else{

            if(first==0)value+=f(i+1 , 1 , j , j);
            else value+=f(i+1 , 1 , first , j);
        }
    }

    return dp[i][smaller][first][last] = value;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll a , b;
    cin >> a >> b;

    make(a-1);

    si = v.size();

    memset(dp , -1 , sizeof(dp));

    ll ans1 = f(0 , 0 , 0 , 0);

    make(b);

    si = v.size();

    memset(dp , -1 , sizeof(dp));

    ll ans2 = f(0 , 0 , 0 , 0);

    cout << ans2-ans1 << endl;


    return 0;
}
