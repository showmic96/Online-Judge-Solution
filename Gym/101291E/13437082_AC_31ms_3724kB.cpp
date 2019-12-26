// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int n , k;
    scanf("%d %d",&n , &k);
    vector<ll>v;

    for(int i=0;i<n;i++){

        int in;
        scanf("%d",&in);
        v.push_back(in);
    }

    vector<int>temp;

    for(int i=0;i<k;i++){

        temp.push_back(v[i]);
    }

    ll ans = 0;
    ll now = 0;

    for(int i=0;i<n;i++){

        sort(temp.begin() ,temp.end());
        ans = ans+temp[0]+now;
        now+=temp[0];

        temp.erase(temp.begin());

        if(k<n){

            temp.push_back(v[k]);
            k++;
        }
    }

    printf("%lld\n",ans);

    return 0;
}
