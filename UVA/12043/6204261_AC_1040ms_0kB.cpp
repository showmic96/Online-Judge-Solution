#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

bool checkPrime(ll a)
{
    if(a==2)return true;
    if(a%2==0)return false;
    for(ll b=3;b<=sqrt(a);b++){

        if(a%b==0)return false;
    }
    return true;
}

void divisible(ll a , ll b , ll c)
{

    int j = 0; ll t = 0 , t1=0 , j1=0;
    int a1=a;
    while(a%c!=0)a++;
    for(;a<=b;a+=c){
    if(a==1&&c==1){j1+=1;t1+=1;continue;}

    j=0;t=0;
    bool check = false;

    for(ll k=2;k<=sqrt(a);k++)if(a%k==0){
          //  cout << k << endl;
            j++;t+=k;
            //if(checkPrime(a/k)==true){
           // cout << a/k << endl;
            if(k!=a/k){
            j++;
            t+=(a/k);
            }
            check = true;
          //  }
    }
    //if(check==true){
      j+=2;
      t+=1;
      t+=a;
      t1+=t;
      j1+=j;
     // cout << endl;
   // }

    }
    //if(a1==1 && b==1 && c==1){cout << 1 << " " << 1 << endl;}
    cout << j1 << " " << t1 << endl;

}

int main(void)
{
    ll a;
    cin >> a;
    while(a--){
        ll b , c , d;
        cin >> b >> c >> d;
        divisible(b,c,d);
    }
    return 0;
}
