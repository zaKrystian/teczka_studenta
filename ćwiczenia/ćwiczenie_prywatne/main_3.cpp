#include <iostream>
#include <string>

// Szablon bazowy dla rekurencji
void printAll() {
    std::cout << "\\n";
}

// Szablon wariadyczny (Variadic Template)
template <typename T, typename... Args>
void printAll(T first, Args... args) {
    std::cout << first << " ";
    printAll(args...); // Rozwiniecie pakietu parametrow
}

// C++17 Fold Expressions
template<typename... Args>
auto sumAll(Args... args) {
    return (... + args);
}

int main() {
    std::cout << "--- Variadic Templates (printAll) ---\\n";
    printAll(1, 2.5, "Tekst", 'c', 100);
    printAll("Test", 42);

    std::cout << "\\n--- Fold Expressions (C++17) ---\\n";
    std::cout << "Suma int: " << sumAll(1, 2, 3, 4, 5) << "\\n";
    std::cout << "Suma double: " << sumAll(1.5, 2.5, 3.0) << "\\n";
    
    // Fold expression dla std::string wymaga ostroznosci z typami literalow
    using namespace std::string_literals;
    std::cout << "Konkatenacja: " << sumAll("Hello "s, "World"s, "!"s) << "\\n";

    return 0;
}