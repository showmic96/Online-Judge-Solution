// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll x , a , d , m;

vector<pair < pair < ll , ll > , ll > > v , data;
map<pair < pair < ll , ll > , ll> , int>mp;

void f1(ll i , ll x1 , ll x2 , ll x3)
{
    if(i==m/2){

        v.push_back(make_pair(make_pair(x1 , x2) , x3));
        return ;
    }

    f1(i+1 , x1 , x2 , x3);
    f1(i+1 , x1+data[i].first.first ,x2+data[i].first.second , x3+data[i].second);
}

void f2(ll i , ll x1 , ll x2 , ll x3)
{
    if(i==m){

        mp[(make_pair(make_pair(x1 , x2) , x3))]=1;
        return ;
    }

    f2(i+1 , x1 , x2 , x3);
    f2(i+1 , x1+data[i].first.first ,x2+data[i].first.second , x3+data[i].second);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    while(t--){

        cin >> x >> a >> d >> m;

        v.clear();
        mp.clear();
        data.clear();

        for(int i=0;i<m;i++){

            string ar;
            ll in1 , in2 , in3;
            cin >> ar;
            cin >> in1 >> in2 >> in3;

            data.push_back(make_pair(make_pair(in1 , in2) , in3));
        }

        f1(0 , 0 , 0 , 0);
        f2(m/2 , 0 , 0 , 0);

        bool check = false;

        int si = v.size();

        for(int i=0;i<v.size();i++){

            ll x1 = v[i].first.first;
            ll x2 = v[i].first.second;
            ll x3 = v[i].second;

            if(x1==x&&x2==a&&x3==d)check = true;

            if(mp[make_pair(make_pair(x-x1 , a-x2) , d-x3)]==1)check = true;
        }

        if(mp[make_pair(make_pair(x , a) , d)]==true)check = true;

        if(check==true)cout << "POSSIBLE" << endl;
        else cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
