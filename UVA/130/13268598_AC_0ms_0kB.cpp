// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int jos(int n , int m , int st)
{
    if(n==1)return 1;
    queue<int>current;
    for(int i=0;i<n;i++)current.push(((st+i-1)%n)+1);
    while(true){

        int temp , t , t2;

        for(int i=0;i<m-1;i++){

            temp = current.front();
            current.pop();
            current.push(temp);
        }

        current.pop();
        if(current.empty())return temp;

        for(int i=0;i<m-1;i++){

            t = current.front();
            current.pop();
            current.push(t);
        }

        t = current.front();
        current.pop();
        if(t==temp){current.push(t) ; continue;}
        if(current.empty())return t;
        while(true){

            int now = current.front();
            current.pop();
            if(current.empty()){

                current.push(now);
                current.push(t);
                break;
            }
            current.push(now);
            if(now==temp){

                current.push(t);
                break;
            }
        }
        vector<int>v;
        while(!current.empty()){

            v.push_back(current.front());
            current.pop();
        }
        if(v.size()==1)return v[0];

        for(int i=0;i<v.size();i++)current.push(v[i]);
    }
}

int main(void)
{
    int n , m;
    while(scanf("%d %d",&n,&m)==2){

        if(!n&&!m)break;

        for(int i=1;i<=n;i++){

            if(jos(n , m , i)==1){

                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
