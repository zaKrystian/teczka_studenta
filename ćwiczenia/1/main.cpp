#include <iostream>
#include <string>

//zad 1 & 4

class Employee {
public:
    const int id;
    std::string name;
    static int active_instances;

    
    
    Employee(int emp_id, std::string emp_name) {
        id = emp_id; 
        name = emp_name;
        active_instances++;
    }
    */

    // POPRAWNY KONSTRUKTOR (Zadanie 1d): Użycie listy inicjalizacyjnej.
    Employee(int emp_id, std::string emp_name) : id(emp_id), name(emp_name) {
        active_instances++; // Zadanie 4d
    }

    ~Employee() {
        active_instances--; // Zadanie 4d
    }

    static int get_active_instances() { // Zadanie 4e
        return active_instances;
    }
};

//zad 2
int Employee::active_instances = 0; 

class Window {
public:
    int width;
    int height;
    std::string title;

    // Główny konstruktor
    Window(int w, int h, std::string t) : width(w), height(h), title(t) {}

    // Delegowanie do głównego (wymóg: brak kopiowania kodu)
    Window(int w, int h) : Window(w, h, "Untitled") {}

    
    Window() : Window(800, 600) {}
};

//zad 3

class Buffer {
private:
    int* data;
    int size;
public:
    Buffer(int s) : size(s) { // Zadanie 3c
        data = new int[size]; //
        std::cout << "Allocated " << size << "\n"; //
    }

    ~Buffer() { // Zadanie 3d
        delete[] data; //
        std::cout << "Deallocated\n"; //
    }
};

// ZADANIE 9: Klasa abstrakcyjna (definiowanie interfejsu)
class AbstractEmployee {
protected: // ZADANIE 6: Dostęp w hierarchii
    std::string name;
    int id;

public:
    AbstractEmployee(std::string n, int i) : name(n), id(i) {}

    // ZADANIE 8 i 9: Czysto wirtualne metody i wirtualny destruktor
    virtual void display() = 0; 
    virtual double calculate_salary() const = 0; 
    virtual ~AbstractEmployee() = default; 
};

// zadanie 5&9
class Manager : public AbstractEmployee {
private:
    float bonus_percentage;
    double base_salary;

public:
    Manager(std::string n, int i, double base, float bonus) 
        : AbstractEmployee(n, i), base_salary(base), bonus_percentage(bonus) {} //

    // Przesłonięcie wirtualnych metod (Zadanie 8 i 9)
    void display() override {
        // Dostęp do protected fields `name` i `id`
        std::cout << "Manager: " << name << ", ID: " << id 
                  << ", Bonus: " << bonus_percentage << "%\n"; 
    }

    double calculate_salary() const override { //
        return base_salary + (base_salary * (bonus_percentage / 100.0f));
    }
};

int main() {
    //zad3
    std::cout << "Start\n"; //
    { // Sztuczny zakres
        Buffer buf(10); //
    }
    std::cout << "End\n";

    // zadanie 6c
    Manager mgr("Alice", 1, 5000.0, 10.0f);
    

    // --- zad 7 i 8 (Polimorfizm) ---
    
    AbstractEmployee* team[1];
    team[0] = new Manager("Bob", 2, 6000.0, 15.0f); //
    
    
    team[0]->display(); 

    //zadanie 9c 

    delete team[0]; 

    return 0;
}