// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool cmp(pair<ll , ll> A , pair<ll , ll> B)
{
    return A.first<B.first;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        ll n , m;
        scanf("%lld %lld",&n , &m);
        vector<pair<ll , ll > >v;
        set<ll>st;

        ll p , q , r , x , y , z;
        scanf("%lld %lld %lld %lld %lld %lld",&p , &q , &r , &x , &y , &z);


        for(ll i=1;i<=n;i++){

            ll now = (p*i*i+q*i+r)%1000007;
            v.push_back(make_pair(now , i));
        }

        for(int i=1;i<=m;i++){

            ll now = (x*i*i+y*i+z)%n + 1;
            st.insert(now);
        }

        if(n==1){

            printf("Case %d: 0\n",++c);
            continue;
        }
        else if(n==2){

            printf("Case %d: %lld\n",++c ,v[0].first*v[1].first);
            continue;
        }

        sort(v.begin() , v.end() , cmp);

        int counter = 0 , check = false , idx = -1;
        ll ans = 0;
        for(int i=0;i<v.size();i++){

            if(st.find(v[i].second)==st.end()){

                idx = i;
                break;
            }
        }

        for(int i=0;i<v.size();i++){

            if(i==idx)continue;
            ans+=v[i].first*v[idx].first;
        }

        printf("Case %d: %lld\n",++c , ans);
    }
    return 0;
}
