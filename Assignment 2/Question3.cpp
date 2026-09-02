#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int level = 1;

class Entity
{
private:
    string name;
    int health;
    int level;
    string type;

public:
    Entity()
    {
        name = "";
        health = 0;
        level = 0;
        type = "";
    }

    Entity& setName(const string& name)
    {
        this->name = name;
        return *this;
    }

    Entity& setHealth(int health)
    {
        this->health = health;
        return *this;
    }

    Entity& setLevel(int level)
    {
        this->level = level;
        return *this;
    }

    Entity& setType(const string& type)
    {
        this->type = type;
        return *this;
    }

    string getName() const
    {
        return name;
    }

    int getHealth() const
    {
        return health;
    }

    int getLevel() const
    {
        return level;
    }

    string getType() const
    {
        return type;
    }

    void displayInfo() const
    {
        cout << "Name   : " << name << endl;
        cout << "Health : " << health << endl;
        cout << "Level  : " << level << endl;
        cout << "Type   : " << type << endl;
        cout << endl;
    }
};

namespace Physics
{
    double clamp(double val, double min, double max)
    {
        if (val < min)
            return min;
        if (val > max)
            return max;
        return val;
    }

    double lerp(double a, double b, double t)
    {
        return a + (b - a) * t;
    }
}

namespace GameMath
{
    int clamp(int val, int min, int max)
    {
        if (val < min)
            return min;
        if (val > max)
            return max;
        return val;
    }

    double lerp(double a, double b, double t)
    {
        return a + (b - a) * t;
    }
}

namespace Engine
{
    namespace Audio
    {
        void playSound(string name)
        {
            cout << "Playing: " << name << endl;
        }
    }
}

int main()
{
    Entity player, enemy, item;

    player.setName("Aragorn").setHealth(100).setLevel(10).setType("Player");
    enemy.setName("Orc").setHealth(60).setLevel(5).setType("Enemy");
    item.setName("HealthPotion").setHealth(0).setLevel(1).setType("Item");

    cout << "===== ENTITY DETAILS =====" << endl;

    player.displayInfo();
    enemy.displayInfo();
    item.displayInfo();

    cout << "===== NAMESPACE FUNCTIONS =====" << endl;

    double velocity = Physics::clamp(120.5, 0.0, 100.0);
    int health = GameMath::clamp(120, 0, 100);

    cout << "Physics clamp: " << velocity << endl;
    cout << "GameMath clamp: " << health << endl;

    cout << "Physics lerp: " << Physics::lerp(10.0, 20.0, 0.5) << endl;
    cout << "GameMath lerp: " << GameMath::lerp(0.0, 100.0, 0.25) << endl;

    {
        using namespace Physics;
        cout << "Limited scope clamp: " << clamp(150.0, 0.0, 100.0) << endl;
    }

    int rows, cols;

    cout << "\nEnter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    int** map = new int*[rows];

    for (int i = 0; i < rows; i++)
    {
        map[i] = new int[cols];
    }

    srand(time(0));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            map[i][j] = rand() % 5;
        }
    }

    int count[5] = {0, 0, 0, 0, 0};

    cout << "\n===== GAME MAP (" << rows << " x " << cols << ") =====" << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << map[i][j] << " ";
            count[map[i][j]]++;
        }
        cout << endl;
    }

    cout << "\nLegend: 0=Grass 1=Water 2=Mountain 3=Forest 4=Dungeon" << endl;

    cout << "\nTile Count:" << endl;
    cout << "Grass : " << count[0] << endl;
    cout << "Water : " << count[1] << endl;
    cout << "Mountain : " << count[2] << endl;
    cout << "Forest : " << count[3] << endl;
    cout << "Dungeon : " << count[4] << endl;

    for (int i = 0; i < rows; i++)
    {
        delete[] map[i];
    }

    delete[] map;

    cout << "\n===== SCOPE RESOLUTION =====" << endl;

    int level = player.getLevel();

    cout << "Local level : " << level << endl;
    cout << "Global level : " << ::level << endl;

    Engine::Audio::playSound("sword_clash");

    return 0;
}