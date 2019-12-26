// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t , c = 0 ;
    cin >> t;
    while(t--){
        int n , m , ans = -1e8;
        cin >> n >> m;
        for(int i=0;i<n;i++){
            int f , t;
            cin >> f >> t;
            if(t<=m){
                ans = max(ans , f);
            }
            else{
                ans = max(ans , f-(t-m));
            }
        }
        cout << "Case #" << ++c << ": " << ans << endl;
    }

    return 0;
}
