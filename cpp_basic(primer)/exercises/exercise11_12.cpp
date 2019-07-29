#include <iostream>
#include <utility>
#include <vector>
#include <string>
using namespace std;

int main()
{
    pair<string, int> pr;
    vector<pair<string, int> > pairs;
    cout << "Enter string-int pairs (# to quit):" << endl;
    while (cin >> pr.first && pr.first != "#") {
        cin >> pr.second;
        pairs.push_back(pr);
    }
    cout << "Done." << endl;

    cout << "Your data are:" << endl;
    for (pair<string, int> p : pairs) {
        cout << p.first << ' ' << p.second << endl;
    }

    return 0;
}