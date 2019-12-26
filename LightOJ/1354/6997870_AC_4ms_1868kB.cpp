#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll decimal(ll a)
{
    ll ans = 0;

    int multiply = 0;

    while(a!=0){

        ans+=((a%10)*pow(2,multiply));
        multiply+=1;
        a/=10;
    }

    //cout << ans << endl;

    return ans;
}

int main(void)
{
    int a;
    cin >> a;

    ll a1 , a2 , a3 , a4 , b1 , b2 , b3 , b4;

    for(int i=0;i<a;i++){

        scanf("%lld.%lld.%lld.%lld",&a1,&a2,&a3,&a4);
        scanf("%lld.%lld.%lld.%lld",&b1,&b2,&b3,&b4);

        printf("Case %d: ",i+1);

        if(a1==decimal(b1)&&a2==decimal(b2)&&a3==decimal(b3)&&a4==decimal(b4))cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
