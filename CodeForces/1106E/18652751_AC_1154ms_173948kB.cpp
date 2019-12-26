// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n , m , k;
vector<pair<int , int>>v1[100005];
vector<pair<int , int>>v2[100005];
pair<ll , ll>ar[100005];
ll dp[100005][205];

ll f(int i , int rem)
{
    if(i>=n+1)return 0;
    if(dp[i][rem]!=-1)return dp[i][rem];
    ll value = 1e17;
    if(rem>0)value = f(i+1 , rem-1);
    value = min(value , f(ar[i].second+1 , rem)+ar[i].first);
    return dp[i][rem] = value;
}

int main(void)
{
    scanf("%d %d %d",&n , &m , &k);
    for(int i=0;i<k;i++){

        int in1 , in2 , in3 , in4;
        scanf("%d %d %d %d",&in1 , &in2 , &in3 , &in4);
        v1[in1].push_back({in4 , in3});
        v2[in2].push_back({in4 , in3});
    }
    multiset<pair<int , int> >st;

    for(int i=1;i<=n;i++){

        for(int j=0;j<v2[i-1].size();j++){
            st.erase(st.find(v2[i-1][j]));
        }
        for(int j=0;j<v1[i].size();j++){
            st.insert(v1[i][j]);
        }

        if(st.size()==0)ar[i] = {0 , i};
        else{
            auto it = st.end();
            it--;
            ar[i] = *it;
        }
    }
    memset(dp , -1 , sizeof(dp));
    printf("%lld\n",f(1 , m));

    return 0;
}