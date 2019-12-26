// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll INF = 1e12+101;
vector<ll>v , ans;
set<ll>st;
set<ll>::iterator it;
int si;

void f(ll value)
{
    if(value>INF)return ;
    v.push_back(value);

    f(value*10+4);
    f(value*10+7);
}

void f2(int i , ll value)
{
    if(i>=si)return ;
    if(value>INF)return ;
    if(value>1)st.insert(value);

    if(INF/v[i]>=value)f2(i , value*v[i]);
    if(INF/v[i]>=value)f2(i+1 , value);
    if(INF/v[i]>=value)f2(i+1 , value*v[i]);
}

int main(void)
{
    f(4);f(7);
    sort(v.begin() , v.end());
    si = v.size();

    f2(0 , 1);
    for(it=st.begin() ; it!=st.end();it++){

        ll temp = *it;
        ans.push_back(temp);
    }

    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        ll a , b;
        scanf("%lld %lld",&a , &b);

        printf("Case %d: %ld\n",++c , upper_bound(ans.begin() , ans.end() , b)-lower_bound(ans.begin() , ans.end() , a));
    }
    return 0;
}
