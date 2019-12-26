// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int ar[1234][1234];

int main(void)
{
    int n , c = 0;
    while(cin >> n){

        if(!n)break;
        long long sum = 0;

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++)cin >> ar[i][j];
        }

        int t = (double)(1.00*ceil(1.00*n/2));
        int s = 0 , e = n;
        printf("Case %d:",++c);
        if(n%2==1)t--;
        while(t--){

            sum = 0;
            for(int i=s;i<e;i++){

                sum+=ar[s][i];
            }
            for(int i=s+1;i<e-1;i++){
                sum+=ar[i][s];
            }

            for(int i=s;i<e;i++){
                sum+=ar[e-1][i];
            }

            for(int i=s+1;i<e-1;i++){
                sum+=ar[i][e-1];
            }
            s++;
            e--;

            cout << " " << sum;
        }

        if(n%2==1)cout << " " << ar[s][e-1] << endl;
        else cout << endl;

    }
    return 0;
}
