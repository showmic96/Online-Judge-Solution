#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    int a;
    int j=0;
    while(cin >> a){
        j++;
        if(a<0)break;
        ll ar[12];
        int in ;
        ll current = a;
        for(int b=0;b<12;b++)cin >>ar[b];
        printf("Case %d:\n",j);
        for(int b=0;b<12;b++){
            cin >> in;
            if(b!=0)current+=ar[b-1];
            //current-=in;

            if(current-in<0){cout << "No problem. :(" << endl;}
            else {cout << "No problem! :D" << endl;current-=in;}
        }

    }

    return 0;
}
