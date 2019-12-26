#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int a;
    cin >> a;
    for(int b=0;b<a;b++){
        int c;
        cin >> c;
        char ar[c+1],br[c+1];

        cin >> ar;

        cin >> br;long long k=0;
        for(int d=0;d<c;d++){
            int i, j;
            if(ar[d]=='0')i=0;
            if(ar[d]=='1')i=1;
            if(ar[d]=='2')i=2;
            if(ar[d]=='3')i=3;
            if(ar[d]=='4')i=4;
            if(ar[d]=='5')i=5;
            if(ar[d]=='6')i=6;
            if(ar[d]=='7')i=7;
            if(ar[d]=='8')i=8;
            if(ar[d]=='9')i=9;
            if(br[d]=='0')j=0;
            if(br[d]=='1')j=1;
            if(br[d]=='2')j=2;
            if(br[d]=='3')j=3;
            if(br[d]=='4')j=4;
            if(br[d]=='5')j=5;
            if(br[d]=='6')j=6;
            if(br[d]=='7')j=7;
            if(br[d]=='8')j=8;
            if(br[d]=='9')j=9;
            int re1=abs(j-i);
            int re2=abs(9-max(i,j)+min(i,j)+1);
            k+=min(re1,re2);
        }
        printf("Case %d: ",b+1);
        cout << k << endl;
    }
    return 0;
}
