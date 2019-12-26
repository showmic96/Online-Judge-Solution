// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string ar[111];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){

        int n , m;
        cin >> n >> m;

        for(int i=0;i<n;i++)cin >> ar[i];

        int counter = 0;

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                if(ar[i][j]=='1')counter++;
            }
        }

        if(counter<2*n+2*(m-2)){

            cout << -1 << endl;
        }

        else{

            counter = 0;

            for(int i=0;i<m;i++){

                if(ar[0][i]=='1')counter++;
                if(ar[n-1][i]=='1')counter++;
            }

            for(int i=1;i<n-1;i++){

                if(ar[i][0]=='1')counter++;
                if(ar[i][m-1]=='1')counter++;
            }

            cout << 2*n+2*(m-2) - counter << endl;
        }
    }

    return 0;
}
