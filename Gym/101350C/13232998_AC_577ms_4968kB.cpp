// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll>v;
int n;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        v.clear();

        scanf("%d",&n);
        ll sum = 0;
        for(int i=0;i<n;i++){

            ll in;
            scanf("%lld",&in);
            v.push_back(in);
            sum+=in;
        }
        sort(v.begin() , v.end());

        ll ans = 1;

        for(ll i=1;i*i<=v[0];i++){

            if(v[0]%i)continue;
            ll temp = v[0]/i;
            bool check = true;

            for(int j=0;j<n;j++){

                if(v[j]%temp!=0)check = false;
            }

            if(check){

                ans = max(ans, v[0]/i);
            }

            check = true;

            for(int j=0;j<n;j++){

                if(v[j]%i!=0)check = false;
            }

            if(check){

                ans = max(ans, i);
            }
        }

        printf("%lld %lld\n",sum , ans);
    }
    return 0;
}
