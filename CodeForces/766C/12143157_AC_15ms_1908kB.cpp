// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e3+9;
ll MOD = 1e9+7;

ll dp[MAX+9];
int n , mx = 0;
string ar;
vector<int>v;

ll f(int i)
{
    if(i==n)return 1;

    if(dp[i]!=-1)return dp[i];

    int len = n , counter = 0;
    ll value = 0;

    for(int i1=i;i1<n&&i1<len;i1++){

        len = min(len , i+v[ar[i1]-'a']);
        if(len<=i1)break;

        counter++;
        mx = max(mx , counter);

        value+=f(i1+1);
        value%=MOD;
    }

    return dp[i] = value;
}


ll f2(int i)
{
    if(i==n)return 0;

    if(dp[i]!=-1)return dp[i];

    int len = n , counter = 0;
    ll value = 1e9;

    for(int i1=i;i1<n&&i1<len;i1++){

        len = min(len , i+v[ar[i1]-'a']);
        if(len<=i1)break;

        counter++;
        mx = max(mx , counter);

        value=min(value , f2(i1+1)+1);

    }

    return dp[i] = value;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> ar;

    for(int i=0;i<26;i++){

        int in;
        cin >> in;

        v.push_back(in);
    }

    memset(dp , -1 , sizeof(dp));

    cout << f(0) << endl;
    cout << mx << endl;
    memset(dp , -1 , sizeof(dp));
    cout << f2(0) << endl;

    return 0;
}
