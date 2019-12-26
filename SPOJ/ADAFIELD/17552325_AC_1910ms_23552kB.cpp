// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

multiset<ll>stx , sty;
multiset<ll>x , y;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        ll n , m , q;
        scanf("%lld %lld %lld",&n , &m , &q);

        stx.clear();sty.clear();x.clear();y.clear();
        x.insert(0);x.insert(n);y.insert(0);y.insert(m);
        stx.insert(n);sty.insert(m);

        while(q--){

            ll in1 , in2;
            scanf("%lld %lld",&in1 , &in2);

            if(in1==0){

                if(x.find(in2)!=x.end()){

                    printf("%lld\n",(*stx.rbegin())*(*sty.rbegin()));
                    continue;
                }

                auto it1 = --x.lower_bound(in2);
                auto it2 = x.upper_bound(in2);

                ll temp = (ll)*it2-(ll)*it1;
                ll t1 = in2-(ll)*it1;
                ll t2 = (ll)*it2-in2;

                stx.insert(t1);
                stx.insert(t2);
                x.insert(in2);

                auto it = stx.find(temp);
                stx.erase(it);
            }
            else{
                if(y.find(in2)!=y.end()){

                    printf("%lld\n",(*stx.rbegin())*(*sty.rbegin()));
                    continue;
                }
                auto it1 = --y.lower_bound(in2);
                auto it2 = y.upper_bound(in2);

                ll temp = (ll)*it2-(ll)*it1;
                ll t1 = in2-(ll)*it1;
                ll t2 = (ll)*it2-in2;

                sty.insert(t1);
                sty.insert(t2);
                y.insert(in2);

                auto it = sty.find(temp);
                sty.erase(it);
            }

            printf("%lld\n",(*stx.rbegin())*(*sty.rbegin()));
        }
    }
    return 0;
}
