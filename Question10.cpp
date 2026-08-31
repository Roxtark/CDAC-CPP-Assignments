#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Employee
{
private:
    int empId;
    string name;
    string department;
    char grade;
    double basicSalary;
    bool isActive;

    static int employeeCount;

public:
    Employee()
    {
        empId = 1001 + employeeCount;
        name = "";
        department = "";
        grade = 'D';
        basicSalary = 0;
        isActive = true;
        employeeCount++;
    }

    void setName(const string& n)
    {
        if (n.empty())
        {
            cout << "ERROR: Name cannot be empty." << endl;
        }
        else
        {
            name = n;
        }
    }

    void setDepartment(const string& dept)
    {
        if (dept == "Engineering" || dept == "HR" ||
            dept == "Finance" || dept == "Operations")
        {
            department = dept;
        }
        else
        {
            cout << "ERROR: '" << dept
                 << "' is not a registered department." << endl;
        }
    }

    void setGrade(char g)
    {
        if (g == 'A' || g == 'B' || g == 'C' || g == 'D')
        {
            grade = g;
        }
        else
        {
            cout << "ERROR: Invalid grade '" << g
                 << "'. Accepted values: A, B, C, D." << endl;
        }
    }

    void setBasicSalary(double salary)
    {
        if (salary > 10000 && salary < 500000)
        {
            basicSalary = salary;
        }
        else
        {
            cout << "ERROR: Salary must be between Rs.10,000 and Rs.5,00,000. Value rejected." << endl;
        }
    }

    void deactivate()
    {
        isActive = false;
    }

    int getEmpId() const
    {
        return empId;
    }

    string getName() const
    {
        return name;
    }

    string getDepartment() const
    {
        return department;
    }

    char getGrade() const
    {
        return grade;
    }

    double getBasicSalary() const
    {
        return basicSalary;
    }

    bool getIsActive() const
    {
        return isActive;
    }

    double computeAllowances() const
    {
        if (grade == 'A')
        {
            return basicSalary * 0.40;
        }
        else if (grade == 'B')
        {
            return basicSalary * 0.30;
        }
        else if (grade == 'C')
        {
            return basicSalary * 0.20;
        }
        else
        {
            return basicSalary * 0.10;
        }
    }

    double computeGrossSalary() const
    {
        return basicSalary + computeAllowances();
    }

    double computeTax() const
    {
        double gross = computeGrossSalary();

        if (gross <= 50000)
        {
            return 0;
        }
        else if (gross <= 100000)
        {
            return (gross - 50000) * 0.10;
        }
        else
        {
            return 5000 + (gross - 100000) * 0.20;
        }
    }

    double computeNetSalary() const
    {
        return computeGrossSalary() - computeTax();
    }

    void printPayslip() const
    {
        cout << "============================================" << endl;
        cout << "EMPLOYEE PAYSLIP - AUG 2026" << endl;
        cout << "============================================" << endl;

        cout << "Emp ID       : " << empId << endl;
        cout << "Name         : " << name << endl;
        cout << "Department   : " << department << endl;
        cout << "Grade        : " << grade << endl;
        cout << "Status       : " << (isActive ? "Active" : "Inactive") << endl;

        cout << "--------------------------------------------" << endl;

        cout << fixed << setprecision(2);

        cout << "Basic Salary : Rs. " << basicSalary << endl;

        if (grade == 'A')
        {
            cout << "Allowances (40%) : Rs. " << computeAllowances() << endl;
        }
        else if (grade == 'B')
        {
            cout << "Allowances (30%) : Rs. " << computeAllowances() << endl;
        }
        else if (grade == 'C')
        {
            cout << "Allowances (20%) : Rs. " << computeAllowances() << endl;
        }
        else
        {
            cout << "Allowances (10%) : Rs. " << computeAllowances() << endl;
        }

        cout << "Gross Salary : Rs. " << computeGrossSalary() << endl;

        cout << "--------------------------------------------" << endl;

        cout << "Tax Deduction : Rs. " << computeTax() << endl;
        cout << "Net Salary    : Rs. " << computeNetSalary() << endl;

        cout << "============================================" << endl;
    }

    static int getEmployeeCount()
    {
        return employeeCount;
    }

    void acceptDetails()
    {
        string n;
        string dept;
        char g;
        double salary;

        cout << "Enter name: ";
        cin.ignore();
        getline(cin, n);

        while (n.empty())
        {
            setName(n);
            cout << "Enter name: ";
            getline(cin, n);
        }

        setName(n);

        cout << "Enter department: ";
        getline(cin, dept);

        while (dept != "Engineering" && dept != "HR" &&
               dept != "Finance" && dept != "Operations")
        {
            setDepartment(dept);
            cout << "Enter department: ";
            getline(cin, dept);
        }

        setDepartment(dept);

        cout << "Enter grade: ";
        cin >> g;

        while (g != 'A' && g != 'B' && g != 'C' && g != 'D')
        {
            setGrade(g);
            cout << "Enter grade: ";
            cin >> g;
        }

        setGrade(g);

        cout << "Enter basic salary: ";
        cin >> salary;

        while (salary <= 10000 || salary >= 500000)
        {
            setBasicSalary(salary);
            cout << "Enter basic salary: ";
            cin >> salary;
        }

        setBasicSalary(salary);
    }
};

int Employee::employeeCount = 0;

int main()
{
    Employee e1;
    Employee* e2 = new Employee();
    Employee* e3 = new Employee();

    e1.acceptDetails();
    e2->acceptDetails();
    e3->acceptDetails();

    // e1.empId = 999;         // Error: empId is private
    // e1.basicSalary = -1000; // Error: basicSalary is private

    e1.printPayslip();
    e2->printPayslip();
    e3->printPayslip();

    e3->deactivate();

    if (!e3->getIsActive())
        cout << e3->getName() << " is no longer active. Payroll skipped." << endl;

    cout << "Total Employees : " << Employee::getEmployeeCount() << endl;

    delete e2;
    delete e3;

    return 0;
}