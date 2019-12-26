#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{

    ll a;
    cin >> a;

    vector<int>ar;
    ar.clear();

    if(a==1){
        cout << a << endl;
        return 0;
    }
    if(a==0){

        cout << 10 << endl;
        return 0;
    }

    for(int i=9;i>=2;i--){

        while(a%i==0){
            ar.push_back(i);
            a/=i;
            //cout << i << endl;
        }

        if(a==1)break;
    }

    int si = ar.size();
    sort(ar.begin() ,ar.end());
    if(a!=1)cout << -1 << endl;
    else {

        for(int i=0;i<si;i++)cout << ar[i];
        cout << endl;
    }

    return 0;
}
