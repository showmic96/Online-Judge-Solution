#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a;
    int ar[10000] , br[10000];
    while(cin >> a){


        int d=0;
        for(d=0;d<a;d++){

            cin >> ar[d];
        }

        for(d=0;d<a-1;d++){
            br[d]=abs(ar[d+1]-ar[d]);
        }
        sort(br,br+d);
        bool check = true;

        for(d=1;d<a;d++){
            if(br[d-1]==br[d]){check=false;break;}
        }

        if(check==false)cout << "Not jolly" << endl;
        else cout << "Jolly" << endl;
    }
    return 0;
}
