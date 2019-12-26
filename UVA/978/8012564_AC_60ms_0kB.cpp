// In the name of Allah the most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    cin >> t;
    bool space = false;
    priority_queue<int>pq1;
    priority_queue<int>pq2;

    while(t--){

        if(space)cout << endl;
        space = true;

        int b , sg , sb , in;
        cin >> b >> sg >> sb;

        for(int i=0;i<sg;i++){

            cin >> in;
            pq1.push(in);
        }

        for(int i=0;i<sb;i++){

            cin >> in;
            pq2.push(in);
        }

        while(true){

            if(pq1.empty()==true&&pq2.empty()==true){

                cout << "green and blue died" << endl;
                break;
            }

            if(pq1.empty()==true){

                cout << "blue wins" << endl;

                while(pq2.empty()==false){

                    cout << pq2.top() << endl;
                    pq2.pop();
                }

                break;
            }

            if(pq2.empty()==true){

                cout << "green wins" << endl;

                while(pq1.empty()==false){

                    cout << pq1.top() << endl;
                    pq1.pop();
                }

                break;
            }

            vector<int>v1;
            vector<int>v2;

            for(int i=0;i<b;i++){

                if(pq1.empty()==true||pq2.empty()==true)break;

                int temp1 = pq1.top();
                int temp2 = pq2.top();
                pq1.pop();
                pq2.pop();
                //cout << "TEMP : " << temp1 << " " << temp2 << endl;
                if(temp1>temp2)v1.push_back(temp1-temp2);
                if(temp2>temp1)v2.push_back(temp2-temp1);
            }
            

            for(int i=0;i<v1.size();i++)pq1.push(v1[i]);
            for(int i=0;i<v2.size();i++)pq2.push(v2[i]);
            
            v1.clear();
            v2.clear();
        }

        while(pq1.empty()==false)pq1.pop();
        while(pq2.empty()==false)pq2.pop();
    }
    return 0;
}
