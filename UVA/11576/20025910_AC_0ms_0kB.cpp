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
        int n , m , ans = 0;
        cin >> n >> m;
        string ar , br;
        for(int i=0 , j;i<m;i++){
            cin >> ar;
            if(i==0){
                ans+=ar.size();
                br = ar;
                continue;
            }
            for(j=0;j<n;j++){
                string s1 = br.substr(j);
                string s2 = ar.substr(0 , n-j);
                if(s1==s2){
                    ans+=j;
                    break;
                }
            }
            if(j==n)ans+=j;
            br = ar;
        }
        cout << ans << endl;
    }

    return 0;
}
