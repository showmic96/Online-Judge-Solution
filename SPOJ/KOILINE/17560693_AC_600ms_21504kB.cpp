// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;

typedef tree< pair<ll ,ll> , null_type, less<pair<ll,ll> >, rb_tree_tag,
  tree_order_statistics_node_update> ordered_set;

int main(void)
{
    ordered_set st;
    int n , c = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){

        ll in;
        scanf("%lld",&in);
        st.insert({in , ++c});
    }

    vector<int>v(n);
    vector<ll>ans(n);

    for(int i=0;i<n;i++)scanf("%d",&v[i]);
    for(int i=0;i<n;i++){

        int now = v[n-i-1];
        ans[n-i-1] = st.find_by_order(now)->first;
        st.erase(st.upper_bound({ans[n-i-1] , -1}));
    }
    for(int i=0;i<n;i++)printf("%lld\n",ans[i]);

    return 0;
}
