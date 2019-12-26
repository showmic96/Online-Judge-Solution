// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int ar[5005];

int main(void)
{
    int n , a , b , c;
    cin >> n;

    cout << "? " << 1 << " " << 2 << endl;
    cin >> a;
    cout << "? " << 1 << " " << 3 << endl;
    cin >> b;
    cout << "? " << 2 << " " << 3 << endl;
    cin >> c;

    ar[1] = b-c+a;
    ar[1]/=2;
    ar[3] = b-ar[1];
    ar[2] = c-ar[3];


    for(int i=4;i<=n;i++){

        cout << "? 1 " << i << endl;
        int temp;
        cin >> temp;

        ar[i] = temp-ar[1];
    }

    cout << "!";
    for(int i=1;i<=n;i++)cout << " " << ar[i];
    cout << endl;

    return 0;
}
