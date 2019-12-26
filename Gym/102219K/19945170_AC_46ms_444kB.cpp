// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t , c = 0;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>v(n);
        for(auto &x:v)cin >> x;
        sort(v.begin() , v.end());
        long sum = 0 , ans = 0;
        for(int i=0;i<n;i++){
            if(v[i]>=sum){
                ans++;
                sum+=v[i];
            }
        }
        cout << "Case #" << ++c << ": " << ans << endl;
    }
    return 0;
}
