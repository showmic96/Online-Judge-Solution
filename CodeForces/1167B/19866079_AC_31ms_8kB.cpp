// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio();
    cin.tie(0);cout.tie(0);

    vector<int>v;
    vector<int>store;
    store.push_back(4);
    store.push_back(8);
    store.push_back(15);
    store.push_back(16);
    store.push_back(23);
    store.push_back(42);

    for(int i=0;i<4;i++){
        cout << "? " << "1 " << i+2 << endl;
        int in;
        cin >> in;
        v.push_back(in);
    }
    do{
        bool check = true;
        for(int i=0;i<4;i++){
            int temp = store[0]*store[i+1];
            if(temp!=v[i])check = false;
        }
        if(check){
            cout << "!";
            for(auto it:store){
                cout << " " << it;
            }
            cout << endl;
            break;
        }
    }while(next_permutation(store.begin() , store.end()));
    return 0;
}
