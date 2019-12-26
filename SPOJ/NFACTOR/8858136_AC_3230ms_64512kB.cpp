// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

map<int, int>mp;
vector<int>v[11];

typedef long long ll;

void pre_cal()
{
//cout << "YES";
    ll lim = 1000000+1000;
//cout << "YES";

    for(ll i=2;i<=lim;i++){

        for(ll j = 2;j*i<=lim;j++){

            if(mp[i]==0)mp[i*j]++;
        }

        if(mp[i]==0)mp[i] = 1;
    }

    for(int i=1;i<lim;i++){

        if(mp[i]<=10){

            v[mp[i]].push_back(i);
        }
    }
}

int main(void)
{
    pre_cal();
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
//cout << "YES";
        int in1 , in2 , in3;
        cin >> in1 >> in2 >> in3;
        vector<int>::iterator it1 , it2;

        it1 = lower_bound(v[in3].begin() , v[in3].end() , in1);
        it2 = upper_bound(v[in3].begin() , v[in3].end() , in2);

        cout << it2 - it1 << endl;
    }

    return 0;
}
