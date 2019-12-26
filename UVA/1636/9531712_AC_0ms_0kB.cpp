// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string ar;
    while(cin >> ar){

        int si = ar.size();
        long double temp = si;
        long double p = 0 , zero = 0;

        if(ar[0]=='0'&&ar[si-1]=='0')p++;
        if(ar[si-1]=='0')zero++;

        for(int i=0;i<si-1;i++){

            if(ar[i]=='0'&&ar[i+1]=='0')p++;
            if(ar[i]=='0')zero++;
        }

        long double t1 = p/zero;
        long double t2 = 1.00*zero/temp;

        if(t1>t2)printf("SHOOT\n");
        else if(t1==t2)printf("EQUAL\n");
        else printf("ROTATE\n");
    }
    return 0;
}
