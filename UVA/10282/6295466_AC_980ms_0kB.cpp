#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    map<string,string>english;
    map<string,string>bdeshi;
    string ar , br;
    string kr;

    while(getline(cin,kr)){

        if(kr=="")break;
        //cout << kr << endl;
        stringstream two (kr);

        two >> ar >> br;

        english[ar]=br;
        bdeshi[br]=ar;
        kr="";

    }

    while(cin >> ar){
       // cout << "YES" << endl;

        if(english[ar]!="")cout << english[ar] << endl;
        else if(bdeshi[ar]!="")cout << bdeshi[ar] << endl;
        else cout << "eh" << endl;
    }
    return 0;
}
