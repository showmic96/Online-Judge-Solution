// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    while(t--){

        string ar , ans;
        cin >> ar;
        ans = ar;

        int si = ar.size();

        for(int i=0;i<si;i++){

            ar+=ar[0];
            ar.erase(ar.begin());

            if(ar<ans)ans = ar;
        }

        cout << ans << endl;
    }
    return 0;
}
