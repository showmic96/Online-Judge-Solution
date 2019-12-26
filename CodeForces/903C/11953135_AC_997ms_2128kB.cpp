// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int n;
    scanf("%d",&n);
    priority_queue<int>pq1 , pq2;

    for(int i=0;i<n;i++){

        int in;
        scanf("%d",&in);

        pq1.push(in);
    }

    int counter = 0;

    while(true){

        if(pq1.empty()==true)break;

        int mx = 2e9;

        counter++;

        while(!pq1.empty()){

            if(pq1.top()<mx){

                mx = pq1.top();
            }

            else pq2.push(pq1.top());

            pq1.pop();
        }

        while(!pq2.empty()){

            pq1.push(pq2.top());
            pq2.pop();
        }
    }

    printf("%d\n",counter);

    return 0;
}