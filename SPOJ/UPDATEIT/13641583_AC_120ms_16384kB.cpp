// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ar[10005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        
        memset(ar , 0 , sizeof(ar));
        
        int n , q;
        cin >> n >> q;
        while(q--){

            int in1 , in2;
            ll in3;
            cin >> in1 >> in2 >> in3;

            ar[in1]+=in3;
            ar[in2+1]-=in3;
        }

        for(int i=1;i<=n;i++){

            ar[i]+=ar[i-1];
        }

        cin >> q;

        while(q--){

            int in;
            cin >> in;
            cout << ar[in] << endl;
        }
    }
    return 0;
}
