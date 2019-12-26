// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int edges[111][111];
int data[111][111];
const int MAX = 923456789;

void setUp(int n)
{
    for(int i=0;i<=n;i++){

        for(int j=0;j<=n;j++){

            edges[i][j] = MAX;
        }
    }
}

int main(void)
{
    int c , s , q;
    int t = 0;
    bool space = false;
    while(cin >> c >> s >> q){

        if(!c&&!s&&!q)break;

        if(space)cout << endl;
        space = true;

        setUp(c);

        while(s--){

            int in1, in2 , in3;
            cin >> in1 >> in2 >> in3;

            edges[in1][in2] = in3;
            edges[in2][in1] = in3;
            //data[in1][in2] = in3;
        }

        for(int k=1;k<=c;k++){

            for(int i=1;i<=c;i++){

                for(int j=1;j<=c;j++){

                    //if(edges[i][k]==MAX||edges[k][j]==MAX)continue;

                    edges[i][j] = edges[j][i] = min(edges[i][j] , max(edges[i][k] , edges[k][j]));
                }
            }
        }

        printf("Case #%d\n",++t);

        while(q--){

            int in1 , in2;
            cin >> in1 >> in2;
            if(edges[in1][in2]==MAX)cout << "no path" << endl;
            else cout << edges[in1][in2] << endl;
        }
    }
    return 0;
}
