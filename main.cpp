#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Base class Vehicle
class Vehicle {
protected:
    string licensePlate;
    int speed;
    int position;

public:
    Vehicle(string lp, int spd) : licensePlate(lp), speed(spd), position(0) {}
    virtual void move() { position += speed; }
    virtual void displayInfo() const = 0;
};

// Derived class Car
class Car : public Vehicle {
private:
    int passengerCount;

public:
    Car(string lp, int spd, int passengers) : Vehicle(lp, spd), passengerCount(passengers) {}
    void displayInfo() const override {
        cout << "Car - License: " << licensePlate << ", Speed: " << speed << ", Passengers: " << passengerCount << endl;
    }
};

// Derived class Bus
class Bus : public Vehicle {
private:
    int routeNumber;
    int capacity;

public:
    Bus(string lp, int spd, int route, int cap) : Vehicle(lp, spd), routeNumber(route), capacity(cap) {}
    void displayInfo() const override {
        cout << "Bus - License: " << licensePlate << ", Route: " << routeNumber << ", Capacity: " << capacity << endl;
    }
};

// TrafficLight class
class TrafficLight {
private:
    string color;
    int duration;

public:
    TrafficLight(string clr, int dur) : color(clr), duration(dur) {}
    void changeLight() {
        if (color == "Red") color = "Green";
        else if (color == "Green") color = "Yellow";
        else color = "Red";
    }
    string getColor() const { return color; }
};

// Intersection class
class Intersection {
private:
    vector<TrafficLight> lights;
    vector<Vehicle*> vehicles;

public:
    void addVehicle(Vehicle* v) { vehicles.push_back(v); }
    void manageTraffic() {
        for (auto& light : lights) light.changeLight();
        for (auto& vehicle : vehicles) vehicle->move();
    }
};

// Main controller class TrafficSystem
class TrafficSystem {
private:
    vector<Intersection> intersections;

public:
    void simulateTraffic() {
        for (auto& intersection : intersections) intersection.manageTraffic();
    }
    void addIntersection(Intersection intersection) { intersections.push_back(intersection); }
};

// Main function
int main() {
    // Example setup and simulation
    TrafficSystem system;
    Car* car1 = new Car("ABC123", 60, 4);
    Bus* bus1 = new Bus("BUS789", 40, 10, 50);

    Intersection intersection1;
    intersection1.addVehicle(car1);
    intersection1.addVehicle(bus1);

    system.addIntersection(intersection1);
    system.simulateTraffic();

    car1->displayInfo();
    bus1->displayInfo();

    delete car1;
    delete bus1;
    return 0;
}
