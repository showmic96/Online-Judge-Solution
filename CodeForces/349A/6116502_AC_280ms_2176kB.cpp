#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(void)
{
    long long a,c=0,d=0;
    cin >> a;bool y=false;
    for(long long b=0;b<a;b++){
        int in;
    cin >> in;
    if(in==25)c+=25;
    if(in==50){c-=25;d+=50;}
    if(in==100){
        if(d>=50){d-=50;c-=25;}
        else c-=75;
    }
    if(c<0)y=true;

    }
    if(y==true)cout << "NO" << endl;
    else cout << "YES" << endl;

    return 0;
}
