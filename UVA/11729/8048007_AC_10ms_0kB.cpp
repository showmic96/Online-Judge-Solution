// In the name of Allah the Lord of the worlds.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5;

struct myStruct{

    int value , penalty;

}data[MAX];

bool cmp(struct myStruct A , struct myStruct B){

    return A.penalty > B.penalty;
}

int main(void)
{
    int counter = 0;
    int n;
    while(cin >> n){
        if(!n)break;

        for(int i=0;i<n;i++){

            cin >> data[i].value;
            cin >> data[i].penalty;
        }

        sort(data , data+n , cmp);

        int hi = 0 , sum = 0;

        for(int i=0;i<n;i++){

            sum+=data[i].value;

            hi = max(hi , sum+data[i].penalty);
        }

        printf("Case %d: ",++counter);
        cout << hi << endl;
    }
    return 0;
}
