// In the name of Allah the Lord of the worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e6+100000;

struct myStruct{

    ll index;
    ll value;

}input[MAX+10];

bool cmp(myStruct A , myStruct B)
{
    return A.value < B.value;
}

int main(void)
{
    ll n , m , in;
    cin >> n >> m;
    for(int i=0;i<MAX;i++){input[i].index = i;input[i].value = i;}

    for(int i=0;i<n;i++){
    
        cin >> in;
        if(in>=MAX)continue;
        input[in].value = 1e9;
    }

    sort(input+1 , input+MAX-1 , cmp);
    ll sum = 0 , counter = 0;

    for(int i=1;i<MAX;i++){

        sum+=input[i].value;
        //cout << input[i].value << endl;
        counter++;
        if(sum>m)break;

    }

    cout << counter-1 << endl;
    for(int i=1;i<counter;i++)cout << input[i].index << " ";
    cout << endl;
    return 0;
}
