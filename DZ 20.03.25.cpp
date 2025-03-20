#include <iostream>
#include <string>
using namespace std;

const int MAX_DEVICES = 10;

class SmartDevice {
public:
    bool isOn; 

public:
    SmartDevice() {
        this->isOn = isOn;
    }


    virtual void executeCommand(const string& command) {
        if (command == "включить") {
            isOn = true;
            cout << "Устройство включено." << endl;
        }
        else if (command == "выключить") {
            isOn = false;
            cout << "Устройство выключено." << endl;
        }
        else {
            cout << "Неизвестная команда: " << command << endl;
        }
    }

    bool getState() {
        return isOn;
    }
};

class SmartHome {
private:
    SmartDevice* devices[MAX_DEVICES]; 
    int deviceCount;

public:
    SmartHome() : deviceCount(0) {}

    void addDevice(SmartDevice* device) {
        if (deviceCount < MAX_DEVICES) {
            devices[deviceCount] = device;
            deviceCount++;
        }
        else {
            std::cout << "Достигнуто максимальное количество устройств!" << endl;
        }
    }

    void CommandDevace(const string& command) {
        for (int i = 0; i < deviceCount; ++i) {
            devices[i]->executeCommand(command);
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    SmartDevice lamp;
    SmartDevice thermostat;

    SmartHome smartHome;
    smartHome.addDevice(&lamp);
    smartHome.addDevice(&thermostat);

    smartHome.CommandDevace("включить");
    smartHome.CommandDevace("выключить");

    return 0;
}
