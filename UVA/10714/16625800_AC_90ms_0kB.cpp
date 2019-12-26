// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int tc , c = 0;
    scanf("%d",&tc);
    while(tc--){

        ll l , n , mx = 0 , mi = 0;
        scanf("%lld %lld",&l , &n);

        for(int i=0;i<n;i++){

            ll in;
            cin >> in;

            if(in>l-in)in = l-in;

            if(in>mi)mi = in;
            if(mx<l-in)mx = l-in;
        }

        printf("%lld %lld\n",mi , mx);
    }
    return 0;
}
