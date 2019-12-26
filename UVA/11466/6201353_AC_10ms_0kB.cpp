#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

bool prime(ll a)
{
    if(a%2==0)return false;
    ll b = sqrt((double)a);
    for(ll c=3;c<=b;c+=2){
        if(a%c==0)return false;
    }
    return true;
}

int main(void)
{
    ll a;
    while(cin >> a){

        if(!a)break;
        if(a<0)a=a*(-1);
        bool j =false;
        bool check = false;
        ll b;int uu=0;
        for(b=2;b<=sqrt(a);b++){
            check = false;
            while(a%b==0){
               // cout << a << endl;
                a=a/b;
                check = true;
                if(prime(a)==true&&(a!=b||uu>0)){j=true;break;}


            }
            //cout << a << endl;
            if(check==true)uu++;

            //cout << a << endl;
            //if(prime(a/b)==true){j=true;break;}
            if(j==true)break;
        }
        if(j==true&&(a)>2)cout << a << endl;
        else cout << -1 << endl;
    }
    return 0;
}
