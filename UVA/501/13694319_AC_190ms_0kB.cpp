// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll>v , ans;

int main(void)
{
    int t;
    scanf("%d",&t);
    bool blank = false;

    while(t--){

        if(blank)printf("\n");blank = true;

        v.clear();ans.clear();

        int n , m;
        scanf("%d %d",&n , &m);

        for(int i=0;i<n;i++){

            ll in;
            scanf("%lld",&in);
            v.push_back(in);
        }

        int last = 0;
        for(int i=0;i<m;i++){

            ll in;
            scanf("%lld",&in);

            while(ans.size()<in){

                vector<ll>::iterator it = lower_bound(ans.begin() , ans.end() , v[last]);
                ans.insert(it , v[last]);
                last++;
            }
            printf("%lld\n",ans[i]);
        }
    }
    return 0;
}
