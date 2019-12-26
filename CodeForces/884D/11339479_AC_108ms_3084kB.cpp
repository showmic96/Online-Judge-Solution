// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct data{

    ll x;

    data(ll _x){

        x = _x;
    }
};

bool operator<(data A , data B)
{
    return A.x > B.x;
}

int main(void)
{
    int n;
    scanf("%d",&n);

    priority_queue<data>pq;

    for(int i=0;i<n;i++){

        ll in;
        scanf("%lld",&in);
        pq.push(data(in));
    }

    ll sum = 0;

    if(n%2==0){

        ll temp = 0;
        temp+=pq.top().x;
        pq.pop();
        temp+=pq.top().x;
        pq.pop();

        sum+=temp;
        pq.push(data(temp));
    }

    while(pq.empty()==false){

        ll temp = pq.top().x;
        pq.pop();

        if(pq.empty())break;

        temp+=pq.top().x;
        pq.pop();
        temp+=pq.top().x;
        pq.pop();

        sum+=temp;
        pq.push(data(temp));
    }

    printf("%lld\n",sum);

    return 0;
}
