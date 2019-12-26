// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int dp[81][(1<<9)+5] , n;
struct s{

    int a, b , c , w;
    s(int _a , int _b , int _c , int _w){

        a = _a;
        b = _b;
        c = _c;
        w = _w;
    }
};

vector<s>v;

int Set(int n , int pos)
{
    return n|(1<<pos);
}

bool Check(int n , int pos)
{
    return n&(1<<pos);
}

int f(int i , int mask)
{
    if(i==n){

        if(mask==(1<<9)-1)return 0;
        return -1e9;
    }
    if(dp[i][mask]!=-1)return dp[i][mask];
    int value = f(i+1 , mask);

    if(Check(mask , v[i].a)==false&&Check(mask , v[i].b)==false&&
       Check(mask , v[i].c)==false){

        int temp = Set(mask , v[i].a);
        temp = Set(temp , v[i].b);
        temp = Set(temp , v[i].c);

        value = max(value , f(i+1, temp)+v[i].w);
    }

    return dp[i][mask] = value;
}

int main(void)
{
    int c = 0;
    while(scanf("%d",&n)==1){

        if(n==0)break;
        v.clear();

        for(int i=0;i<n;i++){

            int in1 , in2 , in3 , in4;
            scanf("%d %d %d %d",&in1 , &in2 , &in3 , &in4);
            v.push_back(s(in1-1 , in2-1 , in3-1 , in4));
        }

        memset(dp , -1 , sizeof(dp));

        int ans = f(0 , 0);
        if(ans<0)ans = -1;
        printf("Case %d: %d\n",++c , ans);
    }
    return 0;
}
