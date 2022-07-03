#include <bits/stdc++.h>
#include <string.h>

using namespace std;

/*
 * Complete the 'superReducedString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string superReducedString(string s) {
    for(int i=0; i<s.length(); i++) {
        if(s[i+1] && s[i]==s[i+1]) {
            s.erase(i, 2);
            if(i>0) i=i-2; else i=i-1;
        }
    }
    if(!s[0]) return "Empty String";
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
