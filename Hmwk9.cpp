#include "Supplies.h"
#include "Turn.h"
#include "Date.h"
#include "Player.h"
#include "Driver.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    Driver d;
    d.begin();
    d.supplies();
    while(d.turn() != 0 && d.misfortunes() != 0 && d.attack() != 0); 
}