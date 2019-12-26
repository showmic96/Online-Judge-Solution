// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int dp[10005][105] , k;;
string ar;

int f(string val , int now)
{
    if(now>=k){

        if(val>ar)return 1;
        return 0;
    }

    int n = stoi(val) , value = 0;

    if(now&1)value = 1;

    if(dp[n][now]!=-1)return dp[n][now];

    for(int i=0;i<4;i++){

        string temp = val;

        if(temp[i]=='9')temp[i] = '0';
        else temp[i]++;

        if(now&1){

            value&=f(temp , now+1);
        }

        else value|=f(temp , now+1);
    }

    return dp[n][now] = value;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        cin >> ar >> k;

        memset(dp , -1 , sizeof(dp));

        if(f(ar , 0))cout << "Ada" << endl;
        else cout << "Vinit" << endl;
    }

    return 0;
}
