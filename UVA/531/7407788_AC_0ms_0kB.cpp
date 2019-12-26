// In the name of Allah the Most Merciful

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string in = "";

    while(cin >> in){

    int si1 = 0 , si2=0;
    string ar[1010] , br[1010] , ans[1010];

    while(true){

        if(in=="#")break;
        ar[si1] = in;

        si1++;
        in="";
        cin >> in;
    }
    in="";

    while(cin >> in){


        if(in=="#")break;
        br[si2] = in;
        si2++;
        in="";
    }

    int lcm[si1+1][si2+1];
    int re[si1][si2];

    for(int i=0;i<=si2;i++)lcm[0][i]=0;

    for(int i=0;i<=si1;i++)lcm[i][0]=0;

    int d = 0 , current = 0;

    for(int i=1;i<=si1;i++){

        for(int j=1;j<=si2;j++){

            if(ar[i-1]==br[j-1]){

                //cout << ar[i-1] << " " << i << " " << br[j-1] << " " << j<< endl;

                lcm[i][j] =lcm[i-1][j-1] + 1;
                re[i-1][j-1] = 1;

            }

            else{

                lcm[i][j] = max(lcm[i-1][j] , lcm[i][j-1]);

                if(lcm[i][j]==lcm[i-1][j])re[i-1][j-1] = 2;
                else re[i-1][j-1] = 3;

            }
        }

    }
    int i = si1-1 , j = si2-1;
    d=0;
    while(true){

        if(i<0||j<0)break;
        if(re[i][j]==1){

            ans[d] = ar[i];
            d++;
            i--;j--;
        }
        else if(re[i][j]==2){
            i--;
        }
        else j--;

    }

    cout << ans[d-1];

    for(int i=d-2;i>=0;i--)cout << " " << ans[i];

    cout << endl;
    }
    return 0;
}
