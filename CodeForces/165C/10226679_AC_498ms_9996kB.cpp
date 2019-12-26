// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int k;
    string ar;
    cin >> k >> ar;

    vector<int>v;

    v.push_back(0);

    int si = ar.size();

    for(int i=1;i<=si;i++){

        v.push_back(v[i-1]+ar[i-1]-'0');
    }

    long long ans = 0;

    for(int i=0;i<si;i++){

        ans+= upper_bound(v.begin() + i + 1 , v.end() , v[i]+k) - lower_bound(v.begin() + i + 1 , v.end() , v[i]+k);
    }

    cout << ans << endl;

    return 0;
}
