// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll n;
    cin >> n;

    vector<int>v;

    int counter = 0;
    bool check = false;

    while(n!=0){

        if(n%10==0&&check==false){

            counter++;
        }
        else check = true;

        v.push_back(n%10);
        n/=10;
    }

    while(counter!=0){

        v.push_back(0);
        counter--;
    }


    check = true;

    for(int i=0;i<v.size()/2;i++){

        if(v[i]!=v[v.size()-i-1])check=false;
    }

    if(check==true)cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
