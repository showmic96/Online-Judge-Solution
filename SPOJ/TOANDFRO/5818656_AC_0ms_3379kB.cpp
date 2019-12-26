#include<bits/stdc++.h>
//#include<algorithm>
typedef long long ll;
using namespace std;

int main()
{
    ll a , b,  c ,d ,e , f, g , h;


    while(cin >> a){
            if(a==0)break;
        char ar[205];
        cin >> ar;
        b=strlen(ar);
        char br[(b/a)+1][a+1];
        f=0;
        for(c=0;c<b/a;c++){
            if(c==0||c%2==0)for(d=0;d<a;d++){br[c][d]=ar[f];f++;}
            else for(d=a-1;d>=0;d--){br[c][d]=ar[f];f++;}
        }
        for(c=0;c<a;c++)
            for(d=0;d<b/a;d++) cout << br[d][c];
        cout << endl;

    }



    return 0;
}