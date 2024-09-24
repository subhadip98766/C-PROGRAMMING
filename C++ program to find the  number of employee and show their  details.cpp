#include <iostream>
#include <vector>
using namespace std;

class Employee {
private:
    int empID;
    string name;
    float salary;
    static int count; // Static variable to count the number of employees

public:
    Employee(int id, string n, float s) : empID(id), name(n), salary(s) {
        count++;
    }

    void display() const {
        cout << "Employee ID: " << empID << ", Name: " << name << ", Salary: " << salary << endl;
    }

    static int getCount() {
        return count;
    }
};

// Initialize static member of class Employee
int Employee::count = 0;

int main() {
    vector<Employee> employees;
    int id;
    string name;
    float salary;
    char choice;

    do {
        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Employee Name: ";
        cin.ignore(); // To ignore the newline character left in the buffer
        getline(cin, name);
        cout << "Enter Employee Salary: ";
        cin >> salary;

        employees.emplace_back(id, name, salary);

        cout << "Do you want to add another employee? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "\nTotal number of employees: " << Employee::getCount() << endl;
    cout << "Employee Details:\n";
    for (const auto& emp : employees) {
        emp.display();
    }

    return 0;
}
