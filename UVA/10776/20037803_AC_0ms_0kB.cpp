// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int n , si;
string ar;
bool taken[35];
char ans[35];
vector<char>v;

void f(int idx)
{
    if(v.size()==n){
        string temp = "";
        for(int i=0;i<v.size();i++){
            temp+=v[i];
        }
        cout << temp << endl;
        return ;
    }
    for(int i=idx;i<si;i++){
        if(taken[i]==false){
            taken[i] = true;
            v.push_back(ar[i]);
            f(i+1);
            taken[i] = false;
            v.pop_back();
            while(ar[i]==ar[i+1])i++;
        }
    }
}

int main(void)
{
    while(cin >> ar >> n){
        sort(ar.begin() , ar.end());
        si = ar.size();
        memset(taken , false , sizeof(taken));
        f(0);
    }

    return 0;
}
