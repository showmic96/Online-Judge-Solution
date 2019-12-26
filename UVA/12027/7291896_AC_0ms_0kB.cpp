#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    char ar[10000];

    while(gets(ar)){

        if(ar[0]=='0')break;

        char br[4];
        br[0]=ar[0];
        br[1]=ar[1];
        br[2]='\0';

        int si = strlen(ar);

        if(si%2==1){

            br[2] = ar[2];

        }
        br[3] = '\0';

        int a = atoi(br);

        a = sqrt(a);
        //cout << a;

        int kr[10];
        int d = 0;

        while(a!=0){

            kr[d] = a%10;
            d++;
            a/=10;
        }
        d--;
        cout << kr[d];

        for(int i=0;i<d;i++)cout << 0;

        si-=2;
        si/=2;

        for(int i=0;i<si;i++)cout<<0;
        cout << endl;
    }

    return 0;
}
