#include<bits/stdc++.h>
using namespace std;

int main(void)
{

    string ar;
    set<string>dict;
    string br;
    while(cin >> ar){

        //int d=0;
        br="";
        char cr[100];
        for(int j=0;j<=ar.size();j++){
            if(ar[j]>='A'&&ar[j]<='Z'){br+=tolower(ar[j]);}
            else if(ar[j]>='a'&&ar[j]<='z'){br+=ar[j];}

            else if (br!=""){dict.insert(br);br="";}
        }
        //br=cr;
        //br+= cr;
        //cout << br << endl;
        //dict.insert(br);

    }

    set<string>::iterator it;
    for(it = dict.begin();it!=dict.end();it++)cout << *it << endl;

    return 0;
}
