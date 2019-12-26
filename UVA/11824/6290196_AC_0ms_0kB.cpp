#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(void)
{
    int a;
    cin >> a;

    while(a--){
        double total=0;

        int b;
        int d=1;
        vector<int>in;
        while(cin >> b){

            if(!b)break;
            in.push_back(b);


        }
        sort(in.begin(),in.begin()+in.size());

        for(int i=in.size()-1,j=0;i>=0;i--,j++){

            if(total<5000000 )total+=pow(in[i],d)*2;
            d++;
        }

        if(total<5000000)cout << total << endl;
        else cout << "Too expensive" << endl;



    }
    return 0;

}
