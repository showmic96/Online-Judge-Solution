#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(void)
{
    int a;
    cin >> a;
    char ar[10000];
    int tt[6];
    while(a--){
        scanf("\n");

        int A=0 , M=0 , R=0 , G=0 , I=0 , T=0;
        gets(ar);
        int k = strlen(ar);

        for(int j=0;j<k;j++){

            if(ar[j]=='A')A++;
            if(ar[j]=='M')M++;
            if(ar[j]=='R')R++;
            if(ar[j]=='G')G++;
            if(ar[j]=='I')I++;
            if(ar[j]=='T')T++;


        }

        tt[0]=A/3;
        tt[1]=M/1;
        tt[2]=R/2;
        tt[3]=G/1;
        tt[4]=I/1;
        tt[5]=T/1;
        sort(tt,tt+6);

        cout << tt[0] << endl;
    }
    return 0;
}
