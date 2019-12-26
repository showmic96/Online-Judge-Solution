// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string ar;
    cin >> ar;

    int si = ar.size();

    ll ans = 1;

    for(int i=1;i<si-1;i++){

        ll counter = 0;

        while(ar[i-1]-'0'+ar[i]-'0'==9&&ar[i-1]==ar[i+1]){

            counter++;
            i++;

            if(si==si-1)break;
        }

        if(counter%2==1){

            counter++;
            ans*=((counter/2)+1);
        }
    }

    printf("%lld\n",ans);

    return 0;
}
