// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;

    while(cin >> n){

        if(!n)break;

        set<int>store;
        set<int>::iterator it;

        map<int ,int>mp;

        while(n--){

            int in1 , in2;
            cin >> in1 >> in2;

            store.insert(in1);
            store.insert(in2);

            mp[in1]--;
            mp[in2]++;
        }

        bool check = true;

        for(it = store.begin();it!=store.end();it++){

            if(mp[*it]!=0){

                cout << "NO" << endl;
                check= false;
                break;
            }
        }

        if(check==true)cout << "YES" << endl;
    }

    return 0;
}
