// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

struct myStruct{

    int team , time;

    myStruct(int x , int y){

        team = x;
        time = y;
    }

};


int main(void)
{
    map<pair< char , int > , int>mp;
    int n , t , m;
    cin >> n >> t >> m;

    vector<myStruct>data;
    int time , id;
    char problem;
    string verdict;

    for(int i=0;i<=n;i++){

        data.push_back(myStruct(-1 , 0));
    }

    while(m--){

        cin >> time >> id >> problem >> verdict;

        if(verdict=="Yes"){

            if(mp[make_pair(problem , id)]==0){

                mp[make_pair(problem , id)]=1;

                if(data[(int)(problem - 'A')].time<=time){

                    data[(int)(problem - 'A')].time = time;
                    data[(int)(problem - 'A')].team = id;
                }
            }
        }
    }

    for(int i=0;i<n;i++){

        cout << (char)('A' + i) << " ";
        if(data[i].team == -1){

            cout << "- -" << endl;
        }

        else cout << data[i].time << " " << data[i].team << endl;
    }

    return 0;
}
