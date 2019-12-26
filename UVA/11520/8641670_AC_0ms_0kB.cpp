// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++){

        int n;
        cin >> n;

        char ar[n+1][n+1];

        for(int j=0;j<n;j++)cin >> ar[j];

        for(int j=0;j<n;j++){

            for(int k=0;k<n;k++){

                bool check = false;

                if(ar[j][k]=='.'){

                    for(int l=0;l<26;l++){

                        char u = '.' , v = '.' , w = '.' , x = '.' , z = 'A' + l ;

                        if(j+1<n)u = ar[j+1][k];
                        if(j-1>=0)v = ar[j-1][k];

                        if(k+1<n)w = ar[j][k+1];
                        if(k-1>=0)x = ar[j][k-1];

                        if(u!=z){

                            if(v!=z){

                                if(w!=z){

                                    if(x!=z){

                                        ar[j][k] = z;
                                        check = true;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        printf("Case %d:\n",i+1);
        for(int j=0;j<n;j++)cout << ar[j] << endl;
    }
    return 0;
}
