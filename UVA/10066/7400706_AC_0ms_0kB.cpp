// In the name of Allah the Most Merciful

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int ar[100010] , br[100010] , in1 , in2;
	int si1 , si2;

	int counter = 0;

    while(cin >> si1 >> si2){

        if(!si1&&!si2)break;

        for(int i=0;i<si1;i++)cin >> ar[i];
        for(int j=0;j<si2;j++)cin >> br[j];

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

        printf("Twin Towers #%d\n",++counter);

        cout << "Number of Tiles : " <<  lcs[si1][si2]<< endl;
        cout << endl;
    }


    return 0;
}
