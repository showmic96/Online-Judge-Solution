// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e3+9;
int row[MAX][MAX] , col[MAX][MAX];
string ar[MAX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n , m;
    cin >> n >> m;

    for(int i=0;i<n;i++)cin >> ar[i];

    for(int i=0;i<n;i++){

        int counter = 0;

        for(int j=0;j<m;j++){

            if(ar[i][j]=='*')counter++;
        }

        for(int j=0;j<m;j++)row[i][j] = counter;
    }

    for(int i=0;i<m;i++){

        int counter = 0;

        for(int j=0;j<n;j++){

            if(ar[j][i]=='*')counter++;
        }

        for(int j=0;j<n;j++)col[j][i] = counter;
    }

    int mx = 0;

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            if(ar[i][j]=='*')mx++;
        }
    }

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            int temp = row[i][j]+col[i][j];

            if(ar[i][j]=='*')temp--;

            if(temp==mx){

                cout << "YES" << endl << i+1 << " " << j+1 << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}
