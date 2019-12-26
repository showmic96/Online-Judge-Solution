#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int a , b;

    while(cin >> a >> b){

        if(!a&&!b)break;

        if(a==2)b=31+b;
        if(a==3)b=31+29+b;
        if(a==4)b=31+29+31+b;
        if(a==5)b=31+29+31+30+b;
        if(a==6)b=31+29+31+30+31+b;
        if(a==7)b=31+29+31+30+31+30+b;
        if(a==8)b=31+29+31+30+31+30+31+b;
        if(a==9)b=31+29+31+30+31+30+31+31+b;
        if(a==10)b=31+29+31+30+31+30+31+31+30+b;
        if(a==11)b=31+29+31+30+31+30+31+31+30+31+b;
        if(a==12)b=31+29+31+30+31+30+31+31+30+31+30+b;

        if(b%7==1)cout << "Thursday" << endl;
        if(b%7==2)cout << "Friday" << endl;
        if(b%7==3)cout << "Saturday" << endl;
        if(b%7==4)cout << "Sunday" << endl;
        if(b%7==5)cout << "Monday" << endl;
        if(b%7==6)cout << "Tuesday" << endl;
        if(b%7==0)cout << "Wednesday" << endl;

    }

    return 0;
}
