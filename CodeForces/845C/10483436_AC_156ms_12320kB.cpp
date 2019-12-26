// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct myStruct{

    ll ti , w;

    myStruct (ll _ti , ll _w){

        ti = _ti;
        w = _w;
    }

};

bool operator<(myStruct A , myStruct B)
{
    if(A.ti==B.ti){

        return A.w < B.w;
    }

    return A.ti < B.ti;
}

int main(void)
{
    int n;
    scanf("%d",&n);

    vector<myStruct>v;

    for(int i=0;i<n;i++){

        ll in1 , in2;
        scanf("%lld %lld",&in1 , &in2);

        v.push_back(myStruct(in1 , 1));
        v.push_back(myStruct(in2 , 2));
    }

    sort(v.begin() , v.end());

    int counter = 0;
    int lim = n*2;

    for(int i=0;i<lim;i++){

        if(v[i].w==1)counter++;
        else counter--;

        if(counter>2)break;
    }

    if(counter>2)cout << "NO" << endl;
    else cout << "YES" << endl;

    return 0;
}
