#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string pangrams(string s) {
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    int flag = 0;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    for(int i=0; i<26; i++) {
        for(int j=0; j<int(s.length()); j++) {
            if(alpha[i]==s[j]) {flag=0; break;}
            else flag=1;
        }
        if(flag==1) {cout<<alpha[i]; 
        return "not pangram";}
    }
    return "pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
