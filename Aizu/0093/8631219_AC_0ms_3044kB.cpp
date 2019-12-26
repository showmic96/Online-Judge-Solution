// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool is_lear_year(ll x)
{
    if(x%400==0)return true;
    if(x%100==0)return false;
    if(x%4==0)return true;
    return false;
}

int main(void)
{
    ll i1 , i2;
    bool space = false;
    while(cin >> i1 >> i2){

        if(!i1&&!i2)break;

        if(space)cout << endl;
        space = true;

        bool check = false;

        for(;i1<=i2;i1++){

            if(is_lear_year(i1)==true){cout << i1 << endl;check=true;}
        }

        if(check==false)cout << "NA" << endl;
    }
    return 0;
}
