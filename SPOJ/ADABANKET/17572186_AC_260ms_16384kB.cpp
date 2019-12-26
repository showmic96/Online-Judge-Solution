// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n , ans = 1e9;
    cin >> n;
    for(int i=0;i<n;i++){

        int counter = 0;
        for(int j=0;j<n;j++){

            int in;
            cin >> in;
            if(in)counter++;
        }

        ans = min(ans , counter);
    }
    cout << ans*2 << endl;

    return 0;
}
