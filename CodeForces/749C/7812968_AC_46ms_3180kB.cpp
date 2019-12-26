// In the name of Allah the Lord of the worlds.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    int si ; string ar;
    cin >> si >> ar;

    queue<int>d_time;
    queue<int>r_time;
    for(int i=0;i<si;i++){
        if(ar[i]=='R')r_time.push(i);
        else d_time.push(i);
    }

    while(d_time.empty()==false&&r_time.empty()==false){
        int temp1 = d_time.front();
        int temp2 = r_time.front();

        d_time.pop();
        r_time.pop();

        if(temp1<temp2){

            d_time.push(si++);
        }

        else r_time.push(si++);

    }

    if(d_time.empty()==true)cout << "R" << endl;
    else cout << "D" << endl;
    return 0;
}


