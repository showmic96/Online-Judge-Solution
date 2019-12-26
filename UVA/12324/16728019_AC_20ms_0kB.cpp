// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n , dp[105][105];
vector<pair<int , int > >v;

int f(int i , int rem)
{
    if(i==n)return 0;
    if(rem>102)rem = 101;
    if(dp[i][rem]!=-1)return dp[i][rem];

    int value = f(i+1 , rem+v[i].second)+v[i].first;

    if(rem>0)value = min(value , f(i+1 , rem-1+v[i].second)+v[i].first/2);

    return dp[i][rem] = value;
}

int main(void)
{
    while(scanf("%d",&n)==1){

        if(n==0)break;
        v.clear();

        for(int i=0;i<n;i++){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);
            v.push_back(make_pair(in1 , in2));
        }

        memset(dp , -1 , sizeof(dp));

        printf("%d\n",f(0 , 0));
    }
    return 0;
}
