// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n , q;


int main(void)
{
    int t;
    scanf("%d",&t);

    for(int i=0;i<t;i++){


        cin >> n >> q;

        vector<ll>ar;
        vector<ll>::iterator it1 , it2;
        ll in;

        for(int j=0;j<n;j++){scanf("%lld",&in);ar.push_back(in);}
        printf("Case %d:\n",i+1);
        while(q--){

            ll in1 , in2;
            scanf("%lld %lld",&in1 , &in2);

            it1 = lower_bound(ar.begin() , ar.end() , in1);
            it2 = upper_bound(ar.begin() , ar.end() , in2);

            //if(it2==ar.end())it2--;

            printf("%d\n",it2 - it1);
        }
    }

    return 0;
}
