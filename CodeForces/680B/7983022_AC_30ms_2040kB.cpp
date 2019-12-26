#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int n , a , counter = 0 , c1 , c2;
    cin >> n >> a;
    int ar[n];
    c1 = a-1 , c2 = a-1;
    for(int i=0;i<n;i++)cin >> ar[i];

    while(true){

        if(c1>=0&&c2<n){

            if(ar[c1]==1){

                if(ar[c2]==1){if(c1!=c2)counter++;counter++;}

            }
        }

        else if(c1<0){if(ar[c2]==1)counter++;/*cout << "YES" << endl;*/}
        else if(c2>=n){if(ar[c1]==1)counter++;/*cout << ar[c1] << " " << c1 << endl;*/}

        c1--;c2++;
        if(c1<0&&c2>=n)break;
    }
    //cout << c1 << " " << c2 << endl;
    cout << counter << endl;

    return 0;
}
