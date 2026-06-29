#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

class IReportable {
public:
    virtual std::string getReport() const = 0;
    virtual ~IReportable() = default;
};

class Task {
public:
    std::string description;
    int priority;
    Task(std::string d, int p) : description(d), priority(p) {}
};

class EmployeeException : public std::runtime_error {
public:
    EmployeeException(const std::string& msg) : std::runtime_error(msg) {}
};

class InvalidSalaryException : public EmployeeException {
public:
    InvalidSalaryException(const std::string& msg) : EmployeeException(msg) {}
};

class Employee : public IReportable {
protected:
    std::string name;
    int id;
    double base_salary;
    std::vector<Task> tasks;

public:
    Employee(std::string n, int i, double s) : name(n), id(i), base_salary(s) {}
    virtual ~Employee() {
        std::cout << "Destruktor Employee\n";
    }

    virtual void display() const {
        std::cout << name << " ID: " << id << "\n";
        for (const auto& t : tasks) {
            std::cout << " - Task: " << t.description << " (Prio: " << t.priority << ")\n";
        }
    }

    virtual double calculate_salary() const = 0;

    void assignTask(const std::string& desc, int prio) {
        tasks.push_back(Task(desc, prio));
    }

    bool operator>(const Employee& other) const {
        return this->calculate_salary() > other.calculate_salary();
    }
};

class Manager final : public Employee {
    float bonus;
public:
    Manager(std::string n, int i, double s, float b) : Employee(n, i, s), bonus(b) {
        if (s < 4000.0) {
            throw InvalidSalaryException("Base salary below minimum for Manager");
        }
    }
    ~Manager() override {
        std::cout << "Destruktor Manager\n";
    }
    void display() const override {
        Employee::display();
        std::cout << " Bonus: " << bonus << "\n";
    }
    double calculate_salary() const final {
        return base_salary + bonus;
    }
    void scheduleMeeting() const {
        std::cout << "Meeting scheduled.\n";
    }
    std::string getReport() const override {
        return "Manager Report: " + name;
    }
};

class Developer : public Employee {
public:
    Developer(std::string n, int i, double s) : Employee(n, i, s) {}
    ~Developer() override {
        std::cout << "Destruktor Developer\n";
    }
    void display() const override {
        Employee::display();
    }
    double calculate_salary() const override {
        return base_salary;
    }
    std::string getReport() const override {
        return "Developer Report: " + name;
    }
};

void printReport(const IReportable& obj) {
    std::cout << obj.getReport() << "\n";
}

template <typename T>
T znajdzWiekszy(T a, T b) {
    return (a > b) ? a : b;
}

double podziel(double licznik, double mianownik) {
    if (mianownik == 0.0) {
        throw std::invalid_argument("Dzielenie przez zero");
    }
    return licznik / mianownik;
}

int main() {
    Employee* emp = new Manager("Jan Kowalski", 101, 5000.0, 20.0f);
    delete emp;

    try {
        Manager m("Biedny Manager", 102, 3000.0, 10.0f);
    } catch (const InvalidSalaryException& e) {
        std::cout << e.what() << "\n";
    } catch (const EmployeeException& e) {
        std::cout << e.what() << "\n";
    } catch (const std::exception& e) {
        std::cout << e.what() << "\n";
    }

    try {
        podziel(10, 0);
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << "\n";
    }

    std::vector<Employee*> staff;
    staff.push_back(new Manager("Anna Nowak", 103, 6000.0, 500.0f));
    staff.push_back(new Manager("Piotr Wisniewski", 104, 5500.0, 300.0f));
    staff.push_back(new Developer("Kamil K", 105, 4500.0));
    staff.push_back(new Developer("Ola O", 106, 4800.0));

    staff[0]->assignTask("Projekt A", 1);
    staff[2]->assignTask("Napisz kod", 2);

    double total_salary = 0;
    for (Employee* e : staff) {
        e->display();
        total_salary += e->calculate_salary();
        printReport(*e);

        Manager* m = dynamic_cast<Manager*>(e);
        if (m != nullptr) {
            m->scheduleMeeting();
        } else {
            std::cout << "To nie jest Manager\n";
        }
    }
    std::cout << total_salary << "\n";

    for (Employee* e : staff) {
        delete e;
    }

    std::cout << znajdzWiekszy(5, 10) << "\n";
    std::cout << znajdzWiekszy(3.14, 2.71) << "\n";
    std::cout << znajdzWiekszy(std::string("A"), std::string("B")) << "\n";

    Manager m1("M1", 1, 5000, 100);
    Manager m2("M2", 2, 6000, 100);
    Manager m3 = znajdzWiekszy(m1, m2);
    m3.display();

    return 0;
}