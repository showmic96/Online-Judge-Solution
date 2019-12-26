// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

set<int>st;
set<int>::iterator it;
vector<pair<int , int> > v;
map<int , int>mp;
int ar[100005];

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        st.clear();
        v.clear();
        mp.clear();
        memset(ar , 0 , sizeof(ar));

        int n;
        scanf("%d",&n);

        for(int i=0;i<n;i++){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);
            st.insert(in1);
            st.insert(in2);
            v.push_back(make_pair(in1 , in2));
        }

        int counter = 1;

        for(it = st.begin();it!=st.end();it++){

            mp[*it] = counter++;
        }

        for(int i=0;i<n;i++){

            ar[mp[v[i].first]]++;
            ar[mp[v[i].second]+1]--;
        }

        int ans = 0;

        for(int i=1;i<100005;i++){

            ar[i] = ar[i-1]+ar[i];
            ans = max(ans , ar[i]);
        }

        printf("Case %d: %d\n",++c , ans);
    }
    return 0;
}
