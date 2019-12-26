// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5;
ll money[MAX+9] , bike[MAX+9];
ll n , m , a;

bool cmp(ll a , ll b)
{
    return a>b;
}

bool is_possible(int x)
{
    int i = (m-x) , d = 0;

    ll sum = 0;

    for(;i<m;i++){

        if(d<n){

            ll temp = bike[i] - money[d];

            sum+= max((ll)0 , temp);
            d++;
        }

        else sum+=bike[i];
    }

    if(sum<=a)return true;
    return false;
}

int main(void)
{
    cin >> n >> m >> a;

    for(int i=0;i<n;i++)cin >> money[i];
    for(int i=0;i<m;i++)cin >> bike[i];

    sort(money , money+n , cmp);
    sort(bike , bike+m , cmp);

    ll hi = min(n , m) , low = 1 , mid , t = 200 , ans = -1;

    while(t--){

        mid = (hi+low)/2;

        if(is_possible(mid)==true){

            low = mid+1;
            ans = mid;
        }

        else{

            hi = mid-1;
        }
    }

    if(ans==-1){cout << "0 0" << endl;return 0;}

    sort(bike , bike+m);
    ll sum = 0;

    for(int i=0;i<ans;i++)sum+=bike[i];

    cout << ans << " " << max((ll)0 , sum - a) << endl;

    return 0;
}
