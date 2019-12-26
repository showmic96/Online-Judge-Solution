// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int a[101010];

int main(void)
{
    string ar;
    while(getline(cin , ar)){

        //scanf("\n");
        stringstream ss(ar);
        int temp , n = 0;

        while(ss >> temp){

            a[n++] = temp;
        }

        int mx = 0;
        temp=0;
        for(int i=0;i<n;i++){

            temp+=a[i];

            mx = max(mx , temp);

            if(temp<0)temp = 0;
        }

        cout << mx << endl;
    }
    return 0;
}
