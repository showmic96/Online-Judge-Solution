#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 , MAX = 100010;
typedef long long ll;
typedef unsigned long long LL;



int main(void)
{
    int a , in;
    cin >> a;
    map<string,int>maping;
    string ar[a] , br , store;

    int hi = 0;

    for(int i=0;i<a;i++){

        cin >> ar[i];

        maping[ar[i]]++;

        if(maping[ar[i]]>hi){hi = maping[ar[i]];store =""; store = ar[i];}
    }

    cout << store << endl;

    return 0;
}
