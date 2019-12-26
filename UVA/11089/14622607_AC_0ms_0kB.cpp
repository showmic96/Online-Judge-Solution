#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;

    ll fib[88];
    fib[0] = 1;
    fib[1] = 2;

    for(int i=2;i<88;i++)fib[i] = fib[i-1]+fib[i-2];

    while(t--){

        ll n;
        cin >> n;

        bool check = false;
        string ans = "";
        for(int i=87;i>=0;i--){

            if(fib[i]<=n){

                check = true;
                ans+='1';
                n-=fib[i];
            }
            else if(check==true)ans+='0';
        }
        cout << ans << endl;
    }
    return 0;
}

