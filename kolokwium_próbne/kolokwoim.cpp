#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <algorithm>

// --- Zadanie 1 – Klasa bazowa i enkapsulacja ---
class BaseDevice {
private:
    int id_;
public:
    explicit BaseDevice(int id) : id_(id) {}
    virtual ~BaseDevice() = default;
    int get_id() const { return id_; }
    virtual void process() = 0;
};

// --- Zadanie 2 – Dziedziczenie + wyjątki ---
class VoltageMonitor : public BaseDevice {
private:
    double voltage_;
public:
    VoltageMonitor(int id, double v) : BaseDevice(id), voltage_(v) {}
    
    void set_voltage(double v) {
        if (v < 0) throw std::runtime_error("Błąd: Ujemne napięcie!");
        voltage_ = v;
    }
    
    void process() override {
        std::cout << "VoltageMonitor ID: " << get_id() << " pracuje z napieciem: " << voltage_ << "V" << std::endl;
    }
};

// --- Zadanie 3 – Zarządzanie pamięcią (Rule of Three) ---
class DataBuffer {
private:
    double* data_;
    int size_;
public:
    DataBuffer(int size) : size_(size), data_(new double[size]{0}) {}
    
    ~DataBuffer() { delete[] data_; }
    
    DataBuffer(const DataBuffer& other) : size_(other.size_), data_(new double[other.size_]) {
        std::copy(other.data_, other.data_ + size_, data_);
    }
    
    DataBuffer& operator=(const DataBuffer& other) {
        if (this != &other) {
            double* newData = new double[other.size_];
            std::copy(other.data_, other.data_ + other.size_, newData);
            delete[] data_;
            data_ = newData;
            size_ = other.size_;
        }
        return *this;
    }
    
    void set(int index, double value) { if(index >= 0 && index < size_) data_[index] = value; }
    double get(int index) const { return (index >= 0 && index < size_) ? data_[index] : 0.0; }
};

// --- Zadanie 4 – Interfejs ---
class ILogger {
public:
    virtual void log() const = 0;
    virtual ~ILogger() = default;
};

class SmartDevice : public VoltageMonitor, public ILogger {
public:
    SmartDevice(int id, double v) : VoltageMonitor(id, v) {}
    void log() const override {
        std::cout << "SmartDevice (ID: " << get_id() << ") raportuje stan OK." << std::endl;
    }
};

// --- Zadanie 5 – Szablony ---
template <typename T, int N>
bool find_first(T (&arr)[N], T value) {
    for (int i = 0; i < N; ++i) {
        if (arr[i] == value) return true;
    }
    return false;
}

int main() {
    // Testowanie Zadania 1 i 2
    try {
        BaseDevice* dev = new SmartDevice(101, 230.0);
        dev->process();
        static_cast<SmartDevice*>(dev)->log();
        
        static_cast<VoltageMonitor*>(dev)->set_voltage(-5.0); // Wywoła wyjątek
        
        delete dev;
    } catch (const std::exception& e) {
        std::cerr << "Złapano wyjatek: " << e.what() << std::endl;
    }

    // Testowanie Zadania 3
    DataBuffer db1(5);
    db1.set(0, 10.5);
    DataBuffer db2 = db1; // Kopiowanie
    db2.set(0, 99.9);
    std::cout << "Oryginal: " << db1.get(0) << ", Kopia: " << db2.get(0) << std::endl;

    // Testowanie Zadania 5
    int arr[] = {1, 2, 3, 4, 5};
    if (find_first(arr, 3)) std::cout << "Znaleziono wartosc 3." << std::endl;

    return 0;
}