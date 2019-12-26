#include<bits/stdc++.h>
typedef long long ll;

using namespace std;

int main(void)
{
    char ar[32];
    while(cin >> ar){
        for(int a=0;a<strlen(ar);a++){
            if(ar[a]=='A'||ar[a]=='B'||ar[a]=='C')cout << 2;
            else if(ar[a]=='D'||ar[a]=='E'||ar[a]=='F') cout << 3;

            else if(ar[a]=='G'||ar[a]=='H'||ar[a]=='I') cout << 4;
            else if(ar[a]=='J'||ar[a]=='K'||ar[a]=='L') cout << 5;
            else if(ar[a]=='M'||ar[a]=='N'||ar[a]=='O') cout << 6;
            else if(ar[a]=='P'||ar[a]=='Q'||ar[a]=='R'||ar[a]=='S') cout << 7;
            else if(ar[a]=='T'||ar[a]=='U'||ar[a]=='V') cout << 8;
            else if(ar[a]=='W'||ar[a]=='X'||ar[a]=='Y'||ar[a]=='Z') cout << 9;
            else cout << ar[a];

        }
        cout << endl;
    }

    return 0;
}
