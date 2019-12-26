// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5+9;

vector<pair<int , int> > v;

int dp[MAX+9];

int f(int i)
{
    if(i<0)return 0;
    if(dp[i]!=-1)return dp[i];

    int value = 0;

    int idx = lower_bound(v.begin() , v.end(), make_pair(v[i].first-v[i].second , 0)) - v.begin();

    value = f(idx-1)+1;

    return dp[i] = value;
}

int main(void)
{
    memset(dp , -1 , sizeof(dp));

    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){

        int in1 , in2;
        scanf("%d %d",&in1 , &in2);
        v.push_back(make_pair(in1 , in2));
    }

    sort(v.begin() , v.end());

    int ans = 0;

    for(int i=n-1;i>=0;i--){

        ans = max(ans , f(i));
    }

    printf("%d\n",n - ans);

    return 0;
}
