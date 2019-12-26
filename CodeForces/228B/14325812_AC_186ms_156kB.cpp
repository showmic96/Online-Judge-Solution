// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string ar[55] , br[55];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n1 , m1 , n2 , m2;
    cin >> n1 >> m1;

    for(int i=0;i<n1;i++)cin >> ar[i];

    cin >> n2 >> m2;

    for(int i=0;i<n2;i++)cin >> br[i];

    ll ans = 0 , x = 0 , y = 0;

    for(int i=-55;i<=55;i++){

        for(int j=-55;j<=55;j++){


            ll counter = 0;

            for(int k=0;k<n1;k++){

                for(int l=0;l<m1;l++){

                    int t1 = k+i;
                    int t2 = l+j;

                    if(t1>=0&&t1<n2&&t2>=0&&t2<m2){

                        if(ar[k][l]=='1'&&br[t1][t2]=='1')counter++;
                    }
                }
            }

            if(counter>ans){

                ans = counter;
                x = i;
                y = j;
            }
        }
    }

    cout << x << " " << y << endl;

    return 0;
}
