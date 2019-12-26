// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int n;
    scanf("%d",&n);
    vector<int>v , ar(n);
    ll temp = n , ans = 0;
    for(int i=2;i<=temp;i++){

        if(temp%i==0){

            //while(temp%i==0)temp/=i;
            v.emplace_back(i);
            v.emplace_back(n/i);
        }
    }
    for(auto &x : ar)scanf("%d",&x) , ans+=x;
    //if(temp>1)v.emplace_back(temp);

    for(auto now : v){
        for(int i=0;i<now;i++){
            ll temp = 0 , tot = 0;
            int j = i;
            while(j<n){
                temp+=ar[j];
                j+=now;
                tot++;
            }
            if(tot>2)ans = max(ans , temp);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
