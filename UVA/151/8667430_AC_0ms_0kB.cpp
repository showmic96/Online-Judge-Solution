// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

bool is_it(int i , int n)
{
    queue<int>current;

    for(int j=2;j<=n;j++)current.push(j);

    int temp;

    while(!current.empty()){

        for(int j=0;j<i;j++){

            temp = current.front();
            current.pop();

            if(j==i-1)break;

            current.push(temp);
        }
    }

    if(temp==13)return true;

    return false;
}

int main(void)
{
    int n;
    while(cin >> n){

        if(!n)break;

        for(int i=1;;i++){

            if(is_it(i , n)==true){

                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}
