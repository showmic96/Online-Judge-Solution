// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int ar[25];
int n , p;

int Set(int n , int pos)
{
    return n|(1<<pos);
}

bool Check(int n , int pos)
{
    return n&(1<<pos);
}

int f(int i , int mask , int counter)
{
    if(i==p){

        for(int j=0;j<p;j++)if(Check(mask , j)==true)counter++;
        return counter;
    }

    int value = f(i+1 , mask , counter);
    value = max(value , f(i+1 , mask&ar[i] , counter+1));

    return value;
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){

        cin >> p >> n;
        memset(ar , 0 , sizeof(ar));

        for(int i=0;i<n;i++){

            int in1 , in2;
            cin >> in1 >> in2;

            ar[in1-1] = Set(ar[in1-1] , in2-1);
        }

        cout << f(0 , (1<<p)-1 , 0) << endl;
    }

    return 0;
}
