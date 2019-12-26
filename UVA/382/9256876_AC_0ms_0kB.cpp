// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll div_sum[123456];

void sieve()
{
    for(int i=0;i<=60000;i++)div_sum[i] = 1;
    div_sum[1] = 0;
    for(ll i=2;i<=60000;i++){

        for(ll j=2;i*j<=60000;j++){

            div_sum[i*j]+=i;
        }
    }
}

int main(void)
{
    sieve();
    int n;

    cout << "PERFECTION OUTPUT" << endl;

    while(cin >> n){

        if(!n)break;

        printf("%5d  ",n);
        if(div_sum[n]==n)cout << "PERFECT" << endl;
        else if(div_sum[n]>n)cout << "ABUNDANT" << endl;
        else cout << "DEFICIENT" << endl;
    }

    cout << "END OF OUTPUT" << endl;
    return 0;
}
