#include <iostream>
using namespace std;

void resetSensorPairV1(int reading1, int reading2)
{
    int temp = reading1;
    reading1 = reading2;
    reading2 = temp;
}

void resetSensorPairV2(int& reading1, int& reading2)
{
    int temp = reading1;
    reading1 = reading2;
    reading2 = temp;
}

void resetSensorPairV3(int* reading1, int* reading2)
{
    int temp = *reading1;
    *reading1 = *reading2;
    *reading2 = temp;
}

int main()
{
    /*
    V1 uses call by value, so copies of the variables are passed.
    The function swaps the copies instead of the original variables.
    Therefore, the original values in main() remain unchanged.
    */

    int A = 55;
    int B = 12;

    cout << "--- V1: Call by Value ---" << endl;
    cout << "Before : A=" << A << " B=" << B << endl;

    resetSensorPairV1(A, B);

    cout << "After : A=" << A << " B=" << B << endl;

    cout << endl;

    cout << "--- V2: Call by Reference ---" << endl;
    cout << "Before : A=" << A << " B=" << B << endl;

    resetSensorPairV2(A, B);

    cout << "After : A=" << A << " B=" << B << endl;

    cout << endl;

    cout << "--- V3: Call by Pointer ---" << endl;
    cout << "Before : A=" << A << " B=" << B << endl;

    resetSensorPairV3(&A, &B);

    cout << "After : A=" << A << " B=" << B << endl;

    return 0;
}