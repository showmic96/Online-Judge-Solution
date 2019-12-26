// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

struct myStruct{

    string name;
    int p , idx;

}data[1234567];

bool cmp(struct myStruct A , struct myStruct B)
{
    if(A.p==B.p)return A.idx < B.idx;
    return A.p < B.p;
}

int main(void)
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++){

        string name , priority;
        cin >> name >> priority;

        data[i].name = name;
        data[i].idx = i+1;

        if(priority=="captain")data[i].p = 10;
        if(priority=="man")data[i].p = 9;
        if(priority=="woman")data[i].p = 8;
        if(priority=="child")data[i].p = 8;
        if(priority=="rat")data[i].p = 7;
    }

    sort(data , data+n , cmp);

    for(int i=0;i<n;i++)cout << data[i].name << endl;

    return 0;
}
