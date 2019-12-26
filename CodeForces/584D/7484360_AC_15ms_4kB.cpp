// In the name of Allah the Lord of the worlds .

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool is_prime[250];

bool isPrime(ll a)
{
    if(a==2)return true;
    if(a%2==0)return false;

    ll si = sqrt(a);

    for(ll i=3;i<=si;i+=2){

        if(a%i==0)return false;
    }

    return true;
}

void seive()
{
    for(int i=0;i<=310;i++)is_prime[i] = true;

    is_prime[0] = false;
    is_prime[1] = false;

    for(int i=2;i<=310;i++){

        for(int j=2;j*i<=310;j++){

            if(is_prime[i]==true)is_prime[i*j] = false;
        }
    }
}

int main(void)
{
    int a;
    cin >> a;
    int a_temp = a;

    while(isPrime(a)==false)a--;

    if(a_temp==a){

        cout << 1 << endl;

        cout << a << endl;
    }

    else if(a_temp==a+2){

        cout << 2 << endl;

        cout << 2 << " " << a << endl;
    }

    else{
        seive();
        a_temp = a_temp - a;
        cout << 3 << endl;
        for(int i=2;;i++){

            if(is_prime[i]==true&&is_prime[a_temp-i]==true){cout << i << " " << a_temp-i << " " << a << endl;break;}
        }
    }

    return 0;
}
