// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll a , b;
    cin >> a >> b;

    vector<ll>n1 , n2 , n3;

    while(a!=0){
        n1.push_back(a%2);
        a/=2;
    }

    while(b!=0){
        n2.push_back(b%2);
        b/=2;
    }

    while(n1.size()!=65)n1.push_back(0);
    while(n2.size()!=65)n2.push_back(0);

    reverse(n1.begin() , n1.end());
    reverse(n2.begin() , n2.end());

    bool check = false;
    ll ans = 0;
    for(int i=0;i<n1.size();i++){

        if(n1[i]!=n2[i])check=true;

        if(check==true){

            ans*=2;
            ans+=1;
        }
    }

    cout << ans << endl;

    return 0;
}
