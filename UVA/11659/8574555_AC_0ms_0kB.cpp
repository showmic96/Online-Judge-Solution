// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n , m;
    while(cin >> n >> m){

        if(!n&&!m)break;

        map<int , int>mp;

        while(m--){

            int in1 , in2;
            cin >> in1 >> in2;

            if(in2<0){

                mp[-in2] = 1;
            }
        }

        int counter = 0;

        for(int i=1;i<=n;i++){

            if(mp[i]==0)counter++;
        }

        cout << counter << endl;
    }
    return 0;
}
