// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll>v;
int n;

bool possible(ll mid)
{

    for(int i=0;i<n;i++){

        if(v[i+1]-v[i]>mid)return false;
        if(v[i+1]-v[i]==mid)mid--;
    }

    return true;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        v.clear();
        scanf("%d",&n);

        v.push_back(0);

        for(int i=0;i<n;i++){

            ll in;
            scanf("%lld",&in);
            v.push_back(in);
        }

        ll hi = 5e9 , low = 1 , ans = -1 , mid , t = 200;

        while(t--){

            mid = (hi+low)/2;

            if(possible(mid)==true){

                ans = mid;
                hi = mid-1;
            }
            else{

                low = mid+1;
            }
        }

        printf("Case %d: %lld\n",++c , ans);
    }
    return 0;
}
