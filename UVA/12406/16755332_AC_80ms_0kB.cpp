// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll p , q;
set<ll>st;

void f(int i , ll val)
{
    if(i==p){

        ll now = (1LL<<q);
        if(val%now==0)st.insert(val);
        return ;
    }

    f(i+1 , val*10+1);
    f(i+1 , val*10+2);
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        scanf("%lld %lld",&p , &q);
        st.clear();

        f(0 , 0);

        vector<ll>v;
        for(auto it=st.begin();it!=st.end();it++)v.push_back(*it);

        if(v.size()==0)printf("Case %d: impossible\n",++c);
        else if(v.size()==1)printf("Case %d: %lld\n",++c , v[0]);
        else printf("Case %d: %lld %lld\n",++c , v[0] , v[v.size()-1]);
    }
    return 0;
}
