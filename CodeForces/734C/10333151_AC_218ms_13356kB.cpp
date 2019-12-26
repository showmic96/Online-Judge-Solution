// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct myStruct{

    ll a , b;

    myStruct(ll _a , ll _b){

        a = _a;
        b = _b;
    }
};

bool cmp(myStruct A , myStruct B)
{
    return A.b < B.b;
}

int main(void)
{
    ll n , m , k , x , s;
    scanf("%lld %lld %lld",&n , &m , &k);
    scanf("%lld %lld",&x , &s);

    vector<myStruct>v1 , v2;

    for(int i=0;i<m;i++){

        ll in;
        scanf("%lld",&in);
        v1.push_back(myStruct(in , 0));
    }

    for(int i=0;i<m;i++){

        ll in;
        scanf("%lld",&in);
        v1[i].b = in;
    }

    v2.push_back(myStruct(0 , 0));

    for(int i=0;i<k;i++){

        ll in;
        scanf("%lld",&in);
        v2.push_back(myStruct(in , 0));
    }

    v2.push_back(myStruct(1e19 , 1e19));

    for(int i=0;i<k;i++){

        ll in;
        scanf("%lld",&in);
        v2[i].b = in;
    }

    vector<ll>v;

    for(int i=0;i<k;i++){

        v.push_back(v2[i].b);
    }

    ll ans = 1e19;

    int idx = lower_bound(v.begin() , v.end() , s+1) - v.begin();
    ans = min((n-v2[idx].a)*x , ans);

    for(int i=0;i<m;i++){

        ll left = s - v1[i].b;
        ll time = v1[i].a;

        if(left<0)continue;

        ll n_temp = n;

        int idx = lower_bound(v.begin() , v.end() , left+1) - v.begin();
        n_temp -= v2[idx].a;
//cout << v2[idx].a << " " << time << endl;
        ans = min(ans , n_temp*time);
    }

    printf("%lld\n",ans);

    return 0;
}
