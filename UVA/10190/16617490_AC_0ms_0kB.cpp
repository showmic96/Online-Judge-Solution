// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll n , m;
    while(scanf("%lld %lld",&n , &m)==2){

        vector<ll>v;
        if(m!=0)while(n%m==0){
            if(n==0||m==0)break;
            if(n==1||m==1)break;
            v.push_back(n);
            n/=m;
        }

        if(n!=1||v.size()==0)printf("Boring!\n");
        else{

            v.push_back(1);
            for(int i=0;i<v.size();i++){

                if(i>0)printf(" ");
                printf("%lld",v[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
