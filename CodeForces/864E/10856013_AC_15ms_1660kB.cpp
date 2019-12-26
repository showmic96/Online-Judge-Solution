// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct item{

    ll t , d , p , idx;

    item(ll _t, ll _d , ll _p , ll _idx){

        t = _t;
        d = _d;
        p = _p;
        idx = _idx;
    }
};

bool operator<(item A , item B)
{
    return A.d<B.d;
}

vector<item>v;
set<ll>st;
vector<ll>ans;
int n;
ll dp[105][2005];


ll f(int i , int j)
{
    if(i==n)return 0;

    if(dp[i][j]!=-1)return dp[i][j];

    ll value1 = 0 , value2 = 0;

    if(j+v[i].t<v[i].d){

        value1 = f(i+1 , j+v[i].t)+v[i].p;
    }

    value2 = f(i+1 , j);

    return dp[i][j] = max(value1 , value2);
}

void print(int i , int j)
{
    if(i>=n)return ;

    int pos = f(i , j);

    if(f(i+1 , j)==pos){

        print(i+1, j);
    }

    else{

        ans.push_back(v[i].idx);
        print(i+1 , j+v[i].t);
    }
}

int main(void)
{
    memset(dp , -1 , sizeof(dp));

    scanf("%d",&n);
    for(int i=0;i<n;i++){

        ll in1 , in2 , in3;
        scanf("%lld %lld %lld",&in1 , &in2 , &in3);

        v.push_back(item(in1 , in2 , in3 , i+1));
    }

    sort(v.begin() , v.end());

    memset(dp , -1 , sizeof(dp));

    printf("%lld\n",f(0 , 0));

    print(0 , 0);

    int si = ans.size();
    printf("%d\n",si);
    for(int i=0;i<si;i++){

        printf("%lld ",ans[i]);
    }

    printf("\n");

    return 0;
}
