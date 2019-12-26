#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a;
    cin >> a;
    map<string,int>sub;

    for(int b=0;b<a;b++){

        sub.clear();

        int c;
        cin >> c;
        string ar; int in , d;

        while(c--){

            cin >> ar >> in;

            sub[ar]=in;

        }
        cin >> d;
        cin >> ar;

        printf("Case %d: ",b+1);

        if(sub[ar]==0)cout << "Do your own homework!" << endl;
        else if(d>=sub[ar])cout << "Yesss" << endl;
        else if(d+5>=sub[ar])cout << "Late" << endl;

        else cout << "Do your own homework!" << endl;
    }
    return 0;
}
