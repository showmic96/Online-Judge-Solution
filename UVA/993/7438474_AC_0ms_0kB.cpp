// In the name of Allah the Lord of the worlds .

#include<bits/stdc++.h>
using namespace std;

int gcd(int a , int b)
{
    if(a==0)return b;
    return gcd(b%a , a);
}


typedef long long ll;

int main(void)
{
    ll a , in , b;
    vector<int>ans;
    cin >> b;

    while(b--){

        ans.clear();
        cin >> a;
        if(a==1){cout << 1 << endl;continue;}
        for(int i=9;i>=2;i--){

            while(a%i==0){ans.push_back(i);a/=i;if(a==0)break;}

            if(a==0)break;
        }

        int si = ans.size();
        sort(ans.begin() , ans.end());

        if(a>1)cout << -1 << endl;
        else{
        for(int i=0;i<si;i++)cout << ans[i];
        cout << endl;
        }
    }

    return 0;
}
