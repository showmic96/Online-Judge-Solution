// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 10005;
vector<int>v[MAX];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t , c = 0;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=0;i<MAX;i++)v[i].clear();
        for(int i=1;i<=n;i++){
            int in;
            cin >> in;
            v[in].push_back(i);
        }
        int q;
        cin >> q;
        while(q--){
            int l , r , lst = -1e6-5 , ans = 1e7;
            cin >> l >> r;
            for(int i=1;i<=10000;i++){
                int tot = upper_bound(v[i].begin() , v[i].end(),r)-lower_bound(v[i].begin() , v[i].end() , l);
                if(tot>1){ans = 0;break;}
                else if(tot==1){
                    ans = min(ans , i-lst);
                    lst = i;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}