#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll rev_int(ll a)
{
    int ar[1000];
    int d=0;
    while(a>=10){

        ar[d]=a%10;
        d++;
        a=a/10;
    }
    ar[d]=a;
    ll sum=0;
    ll de = 1;
    for(int k=d;k>=0;k--){
        sum+=(ar[k]*de);
        de*=10;
    }

    return sum;

}

bool isPalindrome(ll a)
{
    int ar[1000];
    int d=0;
    while(a>=10){

        ar[d]=a%10;
        d++;
        a=a/10;
    }
    ar[d]=a;
    bool check = false;
    for(int b=0;b<=d/2;b++){

        if(ar[b]!=ar[d-b])return false;
    }
    return true;
}

void answer(ll a)
{
    int term = 0;
    ll k , j;
    while(isPalindrome(a)!=true){
        k = a;

        j = rev_int(a);

        a=j+k;
        term++;
    }
    cout << term << " " << a << endl;
}

int main(void)
{
   // ll a;
   // while(cin >> a){if(isPalindrome(a)==true)cout << "YES" << endl;cout << rev_int(a) << endl;}
    int a;
    cin >> a;
    while(a--){

        ll b;
        cin >> b;
        answer(b);
    }
    return 0;

}
