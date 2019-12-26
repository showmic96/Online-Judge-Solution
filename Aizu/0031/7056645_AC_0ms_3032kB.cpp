#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a;

    int ar[100];

    int d;

    while(cin >>a){

        d = 0;

        while(true){

            if(a>=512){ar[d] = 512;d++;a-=512;if(a==0)break;continue;}
            if(a>=256){ar[d] = 256;d++;a-=256;if(a==0)break;continue;}
            if(a>=128){ar[d] = 128;d++;a-=128;if(a==0)break;continue;}
            if(a>=64){ar[d] = 64;d++;a-=64;if(a==0)break;continue;}
            if(a>=32){ar[d] = 32;d++;a-=32;if(a==0)break;continue;}
            if(a>=16){ar[d] = 16;d++;a-=16;if(a==0)break;continue;}
            if(a>=8){ar[d] = 8;d++;a-=8;if(a==0)break;continue;}
            if(a>=4){ar[d] = 4;d++;a-=4;if(a==0)break;continue;}
            if(a>=2){ar[d] = 2;d++;a-=2;if(a==0)break;continue;}
            if(a>=1){ar[d] = 1;d++;a-=1;if(a==0)break;continue;}
        }

        sort(ar , ar + d);

        cout << ar[0];

        for(int i=1;i<d;i++)cout << " " << ar[i];

        cout << endl;
    }

    return 0;
}
