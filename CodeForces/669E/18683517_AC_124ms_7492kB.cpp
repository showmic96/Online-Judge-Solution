// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;

typedef tree< pair<ll , ll>, null_type, less<pair<ll , ll> >, rb_tree_tag,
  tree_order_statistics_node_update> ordered_set;

struct s{
    ll a , b , c , d;
    s(ll _a , ll _b , ll _c , ll _d){
        a = _a;
        b = _b;
        c = _c;
        d = _d;
    }
};
vector<s>v;
bool cmp(s A , s B)
{
    return A.b < B.b;
}
bool cmp2(pair<int , int> A , pair<int , int> B)
{
    return A.first<B.first;
}
vector<pair<int , int> > ans;
int main(void)
{
    ordered_set st1 , st2;
    int q , c = 0;
    scanf("%d",&q);
    while(q--){
        ll in1 , in2 , in3;
        scanf("%lld %lld %lld",&in1 , &in2 , &in3);
        v.push_back(s(in1 , in2 , in3 , ++c));
    }
    for(int i=0;i<v.size();i++){

        if(v[i].a==1){
            st1.insert({v[i].c , v[i].b});
        }
        else if(v[i].a==2){
            st2.insert({v[i].c , v[i].b});
        }
        else{
            int t1 = st1.order_of_key({v[i].c , v[i].b+1}) - st1.order_of_key({v[i].c , 0});
            int t2 = st2.order_of_key({v[i].c , v[i].b+1}) - st2.order_of_key({v[i].c , 0});
            printf("%d\n",t1-t2);
        }
    }
    return 0;
}
