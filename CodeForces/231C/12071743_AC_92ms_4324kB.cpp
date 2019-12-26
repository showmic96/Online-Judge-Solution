// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll>v;
ll n , k;
ll sum[100005];

bool possible(int i , int value , ll mid)
{
    ll counter = sum[i+1] - sum[i-mid+1];

    counter = mid*value-counter;

    if(counter<=k)return true;
    return false;
}

int bs(int i , int value)
{
    ll hi = i+1 , low = 1 , mid , t = 18 , ans = -1;

    while(t--){

        mid = (hi+low)/2;

        if(possible(i , value , mid)==true){

            ans = mid;
            low = mid+1;
        }

        else{

            hi = mid-1;
        }
    }

    return ans;
}

int main(void)
{
    memset(sum , 0 , sizeof(sum));

    scanf("%lld %lld",&n , &k);

    for(int i=0;i<n;i++){

        ll in;
        scanf("%lld",&in);
        v.push_back(in);
    }

    sort(v.begin() , v.end());

    for(int i=1;i<=n;i++){

        sum[i] = sum[i-1]+v[i-1];
    }

    ll ans = 0 , mx = 0;

    for(int i=0;i<n;i++){

        int temp = bs(i , v[i]);

        if(temp>mx){

            ans = v[i];
            mx = temp;
        }
    }

    printf("%lld %lld\n",mx , ans);

    return 0;
}
