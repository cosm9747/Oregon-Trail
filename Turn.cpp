#include "Turn.h"
using namespace std;

Turn::Turn() {
    totMiles = 0;
    milestone = 0;
    toNextMilestone = 0;
    puzzle = 0;
    rcount = 0;
    fcount = 0;
    mName = "";
    fName = "";
    fMiles = "";
    rName = "";
    rMiles = "";
    rDepth = "";
}

int Turn::getTotMiles() {
    return totMiles;
}

int Turn::getMilestone() {
    return milestone;
}

int Turn::getToNextMilestone() {
    return toNextMilestone;
}

int Turn::getPuzzle() {
    return puzzle;
}

int Turn::getRCount() {
    return rcount;
}

int Turn::getFCount() {
    return fcount;
}

string Turn::getMilestoneName() {
    return mName;
}

string Turn::getFortName() {
    return fName;
}

string Turn::getFortMiles() {
    return fMiles;
}

string Turn::getRiverName() {
    return rName;
}

string Turn::getRiverMiles() {
    return rMiles;
}

string Turn::getRiverDepth() {
    return rDepth;
}

void Turn::setTotMiles(int nmiles) {
    totMiles += nmiles;
}

void Turn::setMilestone(int nmilestone) {
    milestone = nmilestone;
}

void Turn::setToNextMilestone(int nMilestone) {
    toNextMilestone = nMilestone;
}

void Turn::setPuzzle() {
    puzzle = rand() % 10 + 1;
}

void Turn::setRCount() {
    rcount++;
}

void Turn::setFCount() {
    fcount++;
}


void Turn::setMilestoneName(string nmname) {
    mName = nmname;
}

void Turn::setFortName(string nfname) {
    fName = nfname;
}

void Turn::setFortMiles(string nfmiles) {
    fMiles = nfmiles;
}

void Turn::setRiverName(string nrname) {
    rName = nrname;
}

void Turn::setRiverMiles(string nrmiles) {
    rMiles = nrmiles;
}

void Turn::setRiverDepth(string nrdepth) {
    rDepth = nrdepth;
}