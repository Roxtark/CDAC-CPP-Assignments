#include <iostream>
using namespace std;

int main()
{
    double temperature[3][3];

    cout << "Enter temperatures for 3 floors and 3 rooms:" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "Floor " << i + 1 << ":" << endl;

        for (int j = 0; j < 3; j++)
        {
            cout << "Room " << j + 1 << ": ";
            cin >> temperature[i][j];
        }
    }

    cout << endl;
    cout << "       Room1  Room2  Room3" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "Floor " << i + 1 << " : ";

        for (int j = 0; j < 3; j++)
        {
            cout << temperature[i][j] << "   ";
        }

        cout << endl;
    }

    double hottest = temperature[0][0];
    int hottestFloor = 0;
    int hottestRoom = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (temperature[i][j] > hottest)
            {
                hottest = temperature[i][j];
                hottestFloor = i;
                hottestRoom = j;
            }
        }
    }

    cout << endl;
    cout << "Hottest Room : Floor " << hottestFloor + 1
         << ", Room " << hottestRoom + 1
         << " → " << hottest << "°C" << endl;

    double highestAverage = 0;
    int hottestFloorNumber = 0;

    for (int i = 0; i < 3; i++)
    {
        double sum = 0;

        for (int j = 0; j < 3; j++)
        {
            sum = sum + temperature[i][j];
        }

        double average = sum / 3;

        if (average > highestAverage)
        {
            highestAverage = average;
            hottestFloorNumber = i;
        }
    }

    cout << "Hottest Floor : Floor " << hottestFloorNumber + 1
         << " (avg " << highestAverage << "°C)" << endl;

    int warningRooms = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (temperature[i][j] >= 30)
            {
                warningRooms++;
            }
        }
    }

    cout << "Rooms at WARNING or above : " << warningRooms << endl;

    return 0;
}