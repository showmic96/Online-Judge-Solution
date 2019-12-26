// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[105][105][105];
vector<ll>v;
string ar;

ll f(int i , int j , int tot)
{
    if(i>j)return 0;
    if(dp[i][j][tot]!=-1)return dp[i][j][tot];

    ll value = f(i+1 , j , 0) + v[tot];
    for(int k=i+1;k<=j;k++){

        if(ar[i]==ar[k])value = max(value , f(i+1 , k-1 , 0) + f(k , j , tot+1));
    }

    return dp[i][j][tot] = value;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    cin >> ar;

    for(int i=0;i<n;i++){
        ll in;
        cin >> in;
        v.push_back(in);
    }
    memset(dp , -1 , sizeof(dp));
    cout << f(0 , n-1 , 0) << endl;

    return 0;
}
