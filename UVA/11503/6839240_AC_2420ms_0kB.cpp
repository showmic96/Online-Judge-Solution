#include<bits/stdc++.h>
using namespace std;

const int MAX = 100001;

map<string,string>parent;
map<string , int>total;


void setUp()
{
    for(int i=1;i<MAX;i++){

        //parent[i] = i;
        //total[i]=1;
    }
}


string Find(string ar)
{
    if(parent[ar]=="")return ar;

    return parent[ar] = Find(parent[ar]);
}


int Union(string ar , string br)
{
    string px = Find(ar) , py = Find(br);

    if(px==py)return total[px];

    parent[px] = py;

    if(!total[py])total[py]=1;
    if(!total[px])total[px]=1;

    total[py]+=total[px];
    return total[py];

}


int main(void)
{
    int a;
    cin >> a;
    string ar , br;
    map<string,int>friends;

    while(a--){
        setUp();
        int b , d = 1;
        cin >> b;
        parent.clear();
        total.clear();
        while(b--){

            cin >> ar >> br;



            cout << Union(ar,br) << endl;


        }
    }

    return 0;
}
