// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ll n , tot = 0 , cnt = 0 , zero = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        ll in;
        cin >> in;
        if(in==0){
            zero++;
        }
        else if(in<0){
            tot+=abs(in+1);
            cnt++;
        }
        else{
            tot+=abs(in-1);
        }
    }
    if(cnt%2==1){
        if(zero){

        }
        else{
            tot+=2;
        }
    }
    cout << tot+zero << endl;

    return 0;
}
