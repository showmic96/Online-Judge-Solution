// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    while(cin >> n){

        if(!n)break;
        int sum = 0;
        for(int i=1;i<n;i++){

            for(int j=i+1;j<=n;j++){

                sum+=__gcd(i , j);
            }
        }
        cout << sum << endl;
    }

    return 0;
}
