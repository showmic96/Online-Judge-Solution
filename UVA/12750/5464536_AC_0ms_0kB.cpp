#include<iostream>

using namespace std;

int main(void)
{
    int a , b , c, d ,e ,f,g=0;
    cin >> a;
    for(b=0;b<a;b++){
            g=0;
        char ac;
        e=0;
        cin >> c;
        for(d=0;d<c;d++){
            cin >> ac;
            if(e<3){
            if(ac=='L'||ac=='D') e+=1;
            if(ac=='W') e=0;
            g+=1;
            //if(e==3) {f=d;e=-1000;}
            }
        }
        if(g!=c||e==3) cout <<"Case " << b+1 <<": "<< g << endl;
        if(g==c&&e!=3) cout <<"Case " << b+1 <<": "<< "Yay! Mighty Rafa persists!" << endl;
           }
    return 0;
}