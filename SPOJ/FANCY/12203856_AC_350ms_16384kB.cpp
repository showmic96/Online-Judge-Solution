// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll p(int n)
{
    ll ans = 1;
    for(int i=0;i<n;i++){
        ans*=2;
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        string ar;
        cin >> ar;

        int si = ar.size();

        ll ans = 1;
        ll counter = 0;
        char last = 'x';

        for(int i=0;i<si;i++){

            if(ar[i]!=last){

                ans*=p(counter);
                counter = 0;
                last = ar[i];
            }

            else counter++;
        }

        ans*=p(counter);

        cout << ans << endl;
    }

    return 0;
}
