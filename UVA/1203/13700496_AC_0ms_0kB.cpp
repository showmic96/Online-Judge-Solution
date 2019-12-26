// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct s{

    int name;
    int total , now;
    s(int _name , int _now){

        name = _name;
        now = _now;
        total = now;
    }
};

bool operator<(s A , s B)
{
    if(A.total==B.total)return A.name>B.name;
    return A.total>B.total;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    priority_queue<s>pq;

    string ar;

    while(cin >> ar){

        if(ar=="#")break;
        int in1 , in2;
        cin >> in1 >> in2;

        pq.push(s(in1 , in2));
    }

    int k;
    cin >> k;

    for(int i=0;i<k;i++){

        struct s temp = pq.top();
        pq.pop();

        cout << temp.name << endl;
        temp.total+=temp.now;
        pq.push(temp);
    }

    return 0;
}
