// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(void)
{
    int t , c = 0;

    scanf("%d",&t);
    while(t--){

        ll n , h , t1 , t2;
        scanf("%lld %lld %lld %lld",&n , &h , &t1, &t2);

        vector<ll>v;

        for(int i=0;i<n;i++){

            ll in;
            scanf("%lld",&in);
            v.push_back(in);
        }

        sort(v.begin() , v.end());

        int l = 0 , r = v.size()-1;
        ll ans = 0;

        if(2*t1<=t2)printf("Case %d: %lld\n",++c , t1*n);
        else{

            ll counter = 0;

            while(l<r){

                if(v[l]+v[r]<h){

                    l++;
                    r--;
                    ans+=t2;
                    counter+=2;
                }
                else{

                    ans+=t1;
                    r--;
                    counter++;
                }
            }

            ans+=(n-counter)*t1;

            printf("Case %d: %lld\n",++c , ans);
        }
    }

    return 0;
}
