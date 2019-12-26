// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string ar;
    cin >> ar;

    vector<int> v;

    v.push_back(0);

    int si = ar.size();

    for(int i=0;i<si-1;i++){

        if(ar[i]==ar[i+1])v.push_back(v[i] + 1);
        else v.push_back(v[i]);
    }

    v.push_back(1e9);

    int q;
    cin >> q;
    while(q--){

        int in1 , in2;
        cin >> in1 >> in2;

        //cout << v[in2-1] << " " << v[in1-1] << endl;
        cout << v[in2-1] - v[in1-1] << endl;
    }

    return 0;
}
