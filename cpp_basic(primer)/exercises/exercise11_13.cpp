// 综下所述，这些初始化pair的方法都是可行的
#include <iostream>
#include <utility>  // class Pair is in this h file
#include <vector>
#include <string>
using namespace std;
void initPair(vector<pair<string, int>> & pairs);
void makePair(vector<pair<string, int>> & pairs);
void listInit(vector<pair<string, int>> & pairs);
void structInit(vector<pair<string, int>> & pairs);

int main()
{
    vector<pair<string, int> > pairs;

    structInit(pairs);                   // different functions to construct pairs

    cout << "Your data are:" << endl;
    for (auto p : pairs) {
        cout << p.first << ' ' << p.second << endl;
    }

    return 0;
}


void initPair(vector<pair<string, int>> & pairs) {
    pair<string, int> pr;
    cout << "Enter string-int pairs (# to quit):" << endl;
    while (cin >> pr.first && pr.first != "#") {
        cin >> pr.second;
        pairs.push_back(pr);
    }
    cout << "Done." << endl;
}

void makePair(vector<pair<string, int>> & pairs) {
    string key;
    int value;
    cout << "Enter string-int pairs (# to quit):" << endl;
    while (cin >> key && key != "#") {
        cin >> value;
        pairs.push_back(make_pair(key, value));
    }
    cout << "Done." << endl;
}

void listInit(vector<pair<string, int>> & pairs) {
    string key; 
    int value;
    cout << "Enter string-int pairs (# to quit):" << endl;
    pair<string, int> pr;
    while (cin >> key && key != "#") {
        cin >> value;
        pr = {key, value};
        pairs.push_back(pr);
    }
    cout << "Done." << endl;
}

void structInit(vector<pair<string, int>> & pairs) {
    string key; 
    int value;
    cout << "Enter string-int pairs (# to quit):" << endl;
    while (cin >> key && key != "#") {
        cin >> value;
        pairs.push_back(pair<string, int> {key, value});
    }
    cout << "Done." << endl;
}