// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll>v;

ll f(ll value)
{
    for(ll i=1;i<=200;i++){

        if(i*i*i==value)return i;
    }
}

int main(void)
{
    for(ll i=1;i<=200;i++){

        v.push_back(i*i*i);
    }

    for(ll i=2;i<=200;i++){

        for(ll j=2;j<=200;j++){

            for(ll k=j;k<=200;k++){

                ll temp = i*i*i - j*j*j - k*k*k;

                if(binary_search(v.begin() , v.end() , temp)){
	        if(f(temp)<k)break;
                    printf("Cube = %lld, Triple = (%lld,%lld,%lld)\n",i , j , k , f(temp));
                }
            }
        }
    }
    return 0;
}
