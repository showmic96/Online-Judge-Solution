#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<string>

using namespace std;

int main(void)
{   long long a , b , c , d , e ,f;
    cin >> a;
    for(b=0;b<a;b++){
        cin >> c;
        if(c%2==0) cout << c/2 << " " << c/2 << endl;
        else cout << (c/2)+1 << " " << c/2 << endl;
    }

    return 0;
}
