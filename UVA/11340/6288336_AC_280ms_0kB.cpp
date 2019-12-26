#include <iostream>
#include <map>
#include <cstdio>
using namespace std;
int main (int argc, const char * argv[])
{

    int t,in;
    double answer;
    char letter;
    int vals;
    string line;
    map<char, int> values; 
    
    cin>>t;
    while (t--) {
        
        answer=0;
        cin>>in;
        while (in--) {
            cin>>letter>>vals;
            values.insert(pair<char, int>(letter, vals));
        }
        cin>>in;
        getchar();
        while (in--) {
            getline(cin, line);
            for (int i=0; i<line.size() ; i++) {
                if (values[line[i]]) {
                    answer+=values[line[i]];
                }
            }
        }
        answer/=100;
        printf("%.2f$\n", answer);
        
        values.clear();
        
    }
    return 0;
}