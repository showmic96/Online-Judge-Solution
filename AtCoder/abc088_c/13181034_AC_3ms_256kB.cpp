// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int ar[3][3];
int a[3] , b[3];
bool check()
{
    for(int i=0;i<3;i++){

        for(int j=0;j<3;j++){

            if(ar[i][j]!=a[i]+b[j])return false;
        }
    }
    
    return true;
}

int main(void)
{
    for(int i=0;i<3;i++){

        for(int j=0;j<3;j++){

            cin >> ar[i][j];
        }
    }

    for(int i=0;i<=100;i++){

        for(int j=0;j<=100;j++){

            for(int k=0;k<=100;k++){

                a[0] = i;
                b[0] = ar[0][0] - i;
                a[1] = j;
                b[1] = ar[1][1] - j;
                a[2] = k;
                b[2] = ar[2][2] - k;

                if(check()==true){

                    cout << "Yes" << endl;
                    return 0;
                }

            }
        }
    }

    cout << "No" << endl;

    return 0;
}
