#include"TrieArray.h"
#include"TrieNodeVec.h"
#include"TrieNodeMap.h"
#include <iostream>

using namespace std;


int main() {
    // --- Test TrieArray ---
    TrieArray ta;
    ta.insert("apple");
    ta.insert("app");
    cout << "=== TrieArray ===" << endl;
    cout << ta.search("apple")      << "\n"; // 1
    cout << ta.search("app")        << "\n"; // 1
    cout << ta.search("ap")         << "\n"; // 0
    cout << ta.startsWith("app")    << "\n"; // 1
    cout << ta.startsWith("xyz")    << "\n"; // 0

    // --- Test TrieVec ---
    TrieVec tv;
    tv.insert("apple");
    tv.insert("app");
    cout << "\n=== TrieVec ===" << endl;
    cout << tv.search("apple")      << "\n"; // 1
    cout << tv.search("app")        << "\n"; // 1
    cout << tv.search("ap")         << "\n"; // 0
    cout << tv.startsWith("app")    << "\n"; // 1
    cout << tv.startsWith("xyz")    << "\n"; // 0

    // --- Test TrieMap ---
    TrieMap tm;
    tm.insert("apple");
    tm.insert("app");
    cout << "\n=== TrieMap ===" << endl;
    cout << tm.search("apple")      << "\n"; // 1
    cout << tm.search("app")        << "\n"; // 1
    cout << tm.search("ap")         << "\n"; // 0
    cout << tm.startsWith("app")    << "\n"; // 1
    cout << tm.startsWith("xyz")    << "\n"; // 0

    return 0;
}
