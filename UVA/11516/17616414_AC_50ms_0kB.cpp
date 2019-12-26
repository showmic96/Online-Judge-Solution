// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n , m;
vector<double>v;

bool possible(double range)
{
    double last = -1e9;
    ll t = n;

    for(int i=0;i<m;i++){

        if(v[i]>last){

            last = v[i]+2*range;
            t--;
        }
    }
    if(t<0)return false;
    return true;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        scanf("%lld %lld",&n , &m);
        v.clear();
        for(int i=0;i<m;i++){

            ll in;
            scanf("%lld",&in);
            v.emplace_back(in);
        }
        sort(v.begin() , v.end());
        int lim = 100;
        double hi = 1e9 , low = 0 , mid , ans = -1;

        while(lim--){

            mid = (hi+low)/2.0;
            if(possible(mid)==true){

                ans = mid;
                hi = mid;
            }
            else low = mid;
        }

        printf("%.1f\n",ans);
    }
    return 0;
}
