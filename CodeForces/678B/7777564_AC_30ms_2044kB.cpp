// In the name of Allah the most Merciful.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool is_leapYear(ll n)
{
    if(n%400==0)return true;
    if(n%4==0&&n%100!=0)return true;
    return false;
}

int main(void)
{
    ll n , current = 0;

    /*for(int i=2000;i<=3000;i++){

        if(is_leapYear(i)==true)cout << i << endl;
    }*/

    cin >> n;

    if(is_leapYear(n)==true)while(true){

        if(is_leapYear(n)==true)current+=366;
        else current+=365;
        n++;
        if(current%7==0&&is_leapYear(n)==true)break;
    }

    else while(true){

        if(is_leapYear(n)==true)current+=366;
        else current+=365;
        n++;
        if(current%7==0&&is_leapYear(n)==false)break;
    }

    cout << n << endl;

    return 0;
}
