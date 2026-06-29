#include <iostream>
#include <memory>
#include <vector>
#include <string>

class Sensor {
    std::string name;
public:
    Sensor(std::string n) : name(n) {
        std::cout << "Sensor " << name << " zainicjalizowany.\\n";
    }
    ~Sensor() {
        std::cout << "Sensor " << name << " zniszczony.\\n";
    }
    void readData() const {
        std::cout << "Odczyt danych z: " << name << "\\n";
    }
};

class Dashboard {
    std::shared_ptr<Sensor> primarySensor;
public:
    Dashboard(std::shared_ptr<Sensor> sensor) : primarySensor(sensor) {}
    void display() const {
        std::cout << "Dashboard: ";
        primarySensor->readData();
    }
};

int main() {
    std::cout << "--- std::unique_ptr ---\\n";
    {
        std::unique_ptr<Sensor> uPtr = std::make_unique<Sensor>("Temperatura");
        uPtr->readData();
        // std::unique_ptr<Sensor> uPtr2 = uPtr; // Błąd kompilacji - brak kopiowania
        std::unique_ptr<Sensor> uPtrMoved = std::move(uPtr); // Transfer wlasnosci
        if (!uPtr) std::cout << "uPtr jest teraz pusty.\\n";
        uPtrMoved->readData();
    } // Sensor niszczony automatycznie

    std::cout << "\\n--- std::shared_ptr ---\\n";
    {
        std::shared_ptr<Sensor> sPtr = std::make_shared<Sensor>("Cisnienie");
        std::cout << "Licznik odwolan: " << sPtr.use_count() << "\\n";
        
        Dashboard dash1(sPtr);
        Dashboard dash2(sPtr);
        
        std::cout << "Licznik odwolan po przekazaniu: " << sPtr.use_count() << "\\n";
        dash1.display();
        dash2.display();
    } // Sensor niszczony, gdy licznik spada do 0

    return 0;
}