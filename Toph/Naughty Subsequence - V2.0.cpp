// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int dp[505][27][3];
vector<int>v;

int f(int i , int last , int now)
{
    if(i==v.size())return 0;
    if(dp[i][last][now]!=-1)return dp[i][last][now];
    int value = 0;
    if(now==0){
        value = max(value , f(i+1 , last , now));
        value = max(value , f(i+1 , v[i] , 1)+1);
        value = max(value , f(i+1 , v[i] , 2)+1);
    }
    if(now==1){
        value = max(value , f(i+1 , last , now));
        if(v[i]>last){
            value = max(value , f(i+1 , v[i] , 1)+1);
            value = max(value , f(i+1 , v[i] , 2)+1);
        }
        if(v[i]<last){
            value = max(value , f(i+1 , v[i] , 2)+1);
        }
    }
    if(now==2){
        value = max(value , f(i+1 , last , now));
        if(v[i]<last){
            value = max(value , f(i+1 , v[i] , 2)+1);
        }
    }
    return dp[i][last][now] = value;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        v.clear();
        int n;
        cin >> n;
        for(int i=0;i<n;i++){
            char x;
            cin >> x;
            v.push_back(x-'A');
        }
        memset(dp , -1 , sizeof(dp));
        cout << f(0 , 0 , 0) << endl;
    }
    return 0;
}