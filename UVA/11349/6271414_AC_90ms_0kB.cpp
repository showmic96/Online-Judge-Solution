#include<bits/stdc++.h>
typedef long long ll;

using namespace std;

int main(void)
{
    int a;
    cin >> a;

    char x , y ; int b;
    int j=0;
    while(a--){j++;

        cin >> x >> y >> b;
        bool check = true;
        long long ar[b][b];

        for(int c=0;c<b;c++){

            for(int d=0;d<b;d++){

                cin >> ar[c][d];
                if(ar[c][d]<0)check = false;
            }
        }



        for(int c=0;c<b;c++){

            for(int d=0;d<b/2;d++){

                if(ar[c][d]!=ar[b-c-1][b-d-1])check = false;
            }

        }

        printf("Test #%d: ",j);
        if(check==true)cout << "Symmetric." << endl;
        else cout << "Non-symmetric." << endl;

    }

    return 0;
}
