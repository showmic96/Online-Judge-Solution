// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    while(cin >> n){

        if(!n)break;
        string ar;
        cin >> ar;
        int mx = INT_MAX , l = -1;

        for(int i=0;i<n;i++){

            if(ar[i]=='Z'){mx = 0 ;break;}

            if(ar[i]=='R'){l = i;}

            if(ar[i]=='D'){

                if(l!=-1){

                    mx = min(mx , i-l);
                }
            }
        }

        reverse(ar.begin() , ar.end());

        l = -1;

        for(int i=0;i<n;i++){

            if(ar[i]=='Z'){mx = 0 ;break;}

            if(ar[i]=='R'){l = i;}

            if(ar[i]=='D'){

                if(l!=-1){

                    mx = min(mx , i-l);
                }
            }
        }

        cout << mx << endl;
    }
    return 0;
}
