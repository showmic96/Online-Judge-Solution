// In the name of Allah the most Merciful.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    int m , n;
    cin >> m >> n;
    char ar[m+10][n+10];

    for(int i=0;i<m;i++)cin >> ar[i];

    int d = 0 , hi = 0 , counter = 0;
    int e = 0;
    bool check = true;
    while(d!=m){

        if(ar[d][e]=='.')counter++;
        if(ar[d][e]=='L'){if(counter>hi)hi=counter;counter=0;}
        if(check==true)e++;
        else e--;
        if(e==n){check=false;d++;}
        if(e==-1){check=true;d++;}

        if(d==m)break;
    }

    if(counter>hi){hi=counter;counter=0;}

    cout << hi << endl;

    return 0;
}
