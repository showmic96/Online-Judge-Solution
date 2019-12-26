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

        int n;
        string ar;
        cin >> n >> ar;

        if(n==2){

            if(ar[0]>=ar[1])cout << "NO" << endl;
            else{

                cout << "YES" << endl;
                cout << 2 << endl;
                cout << ar[0] << " " << ar[1] << endl;
            }
        }
        else{

            cout << "YES" << endl;
            cout << 2 << endl;
            cout << ar[0] << " ";
            for(int i=1;i<n;i++)cout << ar[i];
            cout << endl;
        }
    }

    return 0;
}
