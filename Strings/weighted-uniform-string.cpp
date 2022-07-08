#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'weightedUniformStrings' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER_ARRAY queries
 */

vector<string> weightedUniformStrings(string s, vector<int> queries) {
    vector <int> weights;
    vector <string> result;
    int mul = 1;
    int temp = 0;
    for(int i=0; i<s.length(); i++) {
        temp = s[i]-'a'+1;
        if(s[i]==s[i+1]) {
            mul+=1;
            temp = (s[i]-'a'+1)*mul;
        }
        else {
            mul = 1;
        }
        weights.push_back(temp);
    }
    
    for (auto i=queries.begin(); i!=queries.end(); ++i) {
        temp = *i;
        int flag=0;
        for (auto itr = weights.begin(); itr != weights.end(); ++itr) {
        if(*itr == temp) {
            flag = 1;
            break;
            }
        }
        if (flag==0)
        result.push_back("No");
        else {
            flag = 0;
            result.push_back("Yes"); 
        }
    }
    return result;
    }

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<string> result = weightedUniformStrings(s, queries);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
