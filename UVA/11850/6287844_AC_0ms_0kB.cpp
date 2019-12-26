#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a;
    while(cin >> a){

        int ar[a];

        if(!a)break;

        int j;

        for(j=0;j<a;j++)cin >> ar[j];

        bool check = true;

        sort(ar,ar+j,greater<int>());

        if(abs(1522-ar[0])>200)check = false;

        for(int j=0;j<a-1;j++){
            if(ar[j]-ar[j+1]>200){check =false;break;}
        }
        if(check==true)cout << "POSSIBLE" << endl;
        else cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
