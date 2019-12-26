// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 5005;
int dp[MAX][MAX] , n;
vector<int>v;
set<int>st;
map<int , int>mp , ump;

int f(int i , int j)
{
    if(i==n)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int now = min(ump[j] , v[i]);
    int value = f(i+1 , mp[now])+1;
    if(now<v[i])value = min(value , f(i+1 , mp[v[i]])+v[i]-now);
    if(now==v[i])value = min(value , f(i+1 , mp[now]));
    return dp[i][j] = value;
}

int main(void)
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int in;
        scanf("%d",&in);
        v.push_back(in);
        st.insert(in);
    }
    int c = 1;
    for(auto it:st){
        mp[it] = c;
        ump[c] = it;
        c++;
    }
    memset(dp , -1 , sizeof(dp));
    printf("%d\n",f(0 , 0));
    return 0;
}
