// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int INF = 123456;

int main(void)
{
    int n , m , c = 0;
    while(cin >> n >> m){

        if(!n&&!m)break;
        int edges[123][123];
        map<int , string>mp;

        for(int i=0;i<n;i++){

            string ar;
            cin >> ar;
            mp[i+1] = ar;
        }

        for(int i=0;i<123;i++){

            for(int j=0;j<123;j++){

                if(i==j)edges[i][j] = 0;
                else edges[i][j] = INF;
            }
        }

        while(m--){

            int in1 , in2 , in3;
            cin >> in1 >> in2 >> in3;

            edges[in1][in2] = min(edges[in1][in2] , in3);
            edges[in2][in1] = min(edges[in2][in1] , in3);
        }

        for(int k=1;k<=n;k++){

            for(int i=1;i<=n;i++){

                for(int j=1;j<=n;j++){

                    if(edges[i][j]>edges[i][k] + edges[k][j]){

                        edges[i][j]=edges[i][k] + edges[k][j];
                        edges[j][i] = edges[i][j];
                    }
                }
            }
        }

        int ans , mi = 123456;

        for(int i=1;i<=n;i++){

            int counter = 0;

            for(int j=1;j<=n;j++){

                counter +=edges[i][j];
            }

            if(counter<mi){

                ans = i;
                mi = counter;
            }
        }

        printf("Case #%d : ",++c);

        cout << mp[ans] << endl;

    }

    return 0;
}
