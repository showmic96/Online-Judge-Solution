// In the name of Allah the Lord of the worlds .

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool is_prime(ll a)
{
    if(a==2)return true;
    if(a%2==0)return false;

    ll lim = sqrt(a);

    for(ll i=3;i<=lim;i+=2){

        if(a%i==0)return false;
    }

    return true;
}

bool prime[350];

void seive()
{
    for(int i=0;i<=310;i++)prime[i]=true;

    prime[0] = false;
    prime[1] = false;

    for(int i=2;i<=310;i++){

        for(int j=2;i*j<=310;j++){

            if(prime[i]==true)prime[i*j]=false;
        }
    }
}

int main(void)
{
    seive();

    ll a;

    cin >> a;
    ll a_temp = a;

    while(is_prime(a)==false)a--;

    if(a_temp==a){

        cout << 1 << endl;
        cout << a << endl;
    }

    else if(a_temp==a+2){

        cout << 2 << endl;

        cout << 2 << " " << a << endl;
    }

    else{

        a_temp = a_temp-a;

        cout << 3 << endl;

        for(int i=2;;i++){

            if(prime[i]==true&&prime[a_temp-i]==true){cout << i << " " << a_temp-i << " " << a << endl;break;}
        }
    }

    return 0;
}
