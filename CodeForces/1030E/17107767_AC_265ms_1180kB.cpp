// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1505;

int n ;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;

    vector<int>v(n);

    for(int i=0;i<n;i++){

        ll in;
        cin >> in;
        v[i] = __builtin_popcountll(in);
    }

    ll odd = 0 , even = 1 , sum = 0;

    for(int i=0;i<n;i++){

        sum+=v[i];
        if(sum%2==0)even++;
        else odd++;
    }

    sum = even*(even-1)/2 + odd*(odd-1)/2;

    for(int i=0;i<n;i++){

        ll temp = 0 , mx = 0;

        for(int j=0;j<75;j++){

            if(i+j>=n)break;

            temp+=v[i+j];
            mx = max(mx , (ll)v[i+j]);
            if(temp%2==0&&2*mx>temp)sum--;
        }
    }

    cout << sum << endl;

    return 0;
}
