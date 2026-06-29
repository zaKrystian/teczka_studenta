#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <string>

int main() {
    std::vector<int> numbers = {5, 2, 8, 1, 9, 3, 7, 4, 6};

    std::cout << "--- Sortowanie i Lambdy ---\\n";
    std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a > b; // Sortowanie malejace
    });

    for (int n : numbers) std::cout << n << " ";
    std::cout << "\\n";

    std::cout << "\\n--- std::transform ---\\n";
    std::vector<int> squares(numbers.size());
    std::transform(numbers.begin(), numbers.end(), squares.begin(), [](int n) {
        return n * n;
    });

    for (int n : squares) std::cout << n << " ";
    std::cout << "\\n";

    std::cout << "\\n--- std::map ---\\n";
    std::map<std::string, int> wordCount;
    wordCount["kawa"] = 3;
    wordCount["herbata"] = 5;
    wordCount["woda"] = 10;

    for (const auto& pair : wordCount) {
        std::cout << pair.first << ": " << pair.second << "\\n";
    }

    auto it = wordCount.find("kawa");
    if (it != wordCount.end()) {
        std::cout << "Znaleziono: " << it->first << " -> " << it->second << "\\n";
    }

    return 0;
}