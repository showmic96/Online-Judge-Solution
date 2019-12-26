// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n , c = 0;

    while(cin >> n){

        if(n==-1)break;

        string ar;
        cin >> ar;

        if(n==0)ar+="0" , n = 1;

        int si = ar.size() - 2;
        string temp = "";

        for(int i=0;i<n;i++){

            temp+=ar[ar.size()-i-1];
        }

        reverse(temp.begin() , temp.end());
        ar+=temp;
        ar+=temp;

        ll now = 0 , t = 0;
        for(int i=0;i<si;i++){

            now*=10;
            now+=ar[i+2]-'0';
        }

        for(int i=0;i<si-n;i++){

            t*=10;
            t+=ar[i+2]-'0';
        }

        ll neu = now - t;
        ll dem = pow(10 , si) - pow(10 , si-n);

        ll t1 = neu;
        ll t2 = dem;

        ll gcd = __gcd(t1 , t2);

        printf("Case %d: %lld/%lld\n",++c, t1/gcd , t2/gcd);
    }

    return 0;
}
