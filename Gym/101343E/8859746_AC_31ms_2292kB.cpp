// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    string ar;
    cin >> ar;

    ll si =ar.size() , mx=0;
    map<char ,ll>mp;
    set<char>data;
    set<char>::iterator it;
    vector<int>check;

    for(int i=0;i<si;i++){

        mp[ar[i]]++;
        data.insert(ar[i]);

        if(mp[ar[i]]>mx)mx = mp[ar[i]];
    }

    ll min1 = 0 , min2 = 0 , mx_t = mx;

    for(it = data.begin();it!=data.end();it++){

        if(mp[*it]>1)check.push_back(mp[*it]);
    }

    check.push_back(2);

    si = check.size();

    min1 = 123456789011121314;

    sort(check.begin() , check.end());

    for(int i=2;i<=mx_t;i++){

        min2 = 0;

        for(it = data.begin();it!=data.end();it++){

            min2+= (mp[*it]%i)*mp[*it];
        }

        if(min2<min1){

            min1 = min2;
            mx = i;
        }
    }


    cout << max((ll)2 , mx) << endl;

    return 0;
}
