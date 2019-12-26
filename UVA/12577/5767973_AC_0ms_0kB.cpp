#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<string>

using namespace std;

int main(void)
{
    char a [100]; int b =1;
    while(cin >> a){
            if(a[0]=='*') break;
            else if(a[0]=='H') printf("Case %d: Hajj-e-Akbar\n",b);
            else printf("Case %d: Hajj-e-Asghar\n",b);
    b++;

    }

    return 0;
}
