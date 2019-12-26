// In the name of Allah the most Merciful .

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int x , y , t;
    int ar[1010];

    cin >> t;
    int a[5] , b[5];

    while(t--){

        for(int i=0;i<5;i++){cin >> a[i];b[i]=a[i];}

        bool check = true;

        for(int i=0;i<4;i++)if(b[i+1]!=b[i]+1)check=false;

        for(int i=0;i<5;i++)if(a[i]!=b[i])check=false;

        if(check==false)cout << "N" << endl;
        else cout << "Y" << endl;

    }

    return 0;
}
