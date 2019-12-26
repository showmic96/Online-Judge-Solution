// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    string ar , br;
    cin >> ar >> br;
    int si1 = ar.size() , si2 = br.size();

    int mp1[26] , mp2[26];

    for(int i=0;i<26;i++){

        mp1[i] = 0;
        mp2[i] = 0;
    }

    for(int i=0;i<si1;i++){

        if(ar[i]!='?')mp1[ar[i]-'a']++;
    }

    int i = 0;

    while(i!=si1){

        for(int j=0;j<si2;j++){

            int temp = br[j] - 'a';

            mp2[temp]++;

            if(mp1[temp]<mp2[temp]){
                //cout << mp1[temp] << " " << mp2[temp] << endl;
                while(ar[i]!='?'){i++;if(i==si1)break;}

                if(i==si1)break;

                ar[i] = br[j];
                mp1[temp]++;
            }
        }
    }

    cout << ar << endl;

    return 0;
}