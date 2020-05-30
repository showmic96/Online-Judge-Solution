// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 207;
vector<int>v[MAX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        for(int i=0;i<MAX;i++){
            v[i].clear();
        }
        int n;
        cin >> n;
        for(int i=0;i<n;i++){
            int in;
            cin >> in;
            v[in].push_back(i);
        }
        int ans = 1;
        for(int i=0;i<MAX;i++){
            if(v[i].size()==0)continue;
            int l = 0 , r = v[i].size()-1;
            while(l<r){
                for(int j=0;j<MAX;j++){
                    if(v[j].size()==0)continue;
                    int tot = upper_bound(v[j].begin(), v[j].end(), v[i][r]-1) - lower_bound(v[j].begin(), v[j].end(), v[i][l]+1);
                    ans = max(ans , 2*(l+1)+tot);
                }
                l++;r--;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
