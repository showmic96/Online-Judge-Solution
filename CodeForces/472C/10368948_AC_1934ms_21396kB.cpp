// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

struct myStruct{

    string first , last;
    int idx;

    myStruct(string _first , string _last , int _idx){

        first = _first;
        last = _last;
        idx = _idx;
    }
};

vector<myStruct>v;

int main(void)
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++){

        string ar , br;
        cin >> ar >> br;

        v.push_back(myStruct(ar , br , i+1));
    }

    vector<int>data;

    bool check = true;
    string last = "";

    for(int i=0;i<n;i++){

        int in;
        cin >> in;

        string temp = v[in-1].first;
        if(temp>v[in-1].last){

            temp = v[in-1].last;
        }

        if(last<=v[in-1].first&&last<=v[in-1].last){

            last = temp;
        }

        else if(last<=v[in-1].first){

            last = v[in-1].first;
        }

        else if(last<=v[in-1].last){

            last = v[in-1].last;
        }

        if(last==v[in-1].first)continue;
        if(last==v[in-1].last)continue;

        check = false;
    }

    if(check==false)cout << "NO" << endl;
    else cout << "YES" << endl;

    return 0;
}
