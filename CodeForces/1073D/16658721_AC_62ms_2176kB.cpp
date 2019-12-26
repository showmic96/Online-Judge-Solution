// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ll n , t , tot = 0 , ans = 0;
    cin >> n >> t;

    queue<ll>current;

    for(int i=0;i<n;i++){

        ll in;
        cin >> in;
        tot+=in;
        current.push(in);
    }

    while(current.empty()==false){

        ans+=(t/tot)*(ll)current.size();
        t = t%tot;
        int si = current.size();
        tot = 0;

        for(int i=0;i<si;i++){

            if(current.front()<=t){

                tot+=current.front();
                t-=current.front();
                current.push(current.front());
                current.pop();
                ans++;
            }
            else current.pop();
        }
    }

    cout << ans << endl;

    return 0;
}
