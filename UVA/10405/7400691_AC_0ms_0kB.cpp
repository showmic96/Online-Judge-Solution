// In the name of Allah the Most Merciful

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string ar , br;
	int si1 , si2;

    while(getline(cin , ar)){
        getline(cin , br);
        si1 = ar.size() ; si2 = br.size();

        int lcs[si1+1][si2+1];

        for(int i=0;i<=si2;i++)lcs[0][i] = 0;
        for(int j=0;j<=si1;j++)lcs[j][0] = 0;

        for(int i=1;i<=si1;i++){

            for(int j=1;j<=si2;j++){


                if(ar[i-1]==br[j-1]){

                    lcs[i][j] = lcs[i-1][j-1] + 1;
                }

                else{

                    lcs[i][j] = max(lcs[i][j-1],lcs[i-1][j]);
                }
            }
        }

        cout << lcs[si1][si2] << endl;
    }


    return 0;
}
