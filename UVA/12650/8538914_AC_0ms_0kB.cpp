// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int r , n;
    while(cin >> r >> n){

        map<int , int> mp;

        while(n--){
            int in;
            cin >> in;
            mp[in] = 1;
        }

        int i = 1;
        while(mp[i]!=0)i++;

        if(i>r)cout << "*" << endl;

        else{
            for(;i<=r;i++){

                if(mp[i]==0)cout << i << " ";
            }

            cout << endl;
        }
    }
    return 0;
}
