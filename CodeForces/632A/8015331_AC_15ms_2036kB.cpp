// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int n , p;
    cin >> n >> p;

    string ar[n];

    for(int i=0;i<n;i++)cin >> ar[i];

    double counter = 0 , total = 0;

    for(int i=n-1;i>=0;i--){

        if(ar[i]=="halfplus")counter+=0.5;

        total+=(counter*p);

        counter*=2;
    }

    cout << (ll)total << endl;

    return 0;
}
