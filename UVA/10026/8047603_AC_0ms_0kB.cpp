// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1000+100;

struct myStruct{

    int index;
    double value;
}data[MAX];

bool cmp(struct myStruct A , struct myStruct B){

    if(A.value==B.value){

        return A.index < B.index;
    }

    return A.value > B.value;
}

int main(void)
{
    int t;
    cin >> t;
    bool space = false;
    while(t--){

        if(space)cout << endl;space = true;

        int n;
        cin >> n;

        for(int i=1;i<=n;i++){

            int in1 , in2;
            cin >> in1 >> in2;

            data[i].index = i;
            data[i].value = 1.00*(1.00*in2/in1*1.00);
        }

        sort(data+1 , data+n+1 , cmp);

        cout << data[1].index;

        for(int i=2;i<=n;i++)cout << " " << data[i].index;

        cout << endl;
    }

    return 0;
}
