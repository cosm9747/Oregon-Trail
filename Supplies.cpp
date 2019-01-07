#include "Supplies.h"
using namespace std;

Supplies::Supplies() {
    cash = 1200;
    numOxen = 0;
    totOxen = 0;
    oxenPrice = 0;
    poundsOfFood = 0;
    totFood = 0;
    foodPrice = 0;
    numBullets = 0;
    totBullets = 0;
    bulletPrice = 0;
    numWagonParts = 0;
    totWagon = 0;
    wagonPrice = 0;
    numMedKits = 0;
    totKit = 0;
    kitPrice = 0;   
}

int Supplies::getCash() {
    return cash;
}

int Supplies::getOxen() {
    return numOxen;
}

int Supplies::getTotOxen() {
    return totOxen;
}

double Supplies::getOxenPrice(double om) {
    oxenPrice = numOxen * 20 * om;
    return oxenPrice;
}

int Supplies::getFood() {
    return poundsOfFood;
}

int Supplies::getTotFood() {
    return totFood;
}

double Supplies::getFoodPrice(double fm) {
    foodPrice = poundsOfFood * 0.5 * fm;
    return foodPrice;
}

int Supplies::getBullets() {
    return numBullets;
}

int Supplies::getTotBullets() {
    return totBullets;
}

double Supplies::getBulletPrice(double bm) {
    bulletPrice = numBullets / 10 * bm; // divided by 10 is times 2 and divided by 20
    return bulletPrice;
}

int Supplies::getWagon() {
    return numWagonParts;
}

int Supplies::getTotWagon() {
    return totWagon;
}

double Supplies::getWagonPrice(double wm) {
    wagonPrice = numWagonParts * 20 * wm;
    return wagonPrice;
}

int Supplies::getKit() {
    return numMedKits;
}

int Supplies::getTotKit() {
    return totKit;
}

double Supplies::getKitPrice(double km) {
    kitPrice = numMedKits * 25 * km;
    return kitPrice;
}

void Supplies::setCash(int ncash) {
    cash += ncash;
}

void Supplies::setOxen(int noxen) {
    numOxen = noxen;
}

void Supplies::setTotOxen() {
    totOxen += numOxen;
}

void Supplies::setFood(int nfood) {
    poundsOfFood = nfood;
}

void Supplies::setTotFood() {
    totFood += poundsOfFood;
}

void Supplies::setBullets(int nbullets) {
    numBullets = nbullets;
}

void Supplies::setTotBullets() {
    totBullets += numBullets;
}

void Supplies::setWagon(int nwagon) {
    numWagonParts = nwagon;
}

void Supplies::setTotWagon() {
    totWagon += numWagonParts;
}

void Supplies::setKit(int nkit) {
    numMedKits = nkit;
}

void Supplies::setTotKit() {
    totKit += numMedKits;
}