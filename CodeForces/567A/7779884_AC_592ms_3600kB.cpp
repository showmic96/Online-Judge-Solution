// In the name of Allah the most Merciful.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    ll ar[100100] , dis[100100] , n;
    cin >> n;
    dis[0] = 0;

    for(int i=0;i<n;i++){

        cin >> ar[i];
        if(i>0){
            dis[i] = abs(ar[i]-ar[i-1]) + dis[i-1];
        }

    }
    for(int i=0;i<n;i++){

        ll min1 = 1e19 , min2 = 1e19;

        if(i+1<n){

            min1 = dis[i+1] - dis[i];

        }
        if(i-1>=0)min2 = dis[i] - dis[i-1];

        cout << min(min1 , min2) << " ";

        min1 = 0 , min2 = 0;

        if(i+1==n){

            cout << dis[i] << endl;
        }

        else{

            min1 = dis[i];
            min2 = dis[n-1] - dis[i];
            cout << max(min1 , min2) << endl;
        }
    }
    return 0;
}
