#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

bool isPrime(ll a)
{
    if(a==2)return true;
    if(a%2==0)return false;
    for(ll b = 3; b<=sqrt(a);b+=2){
        if(a%b==0)return false;
    }
    return true;
}

ll gcd(ll a , ll b)
{
    if(b==0)return a;
    else return gcd(b,a%b);
}

ll lcm(ll a , ll b , ll c)
{
    ll x = c/a;
    ll y = c/b;
   // bool check1 = false;
   // bool check2 = false;
    //int d = 2;
    /*while(a<=c&&b<=c){

        a=a*d;
        b=b*d;
        d++;
        //cout << a  << " " << b << endl;
        if(a==c)check1=true;
        if(b==c)check2=true;
    }*/

    if(isPrime(x)==true&&isPrime(y)==true)return c;
    else return 0;
}

void counter(ll ar[] , ll si , ll j , ll x)
{
    for(ll a=0;a<si-1;a++){

        for(ll b=a+1;b<si;b++){

            if((ar[a]*ar[b])/gcd(ar[a],ar[b])==x)j++;
        }
    }
    cout << x << " " << j << endl;
}

void isDivisible(ll a)
{
    ll ar[1000];
    int d = 0;
    int j = 0;
    for(ll b=2;b<=sqrt(a);b++){

        if(a%b==0){
            ar[d]=b;
            d++;
            if((a/b)!=b){ar[d]=(a/b);d++;j++;}
            j++;
        }
    }
    if(a>1)j+=2;
    else j++;

    counter(ar,d,j,a);
}

int main(void)
{
    ll a;
    while(cin >> a){

        if(!a)break;
        isDivisible(a);
    }
    return 0;
}
