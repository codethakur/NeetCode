#include"TrieArray.h"

int main() {
    // --- Test TrieArray ---
    TrieArray ta;
    ta.insert("apple");
    ta.insert("app");
    std::cout << "=== TrieArray ===" << std::endl;
    std::cout << ta.search("apple")      << "\n"; // 1
    std::cout << ta.search("app")        << "\n"; // 1
    std::cout << ta.search("ap")         << "\n"; // 0
    std::cout << ta.startsWith("app")    << "\n"; // 1
    std::cout << ta.startsWith("xyz")    << "\n"; // 0


    return 0;
}
