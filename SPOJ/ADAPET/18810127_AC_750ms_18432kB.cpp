#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ar[500005];
int f(string s)
{
    int n = s.size();
    ar[0] = 0;

    int len = 0;

    int i = 1;
    while(i < n) {
        if(s[i] == s[len]) {
            len++;
            ar[i] = len;
            i++;
        }
        else{
            if(len!=0){
                len = ar[len-1];
            }
            else{
                ar[i] = 0;
                i++;
            }
        }
    }

    return ar[n-1];
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n;
        string ar;
        cin >> ar >> n;
        ll val = f(ar);
        ll left = ar.size()-val;
        ll ans = left*(n-1)+ar.size();
        cout << ans << endl;
    }
    return 0;
}
