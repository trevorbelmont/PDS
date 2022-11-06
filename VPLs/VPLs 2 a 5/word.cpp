#include <iostream>
#include <map>
#include <string>

using namespace ::std;

void split(string c, map<string, int>& m) {
    int i = 0;

    while (i <= c.size()) {
        char k = c[i];

        if (k == ' ' || i == 0) {
            if (k == ' ') i++;
            string temp;

            while (c[i] != ' ' && i <= c.size()) {
                temp.push_back(c[i]);
                i++;
            }

            //cout << temp << endl;
            m[temp]++;
        }
    }
}

int main() {
     string s,k;

   // getline(cin, s);

while((getline(cin, k, '$'))){
 s += k;
}
   
    map<string, int> w;

    split(s, w);

    string comum;
    int q = 0; 

    for (map<string, int>::iterator it = w.begin(); it != w.end(); it++) {
        if((*it).second > q) {
            q = (*it).second;
            comum = (*it).first;
        }
    }
    cout << comum;
}
