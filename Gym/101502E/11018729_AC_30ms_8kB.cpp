#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        int bed = 0 , liv = 0 , kit = 0;

        while(n--){

            string ar;
            cin >> ar;

            if(ar[0]=='b')bed++;
            else if(ar[0]=='k')kit++;
            else liv++;
        }

        bed/=2;

        cout << min(bed , min(liv , kit)) << endl;
    }

    return 0;
}
