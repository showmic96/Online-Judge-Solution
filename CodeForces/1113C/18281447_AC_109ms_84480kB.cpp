// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll o[5000005] , e[5000005];

int main(void)
{
    int n;
    scanf("%d",&n);
    vector<ll>v;
    for(int i=0;i<n;i++){

        ll in;
        scanf("%lld",&in);
        v.push_back(in);
    }
    ll ans = 0 , cur = 0;
    e[0]++;
    for(int i=0;i<n;i++){

        cur^=v[i];//cout << i << " " << cur << endl;
        if(i%2==0){
            ans+=o[cur];
            o[cur]++;
        }
        else{
            ans+=e[cur];
            e[cur]++;
        }

    }
    printf("%lld\n",ans);
    return 0;
}
