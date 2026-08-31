#include <iostream>
using namespace std;

int main()
{
    int statusReg = 0b10110001;
    int controlReg = 0b00000000;
    int dataReg = 0b11001010;

    const int* regPtr1 = &statusReg;

    cout << "Status Register : " << *regPtr1 << endl;

    // *regPtr1 = 10;       // Error: cannot change value through const pointer
    // regPtr1 = &dataReg;  // Error: pointer can be changed, so this is actually allowed

    int* const regPtr2 = &controlReg;

    *regPtr2 = 25;

    cout << "Control Register : " << *regPtr2 << endl;

    // regPtr2 = &dataReg;  // Error: const pointer cannot point to another address

    const int* const regPtr3 = &statusReg;

    cout << "ROM/Status Register : " << *regPtr3 << endl;

    // *regPtr3 = 50;       // Error: cannot change value through const pointer
    // regPtr3 = &dataReg;  // Error: const pointer cannot point to another address

    return 0;
}