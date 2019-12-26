#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(void)
{
    long long a,b,c=0 ;
    cin >> a >>b;
    if(a%b==0){cout << a/b << endl;return 0;}
    while(a%b!=0){
        c+=(a/b);
        long long k = b;
        b=a%b;

        a=k;

    }
    c+=(a/b);
    cout << c << endl;
    return 0;
}
