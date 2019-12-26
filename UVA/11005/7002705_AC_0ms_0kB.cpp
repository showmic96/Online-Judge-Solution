#include<bits/stdc++.h>
using namespace std;

map<int,int>maping;

void print(int a)
{
    int cheap = 1e9 , cheap_base , temp;
    set<int>ans;
    set<int>::iterator it;

    int temp_a = a;

    for(int i=2;i<=36;i++){

        temp_a = a;
        temp = 0;

        //cout << "yes" << endl;

        while(temp_a!=0){

            temp+=maping[(temp_a%i)];
            temp_a/=i;
        }

        if(cheap>temp){ans.clear();ans.insert(i);cheap=temp;}
        else if(cheap==temp){ans.insert(i);}
    }

    for(it = ans.begin();it!=ans.end();it++)cout <<" " <<*it;
    cout << endl;
}


int main(void)
{
    int a;
    cin >> a;
    int counter = 0 , in , q , input;

    bool blank = false;

    while(a--){

        if(blank==true)cout << endl;
        blank = true;
        maping.clear();

        for(int i=0;i<36;i++){

            cin >> in;
            maping[i] = in;
        }

        cin >> q;

        printf("Case %d:\n",++counter);

        while(q--){

            cin >> input;

            printf("Cheapest base(s) for number %d:",input);

            print(input);
        }
    }

    return 0;
}
