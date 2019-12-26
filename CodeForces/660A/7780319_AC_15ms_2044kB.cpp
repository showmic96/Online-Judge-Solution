// In the name of Allah the most Merciful.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e5;

ll gcd(ll a , ll b)
{
    if(a%b==0)return b;
    return gcd(b , a%b);
}

int main(void)
{
    int n;
    cin >> n;
    int ar[n];

    for(int i=0;i<n;i++)cin >> ar[i];

    vector<int>ans;

    for(int i=0;i<n-1;i++){

        if(gcd(ar[i],ar[i+1])>1){

            ans.push_back(ar[i]);
            ans.push_back(1);
            //ans.push_back(ar[i+1]);
        }
        else{

            ans.push_back(ar[i]);
        }
    }
    ans.push_back(ar[n-1]);

    cout << ans.size() - n << endl;
    int si = ans.size();

    for(int i=0;i<si-1;i++)cout << ans[i]<< " ";
    cout << ans[si-1] << endl;

    return 0;
}
