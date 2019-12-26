#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 , MAX = 100010;
typedef long long ll;
typedef unsigned long long LL;



int main(void)
{
    int a;
    cin >> a;

    string ar , br;

    while(a--){

        cin >> ar;
        int si = ar.size();

        while((double)sqrt(si)!=(int)sqrt(si)){si++;ar+='1';}

        si = sqrt(si);

        char cr[si+1][si+1];

        int d = 0;

        for(int i=0;i<si;i++){

            for(int j=0;j<si;j++){

                cr[i][j] = ar[d];
                d++;

            }
        }


        for(int i=0;i<si;i++){

            for(int j=si-1;j>=0;j--){

                if(cr[j][i]!='1')cout << cr[j][i];
            }
        }

        cout << endl;

    }

    return 0;
}
