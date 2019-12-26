// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n , m;
vector<int>v1 , v2;
ll dp[25][105];

ll f(int i , int rem)
{
    if(i==m){

        if(rem==n)return 1;
        return 0;
    }

    if(dp[i][rem]!=-1)return dp[i][rem];

    ll value = 0;

    for(int i1=v1[i];i1<=v2[i];i1++){

        if(rem+i1<=n)value+=f(i+1 , rem+i1);
    }

    return dp[i][rem] = value;
}

int main(void)
{
    while(cin >> m >> n){

        if(!n&&!m)break;
        v1.clear();v2.clear();

        for(int i=0;i<m;i++){

            int in1 , in2;
            cin >> in1 >> in2;

            v1.push_back(in1);
            v2.push_back(in2);
        }

        memset(dp , -1 , sizeof(dp));

        cout << f(0 , 0) << endl;
    }

    return 0;
}
