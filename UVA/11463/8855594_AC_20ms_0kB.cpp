// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 123 , INF = 123456;

int ar[MAX][MAX];

void setUp()
{
    for(int i=0;i<MAX;i++){

        for(int j=0;j<MAX;j++){

            if(i==j)ar[i][j] = 0;
            else ar[i][j] = INF;
        }
    }
}

int main(void)
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++){

        int n , m;
        cin >> n >> m;

        setUp();

        for(int j=0;j<m;j++){

            int in1 , in2;
            cin >> in1 >> in2;

            ar[in1][in2] = 1;
            ar[in2][in1] = 1;
        }

        for(int l=0;l<n;l++){

            for(int j=0;j<n;j++){

                for(int k=0;k<n;k++){

                    if(ar[j][k]>ar[j][l]+ar[l][k]){

                        ar[j][k] = ar[j][l] + ar[l][k];
                        ar[k][j] = ar[j][k];
                    }
                }
            }
        }

        int mx = 0 , st , en;

        cin >> st >> en;

        for(int j=0;j<n;j++){

            mx = max(ar[j][st]+ar[j][en],mx);
        }

        printf("Case %d: %d\n",i+1 , mx);
    }
    return 0;
}
