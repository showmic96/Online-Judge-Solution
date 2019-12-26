// In the name of Allah the Most Merciful .

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

ll p(ll a , ll b)
{
    ll ans = a;

    for(int i=0;i<b-1;i++){

        ans*=a;
    }

    return ans;
}

int main(void)
{
    //cout << p(2 , 2);
    ll a;
    while(cin >> a){

        if(!a)break;

        if(is_prime(abs(a))==true)cout << 1 << endl;
        else{

            if(a>0){
                bool check = false;
                ll store = 1;

                for(ll i=1;i*i<=a;i++){

                    for(ll j=1;j<=32;j++){

                        if(p(i , j)==a){check =true;store = j;break;}
                        if(p(i , j)>a)break;
                    }
                    if(check==true)break;
                }

                cout << store << endl;
            }

            else{

                bool check = false;
                ll store = 1;
                a = abs(a);
                for(ll i=1;i*i<=a;i++){

                    for(ll j=1;j<=32;j+=2){

                        //cout << p(i , j) << endl;
                        if(p(i , j)==a){check =true;store = j;break;}
                        if(p(i , j)>a)break;
                    }
                    if(check==true)break;
                }

                cout << store << endl;
            }

        }
    }
    return 0;
}
