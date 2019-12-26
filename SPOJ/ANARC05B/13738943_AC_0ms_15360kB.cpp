// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ar[10005] , br[10005];
vector<ll>v1 , v2;
vector<pair<int , int> > v;
map<ll , ll > mp;

int main(void)
{
    int n , m;
    while(scanf("%d",&n)==1){

        if(n==0)break;
        mp.clear();
        v.clear();v1.clear();v2.clear();

        for(int i=0;i<n;i++){

            ll in;
            scanf("%lld",&in);
            v1.push_back(in);
            if(mp[in]==0)mp[in] = i+1;
        }

        scanf("%d",&m);

        for(int i=0;i<m;i++){

            ll in;
            scanf("%lld",&in);
            v2.push_back(in);

            if(mp[in]!=0){

                v.push_back(make_pair(mp[in] , i+1));
            }
        }

        ar[0] = br[0] = 0;

        for(int i=1;i<=n;i++)ar[i] = ar[i-1]+v1[i-1];
        for(int i=1;i<=m;i++)br[i] = br[i-1]+v2[i-1];

        int si = v.size();
        ll sum = 0;

        for(int i=0;i<si;i++){

            int t1 = v[i].first;
            int t2 = v[i].second;

            if(i==0){

                sum+=max(ar[t1] , br[t2]);
            }
            else{

                sum+=max(ar[t1]-ar[v[i-1].first] , br[t2]-br[v[i-1].second]);
            }
        }

        sum+=max(ar[n]-ar[v[si-1].first] , br[m]-br[v[si-1].second]);

        printf("%lld\n",sum);
    }
    return 0;
}
