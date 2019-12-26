// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5+100;

int main(void)
{
    bool isVisited[MAX];
    memset(isVisited , false , sizeof(isVisited));

    int n;
    cin >> n;

    string ar;
    cin >> ar;

    int next[n];
    int si = ar.size();

    for(int i=0;i<n;i++){

        cin >> next[i];
    }

    int d = 0;

    while(true){

        //cout << d << endl;

        if(isVisited[d]==true){cout << "INFINITE" << endl;break;}
        isVisited[d] = true;

        if(ar[d]=='<')d-=next[d];
        else d+=next[d];

        if(d>=n||d<0){cout << "FINITE" << endl;break;}
    }

    return 0;
}
