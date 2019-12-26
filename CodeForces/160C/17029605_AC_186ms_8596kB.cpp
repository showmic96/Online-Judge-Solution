// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll>v;
vector<pair<ll , ll > > p;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ll n , k;
    cin >> n >> k;

    for(int i=0;i<n;i++){

        ll in;
        cin >> in;
        v.emplace_back(in);
    }

    sort(v.begin() , v.end());
    map<ll , ll>mp;

    for(int i=0;i<n;i++){

        mp[v[i]]++;
    }

    ll pre = 0 , sum = 0;

    for(auto it: mp){

        ll t1 = it.first;
        ll t2 = it.second;

        p.emplace_back(t1 , t2);
    }

    for(int i=0;i<p.size();i++){

        ll t1 = p[i].first;
        ll t2 = p[i].second;

        if(sum+pre*t2>=k){

            while(sum+pre*t2>=k)pre--;
            cout << t1 << ' ' << v[pre] << '\n';
            break;
        }
        else sum+=pre*t2;

        if(sum+t2*t2>=k){

            cout << t1 << ' ' << t1 << '\n';
            break;
        }
        else sum+=t2*t2;

        ll rem = n-pre-t2;

        if(sum+rem*t2>=k){

            while(sum+rem*t2>=k)rem--;
            cout << t1 << ' ' << v[pre+t2+rem] << '\n';
            break;
        }
        else sum+=rem*t2;

        pre+=t2;
    }

    return 0;
}
