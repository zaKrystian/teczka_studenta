#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;

//funkcja generująca podziały , zastosowana rekurencja (rekursja)
void generatePartitions(int packageIndex, int highestCarNum, int n, int k, vector<int>& currentPartition, vector<vector<int>>& allPartitions) {

    if (packageIndex == n) {
        allPartitions.push_back(currentPartition); 
        return;
    }

    int limit = min(highestCarNum + 1, k);
    for (int i = 1; i <= limit; i++) {
        currentPartition[packageIndex] = i;
        generatePartitions(packageIndex + 1, max(highestCarNum, i), n, k, currentPartition, allPartitions);
    }
}

//funkcja do generowania trókąta, w zależności od n
vector<vector<long long>> getStirlingTriangle(int n) {
    vector<vector<long long>> triangle(n + 1, vector<long long>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        triangle[i][1] = 1; 
        triangle[i][i] = 1; 
        for (int j = 2; j < i; j++) {
            
            triangle[i][j] = triangle[i - 1][j - 1] + (long long)j * triangle[i - 1][j];
        }
    }
    return triangle;
}

int main() {
    //setup plików
    fstream inputFile;
    fstream outputFile;
    inputFile.open("input.txt", ios::in);
    
    //sprawdzanie, czy plik istnieje
    if (!inputFile.good()) {
        cout << "Błąd: nie znaleziono pliku" << endl; 
        return 1;
    }


    int n, k;

    //wczytanie n i k, zamknięcie pliku
    inputFile >> n;
    inputFile >> k;
    
    inputFile.close();


    //weryfikacja n i k
    if (n <= 0 || k <= 0) {
        cout << "Błąd: n i k muszę być dodatnie" << endl;
        return 1;
    }

    //stworzenie posdstawowcyh typów danych
    vector<int> partition(n); 
    vector<vector<int>> result; 

    //operacje czasu generowania -> ze wzgęgu na rekurencje w funkcji main a nie w osobnej funkcji
    auto startTime = chrono::high_resolution_clock::now();
    generatePartitions(0, 0, n, k, partition, result);
    auto endTime = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);
    double durationUs = duration.count() / 1000; 

    //zapis danych

    
    outputFile.open("output.txt", ios::out);
    //weryfikacja możliwości zapisu
    if (!outputFile.good()) {
        cout << "Błąd: brak możliwości utworenia pliku output.txt" << endl;
        return 1;
    }

   
    outputFile << "n = " << n << endl;

    outputFile << "k = " << k <<endl;

    //zapis podziałów, statystyki końcowe
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            outputFile << result[i][j];
    }
    outputFile <<endl;
}

    
    outputFile << "Czas wykonania: " << durationUs << " us\n";
    outputFile << "Łączna liczba wygenerowanych podziałów: " << result.size() << "\n";

    //trójkąt stirlinga
    outputFile << "Trójkąt Stirlinga (S(n, k)):\n";

    vector<vector<long long>> stirlingTable = getStirlingTriangle(n);
    
    outputFile << "n\\k";
    for (int j = 1; j <= n; j++) 
    {
        outputFile << "    " << j;
    }
    outputFile << "\n";

    for (int i = 1; i <= n; i++) {
        outputFile << i;
        for (int j = 1; j <= i; j++) {
            outputFile << "   " << stirlingTable[i][j];
        }
        outputFile << "\n";
    }

    outputFile.close();
    return 0;
}