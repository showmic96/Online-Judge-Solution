#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    long long a , b , c=0 , d=0;
    cin >> a;
    long long ar[a];
    for(b=0;b<a;b++) cin >> ar[b];
    sort(ar,ar+a);
    for(b=0;b<a-1;b++){
        if(ar[b+1]-ar[b]==1){d+=1;}
        if(d==1)if(ar[b+1]!=ar[b]&&ar[b+1]-ar[b]!=1){d=0;}
    }
    if(d>=2)cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}

