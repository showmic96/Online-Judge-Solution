#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

#define si 1000010
bool prime[si+1];

void seive()
{
    for(ll a=0;a<si;a++)prime[a]=true;
    prime[0]=false;
    prime[1]=false;
    for(ll a=2;a<=sqrt(si);a++){

        for(ll b=2;b*a<=si;b++){

            if(prime[b]==true)prime[b*a]=false;
        }
    }
}

int main(void)
{
    seive();
    ll a , b , c;
    cin >> a;
    ll temp=0;
    ll ar[1000];
    while(a--){

        for(int j=0;j<1000;j++)ar[j]=0;
        cin >> b >> c;
        if(b<0)b=b*-1;
        if(c<0)c=c*-1;

        for(;b<=c;){
            temp = b + 1;
            if(prime[b]==true){
                //cout << b << endl;

                while(prime[temp]!=true)temp++;
                if(temp>c)break;
                ar[temp-b]++;
                //cout << temp << endl;
                //cout << temp-b << endl;
            }
            b=temp;
           // cout << b << endl;
        }
        bool check;
        int k=0,m=0 , y=0;
        for(int j=1;j<1000;j++){
           // cout << ar[j] << endl;
            //if(ar[j]>0)y++;
            if(ar[j]==k){check=true;}
            if(ar[j]>k){check = false;k=ar[j];m=j;}

        }
        if(check==false&&m>0)cout << "The jumping champion is " << m << endl;
        else cout << "No jumping champion" << endl;
    }
    return 0;
}
