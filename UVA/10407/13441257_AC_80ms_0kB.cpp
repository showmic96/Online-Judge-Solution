// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll n;
    while(scanf("%lld",&n)==1){

        if(!n)break;
        vector<ll>v , temp;
        v.push_back(n);

        while(scanf("%lld",&n)==1){

            if(n==0)break;
            v.push_back(n);
        }

        sort(v.begin() , v.end());

        for(int i=0;i<v.size()-1;i++){

            if(v[i+1]-v[i]>0)temp.push_back(v[i+1]-v[i]);
        }

        vector<ll>ans;

        for(int i=0;i<temp.size();i++){
            ans.push_back(temp[i]);
            for(int j=0;j<temp.size();j++){

                if(i==j)continue;
                ans.push_back(__gcd(temp[i] , temp[j]));
            }
        }

        if(ans.size()==0)ans.push_back(1);

        sort(ans.begin() , ans.end());

        printf("%lld\n",ans[0]);
    }
    return 0;
}
