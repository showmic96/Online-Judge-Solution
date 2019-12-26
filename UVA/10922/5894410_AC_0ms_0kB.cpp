#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(void)
{
    char ar[10000];
    while(gets(ar)){ll b=0;
    if(ar[0]=='0')break;
        for(ll a =0;a<strlen(ar);a++){
            if(ar[a]=='1')b+=1;
                if(ar[a]=='2')b+=2;
                if(ar[a]=='3')b+=3;
                if(ar[a]=='4')b+=4;
                if(ar[a]=='5')b+=5;
                if(ar[a]=='6')b+=6;
                if(ar[a]=='7')b+=7;
                if(ar[a]=='8')b+=8;
                if(ar[a]=='9')b+=9;
                if(ar[a]=='0')b+=0;
        }
        ll c =0,e=b ,d=1;
        while(b>=10){
        c+=b%10;
        b=b/10;

        if(b<10){b=c;d++;c+=b;c=0;}

        }
        if(e%9==0)cout << ar << " " << "is a multiple of 9 and has 9-degree " << d << "."<< endl;
        else cout << ar << " is not a multiple of 9." << endl;
    }
    return 0;
}