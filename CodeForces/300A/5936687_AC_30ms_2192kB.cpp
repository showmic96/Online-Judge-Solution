#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(void)
{
    ll a ;
    cin >> a;
   ll ar[a];ll c=0,d=0;
    for(ll b=0;b<a;b++){cin >> ar[b];if(ar[b]<0)c++;if(ar[b]>0)d++;}
    sort(ar,ar+a);
    cout << 1 << " " << ar[0] << endl;
    if(c%2!=0&&c>1){
        cout << 2 << " "<< ar[1] <<" " <<ar[2] << endl;
        cout << a-3 <<" " ;for(ll b=3;b<a;b++)cout <<  ar[b] << " ";cout << endl;
    }
    else if(c%2==0&&ar[a-1]==0)
        {

        cout << a-3 <<" " ;for(ll b=2;b<a-1;b++)cout <<  ar[b] << " ";cout << endl;
        cout << 2 << " "<< ar[a-1] << " " << ar[1] <<endl;//" " <<ar[2] << endl;
    }
    else {
        {
        cout << 1 << " "<< ar[a-1] <<endl;//" " <<ar[2] << endl;
        cout << a-2 <<" " ;for(ll b=1;b<a-1;b++)cout <<  ar[b] << " ";cout << endl;
    }
    }

    return 0;

}
