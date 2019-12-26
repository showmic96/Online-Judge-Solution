// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string ar;
    cin >> ar;

    int l1 = 0 , r1 = 0 , l2 = 0 , r2 = 0 , now = 0 , mx1 = 0 , mx2 = 0 , last = 0;

    for(int i=0;i<ar.size();i++){

        if(ar[i]=='B')now++;
        else now--;

        if(now<0){

            now = 0;
            last = i+1;
        }

        if(now>mx1){

            mx1 = now;
            l1 = last+1;
            r1 = i+1;
        }
    }

    now = 0 , last = 0;

    for(int i=0;i<ar.size();i++){

        if(ar[i]=='B')now--;
        else now++;

        if(now<0){

            now = 0;
            last = i+1;
        }

        if(now>mx2){

            mx2 = now;
            l2 = last+1;
            r2 = i+1;
        }
    }

    if(r1-l1>r2-l2)cout << l1 << " " << r1 << endl;
    else if(r1-l1<r2-l2)cout << l2 << " " << r2 << endl;
    else{

        if(l1<l2)cout << l1 << " " << r1 << endl;
        else if(l1>l2)cout << l2 << " " << r2 << endl;
        else{

            if(r1<r2)cout << l1 << " " << r1 << endl;
            else cout << l2 << " " << r2 << endl;
        }
    }

    return 0;
}
