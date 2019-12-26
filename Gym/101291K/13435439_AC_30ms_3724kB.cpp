// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string ar[55];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ar[6] , br[6];
    for(int i=0;i<6;i++)cin >> ar[i];
    for(int i=0;i<6;i++)cin >> br[i];

    double win = 0 , total = 0;

    for(int i=0;i<6;i++){

        for(int j=0;j<6;j++){

            if(ar[i]>br[j])win++;
            else if(ar[i]==br[j])continue;
            total++;
        }
    }

    printf("%.5f\n",win/total);

    return 0;
}
