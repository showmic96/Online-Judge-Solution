#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    string ar , br;

    map<string,int>counting;

    getline(cin , ar);

    stringstream ss(ar);

    int hi = 0;
    int si = 0;

    string output1 , output2;

    set<string>input;
    set<string>::iterator it;

    while(ss >> br){


        int ji = br.size();

        for(int i=0;i<ji;i++){

            if(br[i]>='A'&&br[i]<='Z')br[i] = br[i] + 32;
        }

        counting[br]++;

        if(counting[br]>hi){hi=counting[br];output1 = "";output1 = br;}

        if(br.size()>si){si=br.size();output2 = "";output2 = br;}
    }

    cout << output1 << " " << output2 << endl;


    return 0;

}
