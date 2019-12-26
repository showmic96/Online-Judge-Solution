// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool found;
string ar;
ll need , cur;
map<ll , ll>par;


void f(ll now , ll add , ll pos , ll dir)
{
    //cout << "debug " << now << endl;
    cur = now;
    if(pos==ar.size())return ;
    if(found==true){

        if(ar[pos]=='L'){

            if(add==0)f(now , add , pos+1 , dir);
            else {
                par[now-add] = now;
                f(now-add , add/2 , pos+1 , 0);
            }
        }
        else if(ar[pos]=='R'){

            if(add==0)f(now , add , pos+1 , dir);
            else {
                par[now+add] = now;
                f(now+add , add/2 , pos+1 , 1);
            }
        }
        else{

            ll temp = par[now];
            f(temp , max(add , abs(temp-now)) , pos+1 , 2);
        }
    }
    else{

        if(now==need){

            found = true;
            f(now , add , pos , dir);
        }
        else if(need>now){
            par[now+add] = now;
            f(now+add , add/2 , pos , 1);
        }
        else{

            par[now-add] = now;
            f(now-add , add/2 , pos , 0);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ll n , q;
    cin >> n >> q;

    ll now = (n+1LL)/2;
    while(q--){

        found = false;
        cin >> need >> ar;
        par[now] = now;
        f(now , now/2 , 0 , 2);
        cout << cur << endl;
    }

    return 0;
}
