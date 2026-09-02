#include <iostream>
#include <string>
using namespace std;

class Patient
{
private:
    int patientId;
    string name;
    int age;
    string ward;
    const string bloodGroup;

public:
    Patient() : patientId(0), name("Unknown"), age(0), ward("General"), bloodGroup("O+")
    {
        cout << "[Constructor] Default patient registered." << endl;
    }

    Patient(int id, const string& name) : patientId(id), name(name), age(0), ward("General"), bloodGroup("O+")
    {
        cout << "[Constructor] Emergency: " << name << endl;
    }

    Patient(int id, const string& name, int age, const string& ward, const string& bg)
        : patientId(id), name(name), age(age), ward(ward), bloodGroup(bg)
    {
        cout << "[Constructor] Full admission: " << name << endl;
    }

    ~Patient()
    {
        cout << "[Destructor] Patient " << name << " discharged." << endl;
    }

    void displayRecord() const
    {
        cout << "\nPatient Record:" << endl;
        cout << "ID : " << patientId << endl;
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Ward : " << ward << endl;
        cout << "Blood Grp : " << bloodGroup << endl;
    }

    void transferWard(const string& newWard)
    {
        cout << "Ward Transfer: " << name << " -> " << newWard << endl;
        ward = newWard;
    }
};

int main()
{
    {
        Patient p1(1001, "Meera Joshi", 34, "Cardiology", "B+");

        Patient p2(1002, "Raj Patel");

        Patient p3;

        Patient patients[4];

        for (int i = 0; i < 4; i++)
        {
            patients[i].displayRecord();
        }

        patients[0].transferWard("ICU");

        cout << "\nDeleting dynamic array..." << endl;

        Patient* dynamicPatients = new Patient[4];

        for (int i = 0; i < 4; i++)
        {
            dynamicPatients[i].displayRecord();
        }

        dynamicPatients[0].transferWard("ICU");

        delete[] dynamicPatients;

        cout << "\nEnd of scope..." << endl;
    }

    return 0;
}