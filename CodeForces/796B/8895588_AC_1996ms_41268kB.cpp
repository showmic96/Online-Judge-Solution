// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll n , m , k , p = 1 , ans = 1;
    scanf("%lld %lld %lld",&n , &m ,&k);//cin >> n >> m >> k;
    map<ll,ll>mp;

    for(int i=0;i<m;i++){

        ll in;
        scanf("%lld",&in);//cin >> in;
        mp[in] = 1;
    }

    bool check = false;

    while(k--){

        ll in1 , in2;
        cin >> in1 >> in2;

        if(check==false)
        {

            if(mp[p]==1){check=true;ans = p;}

            if(in1==p){

                p = in2;
            }

            else if(in2==p) p = in1;
        }
    }

    if(check==true)printf("%lld\n",ans);//cout << ans << endl;
    else printf("%lld\n",p);//cout << p << endl;

    return 0;
}
