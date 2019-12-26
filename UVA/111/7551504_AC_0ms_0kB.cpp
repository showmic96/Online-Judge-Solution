// In the name of Allah the most Merciful

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int a;
    cin >> a;

    int ar[a] , br[a] , lcm[a+1][a+1] , in;

    for(int i=0;i<a;i++){cin >> in;ar[in]=i;}

    while(cin >> in){
        br[in] = 0;

        for(int i=1;i<a;i++){cin >> in;br[in] = i;}

        memset(lcm , 0 , sizeof(lcm));

        for(int i=1;i<=a;i++){

            for(int j=1;j<=a;j++){

                if(ar[i]==br[j]){

                    lcm[i][j] = lcm[i-1][j-1] + 1;
                }

                else{

                    lcm[i][j] = max(lcm[i-1][j] , lcm[i][j-1]);
                }
            }
        }

        cout << lcm[a][a] << endl;

    }

    return 0;
}


