// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

long double ar[5005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n, k;
    cin >> n >> k;
    ar[0] = 0;

    for(int i=1;i<=n;i++)cin >> ar[i];
    for(int i=1;i<=n;i++)ar[i] = ar[i] + ar[i-1];

    long double ans = 0;

    for(int i=1;i<=n;i++){

        for(int j=i+k-1;j<=n;j++){

            long double temp = ar[j] - ar[i-1];
            temp/=(long double)(j-i+1);
            ans = max(ans , temp);

        }
    }
    double fin = ans;
    printf("%.14f\n",fin);

    return 0;
}
