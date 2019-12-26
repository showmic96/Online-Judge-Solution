// In the name the Allah the Most Merciful.

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

        int n , ans = -1;
        cin >> n;

        for(int i=1;i<=100000;i++){

            ll now = n*i;
            if(now%180==0){

                now/=180;
                if(now>i-2)continue;
                ans = i;
                break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
