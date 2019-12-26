// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int>v;

int main(void)
{
    int n;
    ll s;
    while(scanf("%d %lld",&n , &s)==2){

        v.clear();

        for(int i=0;i<n;i++){

            ll in;
            scanf("%lld",&in);
            v.push_back(in);

            if(i>0){

                v[i]+=v[i-1];
            }
        }

        int ans = 1e9;

        for(int i=0;i<n;i++){

            if(v[i]>s){

                int idx = lower_bound(v.begin() , v.end() , v[i]-s) - v.begin();
                ans = min(ans , i-idx+1);
            }
        }
        
        if(ans==1e9)ans = 0;

        printf("%d\n",ans);
    }
    return 0;
}
