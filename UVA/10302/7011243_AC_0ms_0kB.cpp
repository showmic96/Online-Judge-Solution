#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 50010;

ll cube[MAX+1];

void cube_generator()
{
    cube[1] = 1;
    cube[0] = 0;
    for(ll i=2;i<=MAX;i++){

        cube[i]=i*i*i+cube[i-1];
    }
}

int main(void)
{
    int a;
    cube_generator();
    while(cin >> a){

        cout << cube[a] << endl;
    }
    return 0;
}
