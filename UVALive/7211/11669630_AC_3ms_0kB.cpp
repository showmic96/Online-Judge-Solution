#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a;
    int ar[101000];
    while(cin >> a){

        memset(ar , 0 , sizeof(ar));
        for(int i=0;i<5;i++){

            int in;
            cin >> in;
            ar[in]++;
        }

        cout << ar[a] << endl;
    }
    return 0;
}
