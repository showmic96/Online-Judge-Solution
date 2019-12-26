// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

map<string , int>dp;
int f(string s)
{
    if(s=="")return 1;
    if(dp.find(s)!=dp.end())return dp[s];
    int value = 0;
    for(int i=0 , j;i<s.size();i++){
        for(j=i;j<s.size();j++){
            if(s[i]!=s[j])break;
        }
        if(j>=i+2){
            string temp = s.substr(0 , i) + s.substr(j);
            value = max(value , f(temp));
            if(value==1)return dp[s] = value;
            i = j-1;
        }
    }
    return dp[s] = value;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        string ar;
        cin >> ar;
        dp.clear();
        cout << f(ar) << endl;
    }

    return 0;
}
