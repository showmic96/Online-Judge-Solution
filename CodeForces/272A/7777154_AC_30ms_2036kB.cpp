// In the name of Allah the Lord of the worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(void)
{
    int n;
    int sum = 0 , in;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> in;
        sum+=in;
    }
    sum--;
    n++;
    int counter = 0;
    if((sum+1)%n!=0)counter++;
    if((sum+2)%n!=0)counter++;
    if((sum+3)%n!=0)counter++;
    if((sum+4)%n!=0)counter++;
    if((sum+5)%n!=0)counter++;
    cout << counter << endl;
    return 0;
}
