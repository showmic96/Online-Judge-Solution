#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll b1 , b2 , c1 , c2 , g1 , g2 , b3 , c3 , g3 ,mi ,BCG , CBG , GBC , GCB , BGC , CGB;;

    while(cin >> b1 >> g1 >> c1 >> b2 >> g2 >> c2 >> b3 >> g3 >> c3){

        BCG = g1+c1+b2+g2+c3+b3;
        CBG = g1+b1+c2+g2+c3+b3;
        GBC = c1+b1+c2+g2+g3+b3;
        GCB = c1+b1+b2+g2+c3+g3;
        BGC = g1+c1+c2+b2+g3+b3;
        CGB = g1+b1+c2+b2+c3+g3;

        mi = min(CGB,min(BGC,min(GCB,min(GBC,min(BGC,CBG)))));

        if(mi==BCG) cout << "BCG " << BCG << endl;
        else if(mi==BGC)cout << "BGC " << BGC << endl;
        else if(mi==CBG)cout << "CBG " << CBG << endl;
        else if(mi==CGB)cout << "CGB " << CGB << endl;
        else if(mi==GBC) cout << "GBC " << GBC << endl;
        else cout << "GCB " << GCB << endl;
    }

    return 0;
}
