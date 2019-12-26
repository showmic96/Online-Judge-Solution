// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string ar[55];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n , m;
    cin >> n >> m;

    for(int i=0;i<n;i++)cin >> ar[i];

    for(int i=n-1;i>=0;i--){

        for(int j=0;j<m;j++){

            if(ar[i][j]=='.'){

                for(int i1=i;i1>=0;i1--){

                    if(ar[i1][j]=='#')break;
                    if(ar[i1][j]=='o'){

                        ar[i][j] = 'o';
                        ar[i1][j] = '.';
                        break;
                    }
                }
            }
        }
    }

    for(int i=0;i<n;i++)cout << ar[i] << endl;

    return 0;
}
