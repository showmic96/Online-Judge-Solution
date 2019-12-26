// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAX = 10000000000;

int main(void)
{
    ll sum = 0;

    vector<ll>v;

    for(ll i=1;;i++){

        sum+=i;
        v.push_back(sum);

        if(sum>MAX){
            break;
        }
    }

    int t;
    scanf("%d",&t);

    bool space = false;

    while(t--){

        if(space)printf("\n");
        space = true;

        ll in;
        scanf("%lld",&in);
        in = abs(in);

        int idx = lower_bound(v.begin() , v.end() , in) - v.begin();

        for(int i=idx;;i++){

            if(v[i]>=in&&v[i]%2==1&&in%2==1){

                printf("%d\n",i+1);
                break;
            }

            if(v[i]>=in&&v[i]%2==0&&in%2==0){

                printf("%d\n",i+1);
                break;
            }
        }
    }

    return 0;
}
