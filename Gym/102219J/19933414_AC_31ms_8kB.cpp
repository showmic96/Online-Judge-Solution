// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    vector<char>v;
    v.push_back('A');
    v.push_back('B');
    v.push_back('C');
    v.push_back('D');
    v.push_back('E');
    int val[5];
    string ar[5];
    for(int i=0;i<5;i++)cin >> ar[i];
    do{
        for(int i=0;i<v.size();i++){
            val[v[i]-'A'] = i;
        }
        bool check = true;
        for(int i=0;i<5;i++){
            if(ar[i][1]=='>'){
                if(val[ar[i][0]-'A']<val[ar[i][2]-'A'])check = false;
            }
            else{
                if(val[ar[i][0]-'A']>val[ar[i][2]-'A'])check = false;
            }
        }
        if(check==true){
            for(int i=0;i<v.size();i++)cout << v[i];
            cout << endl;
            ar[0] = "DONE";
            break;
        }
    }while(next_permutation(v.begin() , v.end()));
    if(ar[0]!="DONE")cout << "impossible" << endl;

    return 0;
}
