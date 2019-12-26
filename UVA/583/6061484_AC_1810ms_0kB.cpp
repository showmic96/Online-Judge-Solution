#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    long long a;
    while(cin >> a){
        if(!a)break;
        cout << a << " = ";
        if(a<0){cout << -1 << " x ";a=(-1)*a;}
        long long l=a;
        for(long long b=2;b*b<=l;b++){
            int j=0;
            while(a%b==0){
            cout << b ;
            a=a/b;
            if(a>1)cout << " x ";
            }
            if(a==1)break;
            //if(j==1)cout << " x ";
        }
        if(a>1) cout << a ;
        cout << endl;
    }
    return 0;
}
