// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool is_it(ll a)
{
    ll sum = 0;
    a = a*a;
    while(a!=0){

        int t = a%10;

        sum+=t;
        a/=10;
    }

    ll temp = sqrt(sum);

    if(temp*temp==sum)return true;
    return false;
}

int main(void)
{
    int n = 16;
    vector<ll>v;

    while(v.size()<7){

        if(is_it(n)==true){

            v.push_back(n);
        }
        else v.clear();
        n++;
    }

    for(int i=0;i<v.size();i++)printf("%lld %lld\n",v[i] , v[i]*v[i]);

    return 0;
}
