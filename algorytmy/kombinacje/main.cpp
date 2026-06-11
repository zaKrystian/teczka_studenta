#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <chrono>

using namespace std;


void showIngredients(string ingredients[], int n);
long long classicGenerate(int n, int k, int ingredients[], int** resultTab);
long long sembaGenerate(int n, int k, int ingredients[], int** resultTab);
void compareGeneration( int n, int ingredients[]);
void pascalTriangle(int n);
int countCombinations(int n, int k);

int main() {
    //deklaracja zmiennych: wyboru, czasu działania algorymum, kombinacji liczbowe, tabelka 2d), kombinacji nazwanych (tabelka 2d), n, 
    //k = -1 (sprawdzane później w kodzie przy porównaniu aby nie generować ponownie)
    //wszystkie tablice oraz zmienne  zadeklarowane w main - kazda funkcja może z nich korzystać, bez konieczności zwracania danych
    long long timeOfGeneration, timeOfGenerationSemba;
    int choose;
    int **combinationsClassic;
    string **combinationsClassicNames;
    int **combinationsSemba;
    string **combinationsSembaNames;
    int n = 8;
    int k = -1;
    int numOfCombinations;

    //wypełnienie tablicy dla kombinacji
    int ingredients[8];
    for (int i = 0; i < n; i++) {
        ingredients[i] = i + 1;
    }

    //tablica zawierająca nazwy składników
    string ingredientsNames[] = {"Ser", "Szynka", "Pieczarki", "Oliwki", "Kukurydza", "Papryka", "Cebula", "Rukola"};

    //zmienne running - odpowiada za działanie programu i wyjści gdy naciśniemy 0
    bool running = true;
    while (running) {
        //output początkowy
        cout << "\n########### ------------ Pizzeria 'Mamma Mia' ------------ ###########" << endl;
        cout << "[1] Wyświetl dostępne składniki" << endl;
        cout << "[2] Generuj kombinacje składników - algorytm klasyczny" << endl;
        cout << "[3] Generuj kombinacje składników - algorytm Semby" << endl;
        cout << "[4] Porównaj kolejność generacji obu algorytmów" << endl;
        cout << "[5] Trójkat Pascala" << endl;
        cout << "[0] Wyjscie" << endl;

        //cin guardian (stackoverflow)
        while (true) {
            cout << "> Wybor: ";
            cin >> choose;

            if (cin.fail()) {
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                cout << "# Błędny input! Podaj liczbe." << endl;
            } else {
                break;
            }
        }

        //główny switch programu - 1 - składniki, 2 - klasyczny generate, 3 - semba, 4 -  porównanie, 5 - pascal, 6 -koniec

        switch (choose) {
            case 1:
                showIngredients(ingredientsNames, n);
                break;

            case 2:
                // ilosc skadników, to do: osobna funkcja
                while (true) {
                    cout <<"############################"<<endl;
                    cout << "> Wybierz ilosc skladnikow: ";
                    cin >> k;
                    if (k <= n && k >= 1) break;
                    else cout << "# Nieprawidlowa liczba. Sprobuj ponownie" << endl;
                }
                //numer wierszy zwrócony za pomocą zewnętrznej funkcji
                int numRows;
                numRows = countCombinations(n, k);

                //inicjalizacja dwuwymiarowej tablicy: dla numerów wierszy k elementów, tablica n*k
                combinationsClassic = new int*[numRows];
                for (int i = 0; i < numRows; i++) {
                    combinationsClassic[i] = new int[k];
                }

                 
                //czas działania algorytmu zwraca funkcja
                timeOfGeneration = classicGenerate(n, k, ingredients, combinationsClassic);

                //zapisanie macierzy imiennej z nazwami składników
                combinationsClassicNames = new string*[numRows];
                for (int i = 0; i < numRows; i++) {
                    combinationsClassicNames[i] = new string[k];
                    for (int j = 0; j < k; j++) {
                        switch(combinationsClassic[i][j]){
                            case 1:
                                combinationsClassicNames[i][j]="Ser";
                                break;   
                            case 2:
                                combinationsClassicNames[i][j]="Szynka";
                                break;   
                            case 3:
                                combinationsClassicNames[i][j]="Pieczarki";
                                break;   
                            case 4:
                                combinationsClassicNames[i][j]="Oliwki";
                                break; 
                            case 5:
                                combinationsClassicNames[i][j]="Kukurydza";
                                break;     
                            case 6:
                                combinationsClassicNames[i][j]="Papryka";
                                break;   
                            case 7:
                                combinationsClassicNames[i][j]="Cebula";
                                break;   
                            case 8:
                                combinationsClassicNames[i][j]="Rukola";
                                break;   
                        }
                    }
                }

                //wypisanie wyniku
                cout << "\n--- Wszystkie kombinacje pizzy:" << endl;
                for (int i = 0; i < numRows; i++) {

                    cout << i + 1 << "."<< (i<10? "  " : " ")<< "(";

                    for (int j = 0; j < k; j++) {
                        cout << combinationsClassic[i][j] << (j == k - 1 ? "" : ", ");
                    }
                    cout << ") (";
                    for (int j = 0; j < k; j++) {
                        cout << combinationsClassicNames[i][j] << (j == k - 1 ? "" : ", ");
                    }
                    cout << ")" << endl;
                }

                numOfCombinations = countCombinations(n,k);
                cout<<"Wygenerowanych kombinacjji:         "<<numRows<<endl;
                cout<<"Ilość kombinacji oblizona ze wzoru: "<<numOfCombinations<<endl;
                cout<<"Czas potrzebny na generowanie [ns]: "<<timeOfGeneration<<endl;
                
                
                //usuwanie tablicy,  zwalnianie miejsca
                for (int i = 0; i < numRows; i++) delete[] combinationsClassic[i];
                delete[] combinationsClassic;
                break;

            case 3:

                while (true) {
                    cout << "############################"<<endl;;
                    cout << "> Wybierz ilosc skladnikow: ";
                    cin >> k;
                    if (k <= n && k >= 1) break;
                    else cout << "# Nieprawidlowa liczba. Sprobuj ponownie\n" << endl;
                }
                numRows = countCombinations(n, k);

                
                combinationsSemba = new int*[numRows];
                for (int i = 0; i < numRows; i++) {
                    combinationsSemba[i] = new int[k];
                }
                
                timeOfGenerationSemba = sembaGenerate(n, k, ingredients, combinationsSemba);

                combinationsSembaNames = new string*[numRows];
                for (int i = 0; i < numRows; i++) {
                    combinationsSembaNames[i] = new string[k];
                    for (int j = 0; j < k; j++) {
                        switch(combinationsSemba[i][j]){
                            case 1:
                                combinationsSembaNames[i][j]="Ser";
                                break;   
                            case 2:
                                combinationsSembaNames[i][j]="Szynka";
                                break;   
                            case 3:
                                combinationsSembaNames[i][j]="Pieczarki";
                                break;   
                            case 4:
                                combinationsSembaNames[i][j]="Oliwki";
                                break; 
                            case 5:
                                combinationsSembaNames[i][j]="Kukurydza";
                                break;     
                            case 6:
                                combinationsSembaNames[i][j]="Papryka";
                                break;   
                            case 7:
                                combinationsSembaNames[i][j]="Cebula";
                                break;   
                            case 8:
                                combinationsSembaNames[i][j]="Rukola";
                                break;   
                        }
                    }
                }

                cout << "\n--- Wszystkie kombinacje pizzy:" << endl;
                for (int i = 0; i < numRows; i++) {

                    cout << i + 1 << "."<< (i<10? "  " : " ")<< "(";

                    for (int j = 0; j < k; j++) {
                        cout << combinationsSemba[i][j] << (j == k - 1 ? "" : ", ");
                    }
                    cout << ") (";
                    for (int j = 0; j < k; j++) {
                        cout << combinationsSembaNames[i][j] << (j == k - 1 ? "" : ", ");
                    }
                    cout << ")" << endl;
                }

                numOfCombinations = countCombinations(n,k);
                cout<<"Wygenerowanych kombinacjji:         "<<numRows<<endl;
                cout<<"Ilość kombinacji obliczona ze wzoru: "<<numOfCombinations<<endl;
                cout<<"Czas potrzebny na generowanie [ns]: "<<timeOfGenerationSemba<<endl;
                

               
                for (int i = 0; i < numRows; i++) delete[] combinationsSemba[i];
                delete[] combinationsSemba;
                break;
            case 4:
                compareGeneration(n, ingredients);
                break;
            case 5:
                pascalTriangle(n);
                break;

            case 0:
            ///wyłączenie działania programu
                running = false;
                break;

            default:
                cout << "# Wybrano nieprawidlową liczbę." << endl;
                
                break;
        }
    }
    return 0;
}


void showIngredients(string ingredients[], int n) {
    //wypisane składników - standardowy for
    cout << "\n--- Lista skladnikow: " << endl;
    for (int i = 0; i < n ; i++) {
        cout << i + 1 << ". " << ingredients[i] << endl;
    }
}

long long classicGenerate(int n, int k, int ingredients[], int** resultTab) {

    
    //czas zapiwywania
  
 
    //realizacja algorytmu kasycznego z czasem, zapisywanie do tablicy 2d
    auto startTime= std::chrono::high_resolution_clock::now();
    int counter = 0;
    int* c = new int[k + 1];
    for (int i = 1; i <= k; i++) {
        c[i] = i;
    }
    while (true) {
        for (int j = 1; j <= k; j++) {
            resultTab[counter][j - 1] = ingredients[c[j] - 1];
        }
        
        counter++;
        int i = k;
        while (i > 0 && c[i] == n - k + i) {
            i--;
        }
        if (i == 0) break;
        c[i] = c[i] + 1;
        for (int j = i + 1; j <= k; j++) {
            c[j] = c[j - 1] + 1;
        }
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    long long totalDuration = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count();
    delete[] c;

    
    

    return totalDuration;

}

long long sembaGenerate(int n, int k, int ingredients[], int** resultTab) {
    //podobnie tutaj, jak algorytm klasyczny - start zeganra
    
    
    int counter = 0;
    int* c = new int[k + 2];

    auto startTime= std::chrono::high_resolution_clock::now();
    
    for (int i = 1; i <= k; i++) {
        c[i] = i;
    }
    c[k + 1] = n + 1;
    
    while (true) {
        
        for (int m = 1; m <= k; m++) {
            resultTab[counter][m - 1] = ingredients[c[m] - 1];
        }
        
        
        counter++;

        int j = 1;
        while (j <= k && c[j] + 1 == c[j + 1]) {
            c[j] = j;
            j = j + 1;
        }

        if (j > k) break;
        
        c[j] = c[j] + 1;
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    long long totalDuration = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count();

    delete[] c;
    
    

    return totalDuration;

}

int countCombinations(int n, int k) {
    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;
    if (k > n / 2) k = n - k;
    int res = 1;
    for (int i = 1; i <= k; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

void compareGeneration(int n, int ingredients[]) {

    long long timeOfGeneration, timeOfGenerationSemba;
    int choose;

    int **combinationsClassic;
    int **combinationsSemba;

    int numRows;

   
   

    int k = -1;
    int numOfCombinations;
    while (true) {
    
        cout << "> Wybierz ilosc skladnikow: ";
        cin >> k;
        if (k <= n && k >= 1) break;
        else cout << "# Nieprawidlowa liczba. Sprobuj ponownie\n" << endl;
    }

    numRows= countCombinations(n, k);

    combinationsClassic = new int*[numRows];

    for (int i = 0; i < numRows; i++) combinationsClassic[i] = new int[k];
        

     combinationsSemba = new int*[numRows];
    for (int i = 0; i < numRows; i++) combinationsSemba[i] = new int[k];
    
    timeOfGeneration = classicGenerate(n, k, ingredients, combinationsClassic);
    timeOfGenerationSemba = sembaGenerate(n, k, ingredients, combinationsSemba);

    

    cout << "--- Wszystkie kombinacje pizzy:" << endl;
    cout << "Algorytm klasyczny      |     Algorytm Semby" << endl;
    for (int i = 0; i < numRows; i++) {

            cout << i + 1 << "."<< (i<10? "  " : " ")<< "(";

            for (int j = 0; j < k; j++) {
                cout << combinationsClassic[i][j] << (j == k - 1 ? "" : ", ");
            }
            cout << ")             "<< i + 1 << "."<< (i<10? "  " : " ")<< "(";;
            for (int j = 0; j < k; j++) {
                cout << combinationsSemba[i][j] << (j == k - 1 ? "" : ", ");
            }
            cout << ")" << endl;
            }

    cout<<"Czas (klasyczny): " << timeOfGeneration << "ns\nCzas (semba): " <<timeOfGenerationSemba<<"ns";
    cout<<"\nIlość kombinacji wyliczona ze wzoru: "<<numRows<<endl;
    
    
}

void pascalTriangle(int n) {
    cout << "\n--- Trojkat Pascala (do wiersza n = " << n << ") ---\n";
    // Tabela 2D
    //zamina wektrów na dynamiczne tablice dwuwymiarowe
    int** pt; 
    pt = new int*[n+1];
    for (int i = 0; i < n+1; i++)
    {
        pt[i]=new int [n+1];
    }
    
    
   
    
    for (int i = 0; i <= n; i++) {
        // Obliczamy odpowiednią ilość znaków ułatwiającą czytanie jako trójkąt, np offset o (n - i)*3
        for (int spaces = 0; spaces < (n - i); spaces++) {
            cout << "   ";
        }
        
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                pt[i][j] = 1;
            } else {
                pt[i][j] = pt[i - 1][j - 1] + pt[i - 1][j];
            }
            cout << left << setw(6) << pt[i][j];
        }
        cout << "\n";
    }
}


