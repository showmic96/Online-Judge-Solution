// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int n;
    scanf("%d",&n);
    vector<ll>v;

    ll sum = 0;

    for(int i=0;i<n;i++){

        ll in;
        scanf("%lld",&in);
        v.push_back(in);
        sum+=in;
    }

    sort(v.begin() , v.end());
    if(v[n-1]>sum/2){

        cout << sum-v[n-1] << endl;
    }

    else cout << sum/2 << endl;
    return 0;
}
