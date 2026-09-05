#include <iostream>
#include <cstring>

using namespace std;

class LogBuffer {
private:
    char* buffer;
    int capacity;
    int size;
    static int instanceCount;
    mutable int accessCount = 0;

public:
    LogBuffer(int capacity) {
        this->capacity = capacity;
        size = 0;
        buffer = new char[capacity + 1];
        buffer[0] = '\0';
        instanceCount++;

        cout << "[LogBuffer Created] capacity=" << capacity << endl;
    }

    LogBuffer(const LogBuffer& other) {
        capacity = other.capacity;
        size = other.size;
        buffer = new char[capacity + 1];
        memcpy(buffer, other.buffer, size + 1);
        accessCount = 0;
        instanceCount++;

        cout << "[LogBuffer Deep Copied] capacity=" << capacity << endl;
    }

    LogBuffer& operator=(const LogBuffer& other) {
        if (this == &other) {
            cout << "[Self-assignment detected - no operation]" << endl;
            return *this;
        }

        delete[] buffer;

        capacity = other.capacity;
        size = other.size;
        buffer = new char[capacity + 1];
        memcpy(buffer, other.buffer, size + 1);
        accessCount = 0;

        cout << "[LogBuffer Assigned]" << endl;

        return *this;
    }

    ~LogBuffer() {
        delete[] buffer;
        instanceCount--;

        cout << "[LogBuffer Destroyed]" << endl;
    }

    void append(const char* msg) {
        int msgLength = strlen(msg);
        int space = capacity - size;

        if (msgLength > space) {
            msgLength = space;
        }

        memcpy(buffer + size, msg, msgLength);
        size += msgLength;
        buffer[size] = '\0';
    }

    void print() const {
        accessCount++;
        cout << buffer << endl;
    }

    void clear() {
        size = 0;
        buffer[0] = '\0';
    }

    static int getInstanceCount() {
        return instanceCount;
    }

    int getAccessCount() const {
        return accessCount;
    }
};

int LogBuffer::instanceCount = 0;

int main() {
    LogBuffer log1(256);

    log1.append("Server started on port 8080");
    log1.append(" | Request received from 192.168.1.10");
    log1.print();

    LogBuffer log2 = log1;

    log2.append(" | Cached response sent");

    cout << "log1 : ";
    log1.print();

    cout << "log2 : ";
    log2.print();

    LogBuffer log3(128);

    log3 = log1;
    log3.print();

    log1 = log1;
    log1.print();

    cout << "Live LogBuffer objects : " << LogBuffer::getInstanceCount() << endl;

    const LogBuffer readOnly(log1);

    readOnly.print();
    readOnly.print();
    readOnly.print();

    cout << "Times printed: " << readOnly.getAccessCount() << endl;

    return 0;
}

/*
accessCount is mutable because print() is const.
It allows accessCount to change inside a const function.
const normally prevents changing data members.
*/