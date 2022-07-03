#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'minimumNumber' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING password
 */

int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    int ch = 0;
    for(int i=0; i<n; i++) {
        if(password[i]>='0'&&password[i]<='9') 
            {
                ch=0;
                break;
            }
        else ch+=1;
        if(ch>0) ch=1;
    }
    int temp = ch;
    for(int i=0; i<n; i++) {
        if(password[i]>='a'&&password[i]<='z') {
            ch=temp;
            break;
        } 
        ch+=1;
        if(ch>temp) ch=temp+1;
    }
    temp=ch;
    for(int i=0; i<int(password.length()); i++) {
        if(password[i]>='A'&&password[i]<='Z') {
            ch=temp;
            break;
        }
        else ch+=1;
        if(ch>temp) ch=temp+1;
    }
    temp=ch;
    for(int i=0; i<n; i++) {
        if((password[i]>='!'&&password[i]<='+') || password[i]=='-') {
            ch=temp;
            break;
        } 
        else ch+=1;
        if(ch>temp) ch=temp+1;
    }
    temp=ch;
    n >= 7 ? ch=ch : temp=6-n; 
    if(temp>ch) return temp; else return ch;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
