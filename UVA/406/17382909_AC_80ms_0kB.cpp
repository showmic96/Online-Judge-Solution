// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool prime(ll x)
{
    if(x==2)return true;
    if(x%2==0)return false;

    for(ll i=3;i*i<=x;i+=2){

        if(x%i==0)return false;
    }
    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ll n , c;
    while(cin >> n >> c){

        vector<int>v;

        for(int i=1;i<=n;i++){

            if(prime(i)==true){

                v.push_back(i);
            }
        }

        while(v.size()>2*c){

            v.erase(v.begin());
            v.erase(v.begin()+v.size()-1);
        }

        cout << n << " " << c << ":";
        for(int i=0;i<v.size();i++)cout << " " << v[i];
        cout << endl << endl;
    }

    return 0;
}
