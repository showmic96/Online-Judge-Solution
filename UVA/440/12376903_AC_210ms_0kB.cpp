// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int jos(int n , int m)
{
    queue<int>current;
    for(int i=2;i<=n;i++)current.push(i);

    while(true){

        int temp;

        for(int i=0;i<m-1;i++){

            temp = current.front();
            current.pop();
            current.push(temp);
        }

        temp = current.front();
        current.pop();
        if(current.empty())return temp;
    }
}

int main(void)
{
    int n;
    while(scanf("%d",&n)==1){

        if(!n)break;

        for(int i=1;i<=10005;i++){

            if(jos(n , i)==2){

                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
