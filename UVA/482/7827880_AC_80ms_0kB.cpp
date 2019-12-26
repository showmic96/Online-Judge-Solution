// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

struct myStruct{
    int index;
    string value;
}input[10101010];

bool cmp(myStruct A , myStruct B)
{
    return A.index < B.index;
}

int main(void)
{
    int t , in;
    cin >> t;
    bool space = false;
    double in2;
    

    while(t--){
		scanf("\n");
        if(space)cout << endl;space = true;
        int counter = 0;
        string ar , br;
        getline(cin , ar);
        stringstream ss(ar);

        while(ss >> in){

            input[counter++].index = in;
            //if(counter==3)break;
        }

        for(int i=0;i<counter;i++){

            cin >> input[i].value;

        }

        sort(input ,input+counter , cmp);

        for(int i=0;i<counter;i++)cout << input[i].value << endl;
    }

    return 0;
}

