// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll>v;
ll n , m;

ll f(int i , int len , ll val)
{
    if(val>n)return 0;
    if(i==v.size()){

        if(len==0)return n;
        if(len%2)return -n/val;
        return n/val;
    }

    return f(i+1 , len , val) + f(i+1 , len+1 , val*v[i]/__gcd(val , v[i]));
}

int main(void)
{
    while(scanf("%lld %lld",&n , &m)==2){

        v.clear();
        for(int i=0;i<m;i++){

            ll in;
            scanf("%lld",&in);
            v.emplace_back(in);
        }

        printf("%lld\n",f(0 , 0 , 1));
    }
    return 0;
}
