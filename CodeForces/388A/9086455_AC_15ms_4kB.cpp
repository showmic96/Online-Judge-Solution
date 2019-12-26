// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int ar[123];

int main(void)
{
    int n , ans=0;
    cin >> n;

    for(int i=0;i<n;i++)cin >> ar[i];

    sort(ar , ar+n);

    bool check = true;

    while(check){

        bool found = false;
        int sum = 0;
        for(int i=0;i<n;i++){

            if(ar[i]==-1)continue;
            found = true;

            if(ar[i]>=sum){

                sum++;
                ar[i] = -1;
            }
        }

        ans++;
        check = found;
    }

    cout << ans-1 << endl;

    return 0;
}
