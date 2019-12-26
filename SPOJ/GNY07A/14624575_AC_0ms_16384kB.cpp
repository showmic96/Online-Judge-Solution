#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t , c = 0;
    cin >> t;

    while(t--){

        int n;
        string ar;
        cin >> n >> ar;

        ar.erase(ar.begin()+n-1);
        cout << ++c << " " << ar << endl;
    }
    return 0;
}

