// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll>ans;

ll p(ll n , ll lim)
{
    ll now = 1;
    for(int i=0;i<lim;i++){
        now*=n;
    }
    return now;
}
ll sod(ll n)
{
    ll result = 0;
    for (ll i=2; i*i<=n; i++)
    {
        if (n%i==0)
        {
            if (i==(n/i))
                result += i;
            else
                result += (i + n/i);
        }
    }
    return (result + 1);
}
void pre()
{
    for(int i=2;i<=25;i++){
        ll now = p(2 , i-1)*(p(2, i)-1);
        if(now>p(2, 33))break;
        if(sod(now)==now)ans.push_back(i);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    pre();
    int n;
    string ar;
    cin >> n >> ar;
    stringstream ss(ar);
    for(int i=0;i<n;i++){
        char x;
        ll now;
        if(i>0)ss >> x;
        ss >> now;
        if(binary_search(ans.begin() , ans.end() , now)==true)cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
