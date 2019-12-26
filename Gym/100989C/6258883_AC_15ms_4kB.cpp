#include<iostream>
typedef long long ll;
using namespace std;

int main(void)
{
    ll a;
    ll in1 , in2;ll sum=0;
    cin >> a;
    for(ll b=0;b<a;b++){
        cin >> in1 >> in2;
        sum+=(in2-in1);
    }
    cout << sum << endl;

    return 0;
}