#include <iostream>

using namespace std;

class NFSCar {

    private:
    int engine;
    int doors;
    int capacity;
    int topSpeed;

    //protected:
    //string VehicleType;

    public:
    //string VehicleType;
    //setters
    void setEngine(int _engine) {
        engine = _engine;
    }
    void setDoors(int _doors) {
        doors = _doors;
    }
    void setCapacity(int _capacity) {
        capacity = _capacity;
    }
    void setTopSpeed(int _topSpeed) {
        topSpeed = _topSpeed;
    }
    //getters
    int getEngine() { return engine; }
    int getDoors() { return doors; }
    int getCapacity() { return capacity; }
    int getTopSpeed() { return topSpeed; }

    // other methods
    virtual void StartVehicle() = 0;
    virtual void StopVehicle() = 0 ;

    void Accelerate() {
        cout << "\nCar Accerating..!\n";
    }
    void CarCrashed() {
        cout << "\nCar Crashed.\n";
    }
    //why is it called if its virtual?
    virtual ~NFSCar() {
        CarCrashed();
    }


};

class Lambhorghini : public NFSCar {

    // why does this not get inherited? how to avoid repetition.
    string VehicleType =  "Lambhorghini";
    void StartVehicle() {
        cout << "Starting my car type: " << VehicleType << ".\n";
    }

    void StopVehicle() {
        cout << "Stopping my car type: " << VehicleType << ".\n";
    }
};
class BMW : public NFSCar {

    string VehicleType =  "BMW";
    void StartVehicle() {
        cout << "Starting my car type: " << VehicleType << ".\n";
    }
    void StopVehicle() {
        cout << "Stopping my car type: " << VehicleType << ".\n";
    }
};
class Mercedes : public NFSCar {

    string VehicleType = "Mercedes";
    //repition of code
    void StartVehicle() {
        cout << "Starting my car type: " << VehicleType << ".\n";
    }
    void StopVehicle() {
        cout << "Stopping my car type: " << VehicleType << ".\n";
    }
};


int main()
{
    NFSCar* vehicle1 = new Lambhorghini();
    NFSCar* vehicle2 = new BMW();
    NFSCar* vehicle3 = new Mercedes();
    vehicle1->StartVehicle();
    vehicle2->StartVehicle();
    vehicle3->StartVehicle();
    vehicle1->StopVehicle();
    vehicle2->StopVehicle();
    vehicle3->StopVehicle();
    vehicle1->setDoors(10);
    cout << vehicle1->getDoors();
    vehicle2->setDoors(20);
    cout << vehicle2->getDoors();
    vehicle3->setDoors(30);
    cout << vehicle3->getDoors();
    delete vehicle1;
    delete vehicle2;
    delete vehicle3;
    return 0;
}
