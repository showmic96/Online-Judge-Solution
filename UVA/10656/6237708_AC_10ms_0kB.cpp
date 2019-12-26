#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    long long a;
    while(cin >> a){

        if(!a)break;
        long long ar[a];
        for(long long b=0;b<a;b++)cin >> ar[b];
        long long d=0;

        while(ar[d]==0)d++;
        if(d<a)cout << ar[d];
        for(int b=d+1;b<a;b++)if(ar[b]!=0)cout << " " << ar[b];
        if(d==a)cout << 0;
        cout << endl;
    }
    return 0;
}
