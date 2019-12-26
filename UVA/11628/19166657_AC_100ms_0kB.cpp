// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int n , m;
    while(scanf("%d %d",&n , &m)==2){
        if(n==0&&m==0)break;
        vector<ll>v(n);
        ll sum = 0;
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                ll in;
                scanf("%lld",&in);
                if(i==m-1)v[j] = in , sum+=in;
            }
        }
        for(int i=0;i<n;i++){
            ll t1 = v[i];
            ll t2 = sum;
            ll gcd = __gcd(t1 , t2);
            if(t1==0)printf("0 / 1\n");
            else printf("%lld / %lld\n",t1/gcd , t2/gcd);
        }
    }
    return 0;
}
