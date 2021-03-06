// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 2005;
int dp[MAX][MAX], n , k;
string dig[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
vector<string>v;
int req(string t , int n)
{
    string s = dig[n];
    int cnt = 0;
    for(int i=0;i<t.size();i++){
        if(t[i]!=s[i]){
            if(t[i]=='1')return 1e7;
            cnt++;
        }
    }
    return cnt;
}

int f(int i , int k)
{
    if(i==n){
        if(k==0)return 1;
        return 0;
    }
    if(dp[i][k]!=-1)return dp[i][k];
    int value = 0;
    for(int j=9;j>=0;j--){
        int r = req(v[i] , j);
        if(k-r>=0)value = max(value , f(i+1 , k-r));
    }
    return dp[i][k] = value;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> k;
    for(int i=0;i<n;i++){
        string ar;
        cin >> ar;
        v.push_back(ar);
    }
    memset(dp , -1 , sizeof(dp));
    if(f(0 , k)==0)cout << -1 << endl;
    else{
        int now = k;
        for(int i=0;i<n;i++){
            for(int j=9;j>=0;j--){
                int r = req(v[i] , j);
                if(now-r>=0&&f(i+1 , now-r)==1){
                    now-=r;
                    cout << j;
                    break;
                }
            }
        }
    }

    return 0;
}
