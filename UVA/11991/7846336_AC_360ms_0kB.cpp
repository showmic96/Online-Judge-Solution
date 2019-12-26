// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n ,m , in;

    map<pair<int ,int >,int > maping;
    map<int , int> isThere;
    while(cin >> n >> m){
        maping.clear();
        isThere.clear();
        for(int i=0;i<n;i++){

            cin >> in;
            isThere[in]++;

            maping[make_pair(in , isThere[in])] = i + 1;
        }

        while(m--){

            int in1 ,in2;
            cin >> in1 >> in2;

            cout << maping[make_pair(in2 ,in1)] << endl;
        }
    }
        return 0;
}
