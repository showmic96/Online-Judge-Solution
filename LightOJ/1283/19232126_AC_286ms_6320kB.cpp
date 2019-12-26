// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int dp[102][102][104] , n;
vector<int>v;
map<int , int>mp;
set<int>st;

int f(int i , int s , int e)
{
    if(i==n){
        return 0;
    }
    if(dp[i][s][e]!=-1)return dp[i][s][e];
    int value = f(i+1 , s , e);
    if(v[i]>=s&&v[i]<=e){
        value = max(value , f(i+1 , v[i] , e)+1);
        value = max(value , f(i+1 , s , v[i])+1);
    }
    return dp[i][s][e] = value;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        v.clear();st.clear();mp.clear();
        for(int i=0;i<n;i++){
            int in;
            scanf("%d",&in);
            v.push_back(in);
            st.insert(in);
        }
        int now = 1;
        for(set<int>::iterator it = st.begin();it!=st.end();it++){
            mp[*it] = now;
            now++;
        }
        for(int i=0;i<n;i++){
            v[i] = mp[v[i]];
        }
        memset(dp , -1 , sizeof(dp));
        printf("Case %d: %d\n",++c , f(0 , 0 , now+1));
    }
    return 0;
}
