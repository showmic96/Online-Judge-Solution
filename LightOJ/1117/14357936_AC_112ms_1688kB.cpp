// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll>v;
ll n , m , ans;

void f(int i , int counter , ll val)
{
    if(i==m){

        if(counter==0)return ;
        if(counter%2==0&&counter>1){

            ans-=n/val;
        }
        else {
            ans+=n/val;
        }
        return ;
    }

    f(i+1 , counter , val);

    ll temp = (val*v[i])/__gcd(val , v[i]);

    f(i+1 , counter+1 , temp);
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        v.clear();
        scanf("%lld %lld",&n , &m);
        for(int i=0;i<m;i++){

            ll in;
            scanf("%lld",&in);
            v.push_back(in);
        }

        ans = 0;
        f(0 , 0 , 1);
        printf("Case %d: %lld\n",++c , n-ans);
    }
    return 0;
}
