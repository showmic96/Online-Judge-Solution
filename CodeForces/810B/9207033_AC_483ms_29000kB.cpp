// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct myStruct{

    ll first , second , v;

}data[1234567];

bool cmp(myStruct A , myStruct B)
{
    if(A.v==B.v){

        return A.first < B.first;
    }

    return A.v > B.v;
}

int main(void)
{
    cin.tie(0);

    int n , f;
    cin >> n >> f;

    for(int i=0;i<n;i++){

        ll in1 , in2;
        cin >> in1 >> in2;

        data[i].v = min(2*in1 , in2) - min(in1 , in2);
        data[i].first = in1;
        data[i].second = in2;
    }

    sort(data , data+n , cmp);

    ll sum = 0;

    for(int i=0;i<f;i++){sum+=min(data[i].first*2 , data[i].second);}

    for(int i=f;i<n;i++){

        sum+=min(data[i].first , data[i].second);

    }
    cout << sum << endl;

    return 0;
}
