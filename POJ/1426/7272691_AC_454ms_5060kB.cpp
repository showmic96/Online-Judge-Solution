#include<iostream>
#include<queue>
using namespace std;

typedef long long ll;

int main(void)
{
    ll a , temp;
    while(cin >> a){

        if(!a)break;

        queue<ll>current;

        current.push(1);

        while(1){

            temp = current.front();
            current.pop();

            if(temp%a==0){
                break;
            }

            current.push(10*temp);
            current.push(10*temp+1);
        }

        cout << temp << endl;
    }

    return 0;
}