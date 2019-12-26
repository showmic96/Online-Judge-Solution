// In the name of Allah the most Merciful .

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pb push_back
#define ff first
#define ss second

typedef pair < int , int >  pii;

/**************************************/
pii egcd(int a,int b)
{
	if(b==0) return pii(1,0);
	else
	{
		pii d= egcd(b,a%b);
		return pii(d.ss,d.ff-(d.ss)*(a/b));
	}
}

ll gcd(ll a,ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
/**************************************/

int main(void)
{
    ll a , b ;
    pii c;
    while(cin >> a >> b){
        c = egcd(a , b);
        cout << c.first << " " << c.second << " " << gcd(a , b) << endl;
    }

    return 0;
}
