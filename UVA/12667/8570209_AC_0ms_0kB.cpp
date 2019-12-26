// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

struct myStruct{

    int team , time;

}data[15];

void setUp()
{
    for(int i=0;i<15;i++){

        data[i].time = 0;
        data[i].team = -1;
    }
}

int main(void)
{
    setUp();
    map<pair< char , int > , int>mp;
    int n , t , m;
    cin >> n >> t >> m;

    int time , id;
    char problem;
    string verdict;

    while(m--){

        cin >> time >> id >> problem >> verdict;

        if(verdict=="Yes"){

            if(mp[make_pair(problem , id)]==0){

                mp[make_pair(problem , id)]=1;
                //cout << "YAHOO";
                if(data[(int)(problem - 'A')].time<=time){
                    //cout << "YAHOO ";
                    //cout << (int)(problem - 'A') << endl;
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
