// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

string ar[123456];

int main(void)
{
    int n , m , i1=0 , i2=0 , j1=0 , j2=0;
    bool check = false;

    cin >> n >> m;

    for(int i=0;i<n;i++)cin >> ar[i];

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            if(ar[i][j]=='B'&&check==true){

                i1 = min(i1 , i);
                i2 = max(i2 , i);
                j1 = min(j1 , j);
                j2 = max(j2 , j);
            }

            else if(ar[i][j]=='B'){

                i1 = i;
                i2 = i;
                j1 = j;
                j2 = j;

                check = true;
            }
        }
    }

    //cout << i1 << " " << j1 << " " << i2 << " " << j2 << endl;

    while(i2-i1!=j2-j1){

        if(i2-i1<j2-j1){

            if(i2+1<n)i2++;
            else if(i1-1>=0)i1--;
            else break;
        }

        else{

            if(j2+1<m)j2++;
            else if(j1-1>=0)j1--;
            else break;
        }
    }

    int counter = 0;

    for(int i=i1;i<=i2;i++){

        for(int j=j1;j<=j2;j++){

            if(ar[i][j]=='W')counter++;
        }
    }

    if(i2-i1!=j2-j1)counter = -1;

    cout << counter << endl;

    return 0;
}
