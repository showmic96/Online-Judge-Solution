// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n , ans = 1e9;
        cin >> n;
        int ar[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> ar[i][j];
            }
        }
        vector<int>v;
        for(int i=0;i<n;i++)v.push_back(i);
        do{
            int tot = 0;
            for(int i=0;i<n;i++){
                tot+=ar[i][v[i]];
            }
            ans = min(ans , tot);
        }while(next_permutation(v.begin() , v.end()));
        cout << ans << endl;
    }

    return 0;
}
