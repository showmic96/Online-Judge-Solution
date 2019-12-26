// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
short int dp[5005][5005][3];
vector<int>v[5005];

int f(int i, int last , int rem)
{
    if(rem<0)rem = 0;
    if(i==5001){

        if(rem==0)return 0;
        return -5005;
    }
    if(dp[i][last][rem]!=-1)return dp[i][last][rem];

    int value = f(i+1 , last , rem-v[i].size());
    if(last>=i)value++;

    for(int j=0;j<v[i].size();j++){
        value = max(value , f(i+1 , max(v[i][j] , last) , rem-(v[i].size()-1))+1);
    }
    return dp[i][last][rem] = value;
}

int main(void)
{
    int n , q;
    scanf("%d %d",&n , &q);
    for(int i=0;i<q;i++){
        int in1 , in2;
        scanf("%d %d",&in1 , &in2);
        v[in1].push_back(in2);
    }
    memset(dp , -1 , sizeof(dp));
    printf("%d\n",f(0 , 0 , 2)-1);
    return 0;
}
