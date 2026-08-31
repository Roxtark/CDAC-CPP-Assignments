#include <iostream>
using namespace std;

int main()
{
    int n;
    double readings[100];

    cout << "Enter number of readings: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> readings[i];
    }

    cout << "Readings entered : " << n << endl;

    cout << "Valid readings : ";

    int skipped = 0;

    for (int i = 0; i < n; i++)
    {
        if (readings[i] < 0)
        {
            skipped++;
            continue;
        }

        cout << readings[i] << " ";
    }

    cout << endl;
    cout << "Skipped (errors) : " << skipped << endl;

    for (int i = 0; i < n; i++)
    {
        if (readings[i] >= 45)
        {
            cout << "First CRITICAL : Index " << i << " → "
                 << readings[i] << "°C" << endl;
            break;
        }
    }

    double min = 0;
    double max = 0;
    double sum = 0;
    int count = 0;

    int normal = 0;
    int warning = 0;
    int critical = 0;
    int shutdown = 0;

    for (int i = 0; i < n; i++)
    {
        if (readings[i] < 0)
        {
            continue;
        }

        if (count == 0)
        {
            min = readings[i];
            max = readings[i];
        }

        if (readings[i] < min)
        {
            min = readings[i];
        }

        if (readings[i] > max)
        {
            max = readings[i];
        }

        sum = sum + readings[i];
        count++;

        if (readings[i] <= 29)
        {
            normal++;
        }
        else if (readings[i] <= 44)
        {
            warning++;
        }
        else if (readings[i] <= 59)
        {
            critical++;
        }
        else
        {
            shutdown++;
        }
    }

    double average = sum / count;

    cout << "Min : " << min << "°C "
         << "Max : " << max << "°C "
         << "Avg : " << average << "°C" << endl;

    cout << "Normal:" << normal
         << " Warning:" << warning
         << " Critical:" << critical
         << " Shutdown:" << shutdown << endl;

    return 0;
}