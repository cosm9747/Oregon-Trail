#include "Date.h"
using namespace std;

Date::Date() {
    day = 0; 
    month = 0;
    diff = 0;
    totDays = 0;
}

int Date::getTotDays() {
    return totDays;
}

int Date::getDay() {
    return day;
}

int Date::getMonth() {
    return month;
}

int Date::getYear() {
    return 1847;
}

int Date::getDifference() {
    diff = 334 - totDays; //334 is numDays in year until November 30th
    return diff;
}

int Date::getDaysInMonth(int newmonth) {
    switch(newmonth) {
        case 1:
            return 31;
            break;
        case 2:
            return 28;
            break;
        case 3:
            return 31;
            break;
        case 4:
            return 30;
            break;
        case 5:
            return 31;
            break;
        case 6:
            return 30;
            break;
        case 7:
        case 8:
            return 31;
            break;
        case 9:
            return 30;
            break;
        case 10:
            return 31;
            break;
        case 11:
            return 30;
            break;
        case 12:
            return 31;
            break;
        default:
            return 1;
            break;
    }
}

void Date::setTotDays(int numDays) {
    totDays += numDays;
}

void Date::setDay(int ndays) {
    day = ndays;
}

void Date::setMonth(int nmonths) {
    month = nmonths;
}