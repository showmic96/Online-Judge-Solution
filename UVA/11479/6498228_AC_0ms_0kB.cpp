#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(void)
{
    int a;
    cin >> a;
    ll ar[3];
    for(int b=0;b<a;b++){

        cin >> ar[0] >> ar[1] >> ar[2];

        sort(ar,ar+3);
        printf("Case %d: ",b+1);

        if(ar[0]+ar[1]<=ar[2]||ar[0]<=0)cout << "Invalid" << endl;
        else{

                if(ar[0]==ar[1]&&ar[1]==ar[2])cout << "Equilateral" << endl;
                else if(ar[0]==ar[1]||ar[0]==ar[2]||ar[1]==ar[2])cout << "Isosceles" << endl;
                else cout << "Scalene" << endl;

        }
    }
}
