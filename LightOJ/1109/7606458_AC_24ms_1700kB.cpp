// In the name of Allah the most Merciful .

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

//map<int>maping1;
//map<int>maping2;

struct myStruct{

    int no_of_div = 0;
    int last_pos;
    int pos_current;
}maping[1010];

bool cmp(myStruct A , myStruct B)
{
    if(A.no_of_div==B.no_of_div){

        return A.pos_current>B.pos_current;
    }
    return A.no_of_div<B.no_of_div;
}

void pre_cal()
{
    for(int i=1;i<=1000;i++){

        int j =1;
        while(i*j<=1000){

            maping[i*j].no_of_div++;
            j++;
        }

        maping[i].pos_current = i;
    }

    sort(maping , maping+1001, cmp);


}

int main(void)
{
    pre_cal();
    int t;
    cin >> t;

    for(int i=0;i<t;i++){
        int in;
        cin >> in;

        printf("Case %d: ",i+1);
        cout << maping[in].pos_current << endl;
    }

    return 0;
}
