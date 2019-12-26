#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    string ar;

    while(cin >> ar){

        if(ar[0]=='#')break;

        int pc = 0 , yc = 0 , nc=0 , ac =0;

        int si = ar.size();

        for(int i=0;i<si;i++){

            if(ar[i]=='A')ac++;
            if(ar[i]=='Y')yc++;
            if(ar[i]=='N')nc++;
            if(ar[i]=='P')pc++;
        }

        if(si%2==0){

            if(ac>=si/2)cout << "need quorum" << endl;
            else if(yc>nc)cout << "yes" << endl;
            else if(nc>yc)cout << "no" << endl;
            else cout << "tie" << endl;
        }

        if(si%2==1){

            if(ac>=si/2+1)cout << "need quorum" << endl;
            else if(yc>nc)cout << "yes" << endl;
            else if(nc>yc)cout << "no" << endl;
            else cout << "tie" << endl;
        }
    }

    return 0;
}
