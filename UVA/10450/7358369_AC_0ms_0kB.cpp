#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll FIB[100];

ll fibo(ll a)
{
    if(FIB[a])return FIB[a];

    return FIB[a] = fibo(a-1)+fibo(a-2);
}

int main(void)
{
    FIB[1] = 2;
    FIB[2] = 3;

    ll a , in;
    cin >> a;

    for(int i=0;i<a;i++){

        cin >> in;
        printf("Scenario #%d:\n",i+1);
        cout << fibo(in) << endl;
        cout << endl;
    }

    return 0;
}
