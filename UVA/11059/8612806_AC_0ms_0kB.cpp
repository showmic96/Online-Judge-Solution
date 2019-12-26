// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n , c = 0;
    long long sum , temp , mx1 , mx2;

    while(cin >> n){

        int ar[n];
        for(int i=0;i<n;i++){

            cin >> ar[i];
        }

        mx1 = ar[0] , mx2 = 0 , temp = 1;

        for(int i=0;i<n;i++){

            temp*=ar[i];
            mx1 = max(temp , mx1);
            if(temp==0)temp=1;
        }

        mx2 = ar[n-1];
        temp = 1;
        for(int i=n-1;i>=0;i--){

            temp*=ar[i];
            mx2 = max(temp , mx2);
            if(temp==0)temp=1;
        }

        printf("Case #%d: ",++c);

        cout << "The maximum product is " << max((long long)0 , max(mx1 , mx2)) << "." << endl << endl;
    }

    return 0;
}
