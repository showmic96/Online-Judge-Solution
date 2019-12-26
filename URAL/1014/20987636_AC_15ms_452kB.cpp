// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ll n;
    cin >> n;
    vector<int>v;
    if(n==1){
        cout << n << endl;
        return 0;
    }
    if(n==0){
        cout << 10 << endl;
        return 0;
    }
    for(int i=9;i>=2;i--){
        while(n%i==0){
            v.push_back(i);
            n/=i;
        }
        if(n==1)break;
    }
    int si = v.size();
    sort(v.begin() ,v.end());
    if(n!=1)cout << -1 << endl;
    else {
        for(int i=0;i<si;i++)cout << v[i];
        cout << endl;
    }

    return 0;
}
