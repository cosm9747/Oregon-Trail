#include "Player.h"
using namespace std;

Player::Player() {
    name1 = "";
    name2 = "";
    name3 = "";
    name4 = "";
    name5 = "";
    dStatus1 = false;
    dStatus2 = false;
    dStatus3 = false;
    dStatus4 = false;
    dStatus5 = false;
}

string Player::getName1() {
    return name1;
}

string Player::getName2() {
    return name2;
}

string Player::getName3() {
    return name3;
}

string Player::getName4() {
    return name4;
}

string Player::getName5() {
    return name5;
}

bool Player::getDStatus1() {
    return dStatus1;
}

bool Player::getDStatus2() {
    return dStatus2;
}

bool Player::getDStatus3() {
    return dStatus3;
}

bool Player::getDStatus4() {
    return dStatus4;
}

bool Player::getDStatus5() {
    return dStatus5;
}

void Player::setName1(string n1) {
    name1 = n1;
}

void Player::setName2(string n2) {
    name2 = n2;
}

void Player::setName3(string n3) {
    name3 = n3;
}

void Player::setName4(string n4) {
    name4 = n4;
}

void Player::setName5(string n5) {
    name5 = n5;
}

void Player::setDStatus1(bool d1) {
    dStatus1 = d1;
}

void Player::setDStatus2(bool d2) {
    dStatus2 = d2;
}

void Player::setDStatus3(bool d3) {
    dStatus3 = d3;
}

void Player::setDStatus4(bool d4) {
    dStatus4 = d4;
}

void Player::setDStatus5(bool d5) {
    dStatus5 = d5;
}