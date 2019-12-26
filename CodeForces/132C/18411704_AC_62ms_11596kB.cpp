// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int dp[105][55][2][205] , n , si;
string ar;
bool vis[105][55][2][205];
int get(int temp)
{
    if(temp>=0)return temp;
    return 204+temp;
}

int f(int i , int rem , int dir , int tot)
{
    if(i==n){
        if(rem%2==0)return abs(tot);
        return -1e5;
    }
    int now = get(tot);

    if(vis[i][rem][dir][now]==true)return dp[i][rem][dir][now];
    vis[i][rem][dir][now] = true;
    int value = 0;

    if(ar[i]=='F'){
            if(rem>0)value = max(value , f(i+1 , rem-1 , dir^1 , tot));

            if(dir==0)value = max(value , f(i+1 , rem , dir , tot+1));
            else value = max(value , f(i+1 , rem , dir , tot-1));
    }
    else if(ar[i]=='T'){
        if(rem>0){
            if(dir==0)value = max(value , f(i+1 , rem-1 , dir , tot+1));
            else value = max(value , f(i+1 , rem-1 , dir , tot-1));
        }
        value = max(value , f(i+1 , rem , dir^1 , tot));

    }
    return dp[i][rem][dir][now] = value;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> ar >> si;
    n = ar.size();
    memset(vis , false , sizeof(vis));
    int ans = f(0 , si , 0 , 0);
    cout << ans << endl;

    return 0;
}
