#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'largestRectangle' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY h as parameter.
 */

long largestRectangle(vector<int> h) {
    long maxHeight = h[0];
    int n = h.size();
    
    vector<int> menorIzquierda (n, -1);
    vector<int> menorDerecha (n, n);

    for (int i = 1; i < n; i++) {
        int begin = i-1, actual = h[begin];
        while (begin >= 0 && actual >= h[i]) {
            begin = menorIzquierda[begin];
            if (begin == -1) break;
            actual = h[begin];
        }
        menorIzquierda[i] = begin;
    }
    
    for (int i = n-1; i >= 0; i--) {
        if (i != n-1) {
            int end = i+1, actual = h[end];
            while (end <= n && actual >= h[i]) {
                end = menorDerecha[end];
                if (end == n) break;
                actual = h[end];
            }
            menorDerecha[i] = end;
        }
        //cout << i << " " << menorIzquierda[i] << " " << menorDerecha[i] << endl;
        maxHeight = max(maxHeight, long(menorDerecha[i] - menorIzquierda[i] - 1) * long(h[i]));
    }
       
    return maxHeight;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split(rtrim(h_temp_temp));

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

    fout << result << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
