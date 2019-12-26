// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[1000005];
ll ans[1000005];

int main(void)
{
    memset(dp , 0 , sizeof(dp));
    memset(ans , -1 , sizeof(dp));

    ll n , mx = 0 , pos;
    cin >> n;
    ll ar[10];

    for(int i=1;i<=9;i++){cin >> ar[i];dp[ar[i]] = 1;ans[ar[i]] = i;}

    for(int i=1;i<=n;i++){

        for(int j=1;j<=9;j++){

            if(i-ar[j]>=1){

                if(dp[i]<=dp[i-ar[j]]+1){

                    dp[i] = dp[i-ar[j]] + 1;
                    ans[i] = j;
                    if(dp[i]>=mx){

                        mx = dp[i];
                        pos = i;
                    }
                }

            }
        }
    }

    vector<int>v;
    if(mx==0){cout << -1 << endl;return 0;}
    while(ans[pos]!=-1){

        v.push_back(ans[pos]);

        pos-= ar[ans[pos]];
    }

    int si = v.size();

    if(si!=0)sort(v.begin(), v.end());

    for(int i=si-1;i>=0;i--)cout << v[i];

    cout << endl;

    return 0;
}
