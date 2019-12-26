// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string temp = "";
    int counter = 0;

    for(int i=0;i<26;i++){

        for(int j=0;j<100005;j++){

            if(counter+j<=n)temp+='a'+i;
            else break;

            counter+=j;
        }

        if(counter==n)break;
    }

    cout << temp << endl;

    return 0;
}
