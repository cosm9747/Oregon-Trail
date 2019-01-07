#include "Supplies.h"
#include "Turn.h"
#include "Date.h"
#include "Player.h"
#include "Driver.h"
#include <iostream> //cin and cout 
#include <fstream> //reading and writing to file
#include <cmath>
#include <ctime>
#include <cstdlib> //rand and srand
#include <string>
using namespace std;

Driver::Driver() {
    m = 1.0;
}

void Driver::begin() {
    int choice(0), day(0), month(0), numDays(0), fm(0), rm(0), toNext(0), counter(0);
    string name1, name2, name3, name4, name5;
    cout << "THIS PROGRAM SIMULATES A TRIP OVER THE OREGON TRAIL FROM " << endl;
    cout << "INDEPENDENCE, MISSOURI TO OREGON CITY, OREGON IN 1847. YOUR FAMILY OF " << endl;
    cout << "FIVE WILL COVER THE 2040 MILE OREGON TRAIL IN 5-6 MONTHS --- IF YOU " << endl;
    cout << "MAKE IT ALIVE." << endl;
    cout << "Enter your name: " << endl;
    getline(cin, name1);
    cout << "Enter the names of your four travelling companions: " << endl;
    getline(cin, name2);
    getline(cin, name3);
    getline(cin, name4);
    getline(cin, name5);
    p.setName1(name1);
    p.setName2(name2);
    p.setName3(name3);
    p.setName4(name4);
    p.setName5(name5);
    cout << "You will start in Independence, Missouri (mile 0) and finish in Oregon City, Oregon (mile 2040)" << endl;
    cout << "You must arrive in Oregon City by November 30th, 1847." << endl;
    cout << "Do you want to start on 03/28/1847?" << endl << "Yes: 1, No: 2" << endl;
    while(choice < 1 || choice > 2) {
        cin >> choice;
    }
    switch(choice) {
        case 1:
            d.setMonth(3);
            d.setDay(28);
            break;
        case 2:
            cout << "Choose a different departure date between 03/01/1847 and 05/01/1847" << endl;
            while(month < 3 || month > 5) {
                cout << "Month: ";
                cin >> month;
                if(month == 3) {
                    while(day < 1 || day > 31) {
                        cout << "Day: ";
                        cin >> day;
                    }
                }
                else if(month == 4){
                    while(day < 1 || day > 30) {
                        cout << "Day: ";
                        cin >> day;
                    }
                }
                else if(month == 5) {
                    while(day != 1) {
                        cout << "Day: ";
                        cin >> day;
                    }
                }
            }
            d.setMonth(month);
            d.setDay(day);
            break;
    }
    for(int i = 1; i <= d.getMonth(); i++) {
        if(i == d.getMonth()) {
            for(int j = 0; j < d.getDay(); j++) {
                numDays++;
            }
        }
        else {
            for(int k = 0; k < d.getDaysInMonth(i); k++) {
                numDays++;
            }
        }
    }
    d.setTotDays(numDays);
    cout << "You will now visit the store to buy supplies for your trip." << endl << endl;
    s.setCash(-200); //wagon cost
    milestone();
    fm = stoi(ft[0].getFortMiles());
    rm = stoi(rt[0].getRiverMiles());
    if(fm < rm) {
        t.setMilestone(fm);
        t.setMilestoneName(ft[0].getFortName());
    }
    else {
        t.setMilestone(rm);
        t.setMilestoneName(rt[0].getRiverName());
    }
    toNext = t.getMilestone() - t.getTotMiles();
    t.setToNextMilestone(toNext);
    for(int x = 0; x < d.getDay(); x++) {
        for(int y = 0; y < d.getDaysInMonth(x); y++) {
            counter++;
        }
    }
}

void Driver::supplies() {
    //use supplies class
    string line = "";
    string filename1 = "store_info.txt";
    int choice(0), supChoice(0), cashAmount(0), oTurnTot(0), fTurnTot(0), bTurnTot(0), wTurnTot(0), kTurnTot(0);
    double a(0), x(0);
    ifstream myFile(filename1);
    if(myFile.is_open()) {
        while(getline(myFile,line)) {
            cout << line << endl;
        }
        myFile.close();
    }
    s.setOxen(0);
    s.setFood(0);
    s.setBullets(0);
    s.setWagon(0);
    s.setKit(0);
    while(choice != 5) {
        cout << endl << "Oxen: 1, Food: 2, Bullets: 3, Misc: 4, Finished: 5" << endl;
        cin >> choice;
        while(choice < 1 || choice > 5) {
            cin >> choice;
        }
        switch(choice) {
            case 1: 
                a = 40.0 * m;
                cout << "You must spend between $100 and $200 on Oxen, which is between 3 and 5 yokes." << endl;
                cout << "There are two Oxen in a yoke and the price of each yoke is $" << a << endl;
                cout << "How many yokes do you wish to purchase?" << endl;
                cin >> supChoice;
                x = supChoice * a;
                while(supChoice < 3 || supChoice > 5) { //number of yokes that are in between 100 and 200 dollars
                    cout << "Please choose a yoke amount anywhere from 3 to 5" << endl;
                    cin >> supChoice;
                }
                if(x <= s.getCash() && x >= 0) {
                    oTurnTot += supChoice;
                    s.setOxen(oTurnTot * 2);
                    cout << "Your current Oxen price is $" << s.getOxenPrice(m) << endl;
                    s.setCash(-x);
                    s.setTotOxen();
                }
                else {
                    if(x < 0) {
                        cout << "Please choose a positive number" << endl;
                    }
                    else if(x > s.getCash()) {
                        cout << "Oh no! You don't have enough money to purchase Oxen at this quantity." << endl; 
                        cout << "Please choose something that you can afford." << endl;
                    }
                }
                break;
            case 2:
                a = 0.50 * m;
                cout << "You should purchase at least 200 pounds of food, but you don't have to." << endl;
                cout << "One pound of food costs $" << a << ". How many pounds of food do you wish to purchase?" << endl;
                cin >> supChoice;
                x = supChoice * a;
                // while(x < 0 || x > s.getCash()) { 
                //     if(supChoice < 0) {
                //         cout << "Please choose a positive number" << endl;
                //     }
                //     else if(x > s.getCash()){
                //         cout << "Oh no! You don't have enough money to purchase food at this quantity." << endl;
                //         cout << "Please choose something that you can afford." << endl;
                //     }
                //     cin >> supChoice;
                //     x = supChoice * 0.5 * m;
                // }
                if(x <= s.getCash() && x >= 0) {
                    fTurnTot += supChoice;
                    s.setFood(fTurnTot);
                    cout << "Your current food price is $" << s.getFoodPrice(m) << endl;
                    s.setCash(-x);
                    s.setTotFood();
                }
                else {
                    if(x < 0) {
                        cout << "Please choose a positive number" << endl;
                    }
                    else if(x > s.getCash()) {
                        cout << "Oh no! You don't have enough money to purchase food at this quantity." << endl;
                        cout << "Please choose something that you can afford." << endl;
                    }
                }
                break;
            case 3:
                a = 2.0 * m;
                cout << "A box of 20 bullets costs $" << a << ". How many boxes of bullets do you wish to purchase?" << endl;
                cin >> supChoice;
                x = supChoice * a;
                // while(x < 0 || x > s.getCash()) { 
                //     if(supChoice < 0) {
                //         cout << "Please choose a positive number" << endl;
                //     }
                //     else if(x > s.getCash()) {
                //         cout << "Oh no! You don't have enough money to purchase bullets at this quantity." << endl;
                //         cout << "Please choose something that you can afford." << endl;
                //     }
                //     cin >> supChoice;
                //     x = supChoice * 2 * m;
                // }
                if(x <= s.getCash() && x >= 0) {
                    bTurnTot += supChoice;
                    s.setBullets(bTurnTot * 20);
                    cout << "Your current bullet price is $" << s.getBulletPrice(m) << endl;
                    s.setCash(-x);
                    s.setTotBullets();
                }
                else {
                    if(x < 0) {
                        cout << "Please choose a positive number" << endl;
                    }
                    else if(x > s.getCash()) {
                        cout << "Oh no! You don't have enough money to purchase bullets at this quantity." << endl;
                        cout << "Please choose something that you can afford." << endl;
                    }
                }
                break;
            case 4:
                a = 20.0 * m;
                cout << "A wagon part (wheels, axles, or tongues) costs $" << a << " each." << endl;
                cout << "How many wagon parts do you wish to purchase?" << endl;
                cin >> supChoice;
                x = supChoice * a;
                // while(x < 0 || x > s.getCash()) { 
                //     if(supChoice < 0) {
                //         cout << "Please choose a positive number" << endl;
                //     }
                //     else if(x > s.getCash()) {
                //         cout << "Oh no! You don't have enough money to purchase wagon parts at this quantity." << endl;
                //         cout << "Please choose something that you can afford." << endl;
                //     }
                //     cin >> supChoice;
                //     x = supChoice * 20 * m;
                // }
                
                if(x <= s.getCash() && x >= 0) {
                    wTurnTot += supChoice;
                    s.setWagon(wTurnTot);
                    cout << "Your current wagon part price is $" << s.getWagonPrice(m) << endl;
                    s.setCash(-x);
                    s.setTotWagon();
                }
                else {
                    if(x < 0) {
                        cout << "Please choose a positive number" << endl;
                    }
                    else if(x > s.getCash()) {
                        cout << "Oh no! You don't have enough money to purchase wagon parts at this quantity." << endl;
                    }
                }
                
                a = 25.0 * m;
                cout << "A medical aid kit costs $" << a << " each." << endl;
                cout << "How many medical aid kits do you wish to purchase?" << endl;
                cin >> supChoice;
                x = supChoice * a;
                // while(x < 0|| x > s.getCash()) { 
                //     if(supChoice < 0) {
                //         cout << "Please choose a positive number" << endl;
                //     }
                //     else if(x > s.getCash()) {
                //         cout << "Oh no! You don't have enough money to purchase medical aid kits at this quantity." << endl;
                //         cout << "Please choose something that you can afford." << endl;
                //     }
                //     cin >> supChoice;
                //     x = supChoice * 25 * m;
                // }
                if(x <= s.getCash() && x >= 0) {
                    kTurnTot += supChoice;
                    s.setKit(kTurnTot);
                    cout << "Your current medical aid kit price is $" << s.getKitPrice(m) << endl;
                    s.setCash(-x);
                    s.setTotKit();
                }
                else {
                    if(x < 0) {
                        cout << "Please choose a positive number" << endl;
                    }
                    else if(x > s.getCash()) {
                        cout << "Oh no! You don't have enough money to purchase medical aid kits at this quantity." << endl;
                        cout << "Please choose something that you can afford." << endl;
                    }
                }
                break;
            case 5:
                break;
        }
        cout << endl << "Current Bill" << endl;
        cout << "Oxen: $" << s.getOxenPrice(m) << endl;
        cout << "Food: $" << s.getFoodPrice(m) << endl;
        cout << "Bullets: $" << s.getBulletPrice(m) << endl;
        cout << "Misc: $" << s.getWagonPrice(m) + s.getKitPrice(m) << endl;
        cout << "Total: $" <<s.getOxenPrice(m) + s.getFoodPrice(m) + s.getBulletPrice(m) + s.getWagonPrice(m) + s.getKitPrice(m) << endl;
        cout << "Amount Left: $" << s.getCash() << endl;
    }
}

int Driver::turn() {
    //use turn and date class
    int choice(0), pchoice, fchoice, mchoice(0), hunt(0), numPeople(5), foodAmt(0), v1(0), f1(0), m1(0), p1(0), nday(0), nmonth(0), toNext(0), rm(0), fm(0), isFort(0), cost(0); 
    //v1: numDays, f1: amtFood, m1: numMiles, p1: probability, pchoice: puzzle choice
    if(p.getDStatus1() == true) {
        numPeople--;
    }
    if(p.getDStatus2() == true) {
        numPeople--;
    }
    if(p.getDStatus3() == true) {
        numPeople--;
    }
    if(p.getDStatus4() == true) {
        numPeople--;
    }
    if(p.getDStatus5() == true) {
        numPeople--;
    }
    //display status update
    cout << endl << "Status Update" << endl;
    cout << "Current Date: " << d.getMonth() << "-" << d.getDay() << "-" << d.getYear() << endl;
    cout << "Miles Travelled: " << t.getTotMiles() << endl;
    cout << "Miles to Next Milestone: " << t.getToNextMilestone() << endl;
    cout << "Food Available: " << s.getTotFood() << endl;
    cout << "Bullets Available: " << s.getTotBullets() << endl;
    cout << "Cash Available: $" << s.getCash() << endl;
    
    cout << "Rest: 1, Continue: 2, Hunt: 3, Quit: 4" << endl;
    while(choice < 1 || choice > 4) {
        cin >> choice;
    }
    switch(choice) {
        case 1:
            cout << endl << "Resting takes between 1 and 3 days and the resting";
            cout << " party consumes 3 pounds of food per person per day" << endl;
            v1 = rand() % 3 + 1;
            cout << "You rested for " << v1 << " day(s)" << endl;
            f1 = 3 * v1 * numPeople;
            s.setFood(-f1);
            s.setTotFood();
            d.setTotDays(v1);
            if(check() == 0) {
                return 0;
            }
            //update the date
            nday = v1 + d.getDay();
            nmonth = d.getMonth();
            if(nday <= d.getDaysInMonth(nmonth)) {
                d.setDay(nday);
            }
            else {
               nday -= d.getDaysInMonth(nmonth);
               nmonth++;
               d.setDay(nday);
               d.setMonth(nmonth);
            }
            break;
        case 2:
            cout << "Continuing on the trail takes two weeks and you will travel somewhere between 70 and 140 miles" << endl;
            cout << "The travelling party consumes 3 pounds of food per person per day" << endl;
            v1 = 14;
            m1 = rand() % 71 + 70;
            f1 = 3 * v1 * numPeople;
            cout << endl << "You travelled " << m1 << " miles" << endl;
            s.setFood(-f1);
            s.setTotFood();
            if(check() == 0) {
                return 0;
            }
            //start of milestone
            fm = stoi(ft[t.getFCount()].getFortMiles());
            rm = stoi(rt[t.getRCount()].getRiverMiles());
            if(fm < rm) {
                t.setMilestone(fm);
                t.setMilestoneName(ft[t.getFCount()].getFortName());
                isFort = 1;
            }
            else {
                t.setMilestone(rm);
                t.setMilestoneName(rt[t.getRCount()].getRiverName());
                isFort = 0;
            }
            toNext = t.getMilestone() - t.getTotMiles();
            t.setToNextMilestone(toNext);
            if(m1 >= t.getToNextMilestone()) {
                cout << "You were prepared to travel " << m1 << " miles, but you arrived at " << t.getMilestoneName();
                cout << " in " << t.getToNextMilestone() << " miles" << endl;
                m1 = t.getToNextMilestone();
                cout << "What do you want to do?" << endl;
                
                if(isFort == 1) {
                    cout << "Rest: 1, Visit the Store: 2, Continue the Journey: 3" << endl; 
                    cin >> mchoice;
                    while(mchoice < 1 || mchoice > 3) {
                        cin >> mchoice;
                    }
                    while(mchoice == 1 || mchoice == 2) {
                        if(mchoice == 1) {
                            cout << "Your travelling party rested for one day and consumed three pounds of food per person" << endl;
                            f1 = 3 * numPeople;
                            s.setFood(-f1);
                            s.setTotFood();
                            d.setTotDays(1);
                            if(check() == 0) {
                                return 0;
                            }
                        }
                        else if(mchoice == 2) {
                            m += 0.25;
                            supplies();
                        }
                        cout << "Rest: 1, Visit the Store: 2, Continue the Journey: 3" << endl; 
                        cin >> mchoice;
                    }
                    t.setFCount();
                }
                
                if(isFort == 0) {
                    cout << "Rest: 1, Cross the River: 2" << endl;
                    cin >> mchoice;
                    while(mchoice < 1 || mchoice > 2) {
                        cin >> mchoice;
                    }
                    while(mchoice == 1) {
                        cout << "Your travelling party rested for one day and consumed three pounds of food per person" << endl;
                        f1 = 3 * numPeople;
                        s.setFood(-f1);
                        s.setTotFood();
                        d.setTotDays(1);
                        if(check() == 0) {
                            return 0;
                        }
                        cout << "Rest: 1, Cross the River: 2" << endl;
                        cin >> mchoice;
                    }
                    if(mchoice == 2) {
                        if(stoi(rt[t.getRCount()].getRiverDepth()) > 3) {
                            cout << "The river is too deep to cross by foot. You need a ferry to cross" << endl;
                            cout << "The ferry will cost $10 per person" << endl;
                            cost = 10 * numPeople;
                            cout << "The ferryman took you across the river for " << cost << " dollars" << endl;
                            s.setCash(-cost);
                            if(check() == 0) {
                                return 0;
                            }
                        }
                        else {
                            cout << "Your travelling party crossed the river with no issues" << endl;
                        }
                    }
                    t.setRCount();
                }
            }
            
            //end of milestone
            t.setTotMiles(m1);
            d.setTotDays(v1);
            if(check() == 0) {
                return 0;
            }
            //update the date
            nday = v1 + d.getDay();
            nmonth = d.getMonth();
            if(nday <= d.getDaysInMonth(nmonth)) {
                d.setDay(nday);
            }
            else {
               nday -= d.getDaysInMonth(nmonth);
               nmonth++;
               d.setDay(nday);
               d.setMonth(nmonth);
            }
            break;
        case 3:
            cout << "Hunting takes 1 day. You can encounter different animals to hunt with certain probabilites as follows..." << endl;
            cout << "Rabbit: 50%, Fox: 25%, Deer: 15%, Bear: 7%, Moose: 5%" << endl;
            cout << "The maximum amount of food you can get from hunting today is 1000 lbs" << endl;
            cout << "Now lets hunt!" << endl << endl;
            v1 = 1;
            
            p1 = rand() % 100 + 1;
            if(p1 <= 50) { //rabbit
                cout << "You got lucky! You encountered a rabbit! Do you want to hunt?" << endl;
                cout << "Yes: 1, No: 2" << endl;
                hunt = 0;
                while(hunt < 1 || hunt > 2) {
                    cin >> hunt;
                }
                if(hunt == 1) {
                    if(s.getTotBullets() >= 10) {
                        cout << "You must solve a puzzle correctly to have a successful hunt" << endl;
                        cout << "You have three tries to guess the correct random number from 1 to 10" << endl;
                        t.setPuzzle();
                        for(int i = 0; i < 3; i++) {
                            cout << "Guess a number between 1 and 10" << endl;
                            cin >> pchoice;
                            while(pchoice < 1 || pchoice > 10) {
                                cin >> pchoice;
                            }
                            if(pchoice != t.getPuzzle() && i == 2) {
                                cout << "The hunt was unsuccessful." << endl;
                            }
                            else if(pchoice != t.getPuzzle() && i != 2) {
                                cout << "That number is incorrect. Try again" << endl;
                            }
                            else if(pchoice == t.getPuzzle()) {
                                i = 2;
                                cout << "You have solved the puzzle and had a successful hunt!" << endl;
                                cout << "The rabbit increases your food supply by two pounds" << endl;
                                cout << "Although you had to use ten bullets to kill the rabbit" << endl;
                                foodAmt += 2;
                                s.setBullets(-10);
                                s.setTotBullets();
                            }
                        }
                    }
                    else {
                        cout << "You need at least 10 bullets to hunt." << endl;
                    }
                }
                else if(hunt == 2) {
                    cout << "Time to see if there are any other animals to be hunted." << endl;
                }
            }
            
            p1 = rand() % 100 + 1;
            if(p1 <= 25) { //fox
                cout << "You got lucky! You encountered a fox! Do you want to hunt?" << endl;
                cout << "Yes: 1, No: 2" << endl;
                hunt = 0;
                while(hunt < 1 || hunt > 2) {
                    cin >> hunt;
                }
                if(hunt == 1) {
                    if(s.getTotBullets() >= 10) {
                        cout << "You must solve a puzzle correctly to have a successful hunt" << endl;
                        cout << "You have three tries to guess the correct random number from 1 to 10" << endl;
                        t.setPuzzle();
                        for(int i = 0; i < 3; i++) {
                            cout << "Guess a number between 1 and 10" << endl;
                            cin >> pchoice;
                            while(pchoice < 1 || pchoice > 10) {
                                cin >> pchoice;
                            }
                            if(pchoice != t.getPuzzle() && i == 2) {
                                cout << "The hunt was unsuccessful." << endl;
                            }
                            else if(pchoice != t.getPuzzle() && i != 2) {
                                cout << "That number is incorrect. Try again" << endl;
                            }
                            else if(pchoice == t.getPuzzle()) {
                                i = 2;
                                cout << "You have solved the puzzle and had a successful hunt!" << endl;
                                cout << "The fox increases your food supply by five pounds" << endl;
                                cout << "Although you had to use eight bullets to kill the fox" << endl;
                                foodAmt += 5;
                                s.setBullets(-8);
                                s.setTotBullets();
                            }
                        }
                    }
                    else {
                        cout << "You need at least 10 bullets to hunt." << endl;
                    }
                }
                else if(hunt == 2) {
                    cout << "Time to see if there are any other animals to be hunted." << endl;
                }
            }
            
            p1 = rand() % 100 + 1;
            if(p1 <= 15) { //deer
                cout << "You got lucky! You encountered a deer! Do you want to hunt?" << endl;
                cout << "Yes: 1, No: 2" << endl;
                hunt = 0;
                while(hunt < 1 || hunt > 2) {
                    cin >> hunt;
                }
                if(hunt == 1) {
                    if(s.getTotBullets() >= 10) {
                        cout << "You must solve a puzzle correctly to have a successful hunt" << endl;
                        cout << "You have three tries to guess the correct random number from 1 to 10" << endl;
                        t.setPuzzle();
                        for(int i = 0; i < 3; i++) {
                            cout << "Guess a number between 1 and 10" << endl;
                            cin >> pchoice;
                            while(pchoice < 1 || pchoice > 10) {
                                cin >> pchoice;
                            }
                            if(pchoice != t.getPuzzle() && i == 2) {
                                cout << "The hunt was unsuccessful." << endl;
                            }
                            else if(pchoice != t.getPuzzle() && i != 2) {
                                cout << "That number is incorrect. Try again" << endl;
                            }
                            else if(pchoice == t.getPuzzle()) {
                                i = 2;
                                cout << "You have solved the puzzle and had a successful hunt!" << endl;
                                f1 = rand() % 26 + 30;
                                cout << "The deer increases your food supply by " << f1 << " pounds" << endl;
                                cout << "Although you had to use five bullets to kill the deer" << endl;
                                foodAmt += f1;
                                s.setBullets(-8);
                                s.setTotBullets();
                            }
                        }
                    }
                    else {
                        cout << "You need at least 10 bullets to hunt." << endl;
                    }
                }
                else if(hunt == 2) {
                    cout << "Time to see if there are any other animals to be hunted." << endl;
                }
            }
            
            p1 = rand() % 100 + 1;
            if(p1 <= 7) { //bear
                cout << "You got lucky! You encountered a bear! Do you want to hunt?" << endl;
                cout << "Yes: 1, No: 2" << endl;
                hunt = 0;
                while(hunt < 1 || hunt > 2) {
                    cin >> hunt;
                }
                if(hunt == 1) {
                    if(s.getTotBullets() >= 10) {
                        cout << "You must solve a puzzle correctly to have a successful hunt" << endl;
                        cout << "You have three tries to guess the correct random number from 1 to 10" << endl;
                        t.setPuzzle();
                        for(int i = 0; i < 3; i++) {
                            cout << "Guess a number between 1 and 10" << endl;
                            cin >> pchoice;
                            while(pchoice < 1 || pchoice > 10) {
                                cin >> pchoice;
                            }
                            if(pchoice != t.getPuzzle() && i == 2) {
                                cout << "The hunt was unsuccessful." << endl;
                            }
                            else if(pchoice != t.getPuzzle() && i != 2) {
                                cout << "That number is incorrect. Try again" << endl;
                            }
                            else if(pchoice == t.getPuzzle()) {
                                i = 2;
                                cout << "You have solved the puzzle and had a successful hunt!" << endl;
                                f1 = rand() % 251 + 100;
                                cout << "The bear increases your food supply by " << f1 << " pounds" << endl;
                                cout << "Although you had to use ten bullets to kill the bear" << endl;
                                foodAmt += f1;
                                s.setBullets(-10);
                                s.setTotBullets();
                            }
                        }
                    }
                    else {
                        cout << "You need at least 10 bullets to hunt." << endl;
                    }
                }
                else if(hunt == 2) {
                    cout << "Time to see if there are any other animals to be hunted." << endl;
                }
            }
                
            p1 = rand() % 100 + 1;
            if(p1 <= 5) { //moose
                cout << "You got lucky! You encountered a moose! Do you want to hunt?" << endl;
                cout << "Yes: 1, No: 2" << endl;
                hunt = 0;
                while(hunt < 1 || hunt > 2) {
                    cin >> hunt;
                }
                if(hunt == 1) {
                    if(s.getTotBullets() >= 10) {
                        cout << "You must solve a puzzle correctly to have a successful hunt" << endl;
                        cout << "You have three tries to guess the correct random number from 1 to 10" << endl;
                        t.setPuzzle();
                        for(int i = 0; i < 3; i++) {
                            cout << "Guess a number between 1 and 10" << endl;
                            cin >> pchoice;
                            while(pchoice < 1 || pchoice > 10) {
                                cin >> pchoice;
                            }
                            if(pchoice != t.getPuzzle() && i == 2) {
                                cout << "The hunt was unsuccessful." << endl;
                            }
                            else if(pchoice != t.getPuzzle() && i != 2) {
                                cout << "That number is incorrect. Try again" << endl;
                            }
                            else if(pchoice == t.getPuzzle()) {
                                i = 2;
                                cout << "You have solved the puzzle and had a successful hunt!" << endl;
                                f1 = rand() % 301 + 300;
                                cout << "The moose increases your food supply by " << f1 << " pounds" << endl;
                                cout << "Although you had to use twelve bullets to kill the moose" << endl;
                                foodAmt += f1;
                                s.setBullets(-12);
                                s.setTotBullets();
                            }
                        }
                    }
                    else {
                        cout << "You need at least 10 bullets to hunt." << endl;
                    }
                }
                else if(hunt == 2) {
                    cout << "There are no more animals to be hunted." << endl;
                }
            }
            cout << "Now that the hunting day is over it's time to eat. How well do you want to eat?" << endl;
            cout << "Poorly: 2 lbs of food per person, Moderately: 3 lbs of food per person, Well: 5 lbs of food per person" << endl;
            cout << "1 for poorly, 2 for moderately, and 3 for well" << endl;
            cin >> fchoice;
            switch(fchoice) {
                case 1:
                    f1 = 2 * numPeople;
                    break;
                case 2:
                    f1 = 3 * numPeople;
                    break;
                case 3:
                    f1 = 5 * numPeople;
                    break;
            }
            foodAmt -= f1;
            if(foodAmt > 1000) {
                foodAmt = 1000;
            }
            s.setFood(foodAmt);
            s.setTotFood();
            d.setTotDays(v1);
            if(check() == 0) {
                return 0;
            }
            //update date
            nday = v1 + d.getDay();
            nmonth = d.getMonth();
            if(nday <= d.getDaysInMonth(nmonth)) {
                d.setDay(nday);
            }
            else {
               nday -= d.getDaysInMonth(nmonth);
               nmonth++;
               d.setDay(nday);
               d.setMonth(nmonth);
            }
            break;
        case 4:
            cout << "We are sorry that you decided to cut your travels short." << endl;
            cout << "Game Over" << endl;
            results();
            return 0;
            break;
        default: 
            cout << "Please choose a number between 1 and 4 in the future." << endl;
            break;
    }
    return 1;
}

int Driver::misfortunes() {
    int choice(0), nday(0), nmonth(0), p1(0), p2(0), p3(0), p4(0), p5(0);
    string sickness = "";
    cout << endl; //to keep it organized and separate from the text in the last method
    p1 = rand() % 100 + 1;
    if(p1 <= 40) {
        p2 = rand() % 3 + 1;
        switch(p2) {
            case 1:
                p3 = rand() % 5 + 1;
                p4 = rand() % 6 + 1;
                switch(p3) {
                    case 1:
                        switch(p4) {
                            case 1:
                                sickness = "typhoid";
                                cout << "Oh no! You have " << sickness << endl;
                                break;
                            case 2:
                                sickness = "cholera";
                                cout << "Oh no! You have " << sickness << endl;
                                break;
                            case 3:
                                sickness = "diarrhea";
                                cout << "Oh no! You have " << sickness << endl;
                                break;
                            case 4:
                                sickness = "the measles";
                                cout << "Oh no! You have " << sickness << endl;
                                break;
                            case 5:
                                sickness = "dysentery";
                                cout << "Oh no! You have " << sickness << endl;
                                break;
                            case 6:
                                sickness = "a fever";
                                cout << "Oh no! You have " << sickness << endl;
                                break;
                        }
                        
                        if(s.getTotKit() > 0) {
                            cout << "You have a medical aid kit that will be used" << endl;
                            cout << "You have a 50 percent chance of dying" << endl;
                            s.setKit(-1);
                            s.setTotKit();
                            p5 = rand() % 100 + 1;
                            if(p5 <= 50) {
                                p.setDStatus1(true);
                            }
                            else {
                                cout << "You survived and you aren't sick anymore." << endl;
                            }
                        }
                        else {
                            cout << "You have the option to rest or press on." << endl;
                            cout << "If you rest you will stop for three days and the sick player has a 30 percent chance of dying." << endl;
                            cout << "If you press on the sick player has a 70 percent chance of dying." << endl;
                            cout << "Rest: 1, Press on: 2" << endl;
                            cin >> choice;
                            // while(choice < 1 && choice > 2) {
                            //     cin >> choice;
                            // }
                            if(choice == 1) {
                                d.setTotDays(3);
                                cout << "You rested for three days" << endl;
                                if(check() == 0) {
                                    return 0;
                                }
                                p5 = rand() % 100 + 1;
                                if(p5 <= 30) {
                                    p.setDStatus1(true);
                                }
                                else {
                                    cout << "You survived and you aren't sick anymore." << endl;
                                }
                                nday = 3 + d.getDay();
                                nmonth = d.getMonth();
                                if(nday <= d.getDaysInMonth(nmonth)) {
                                    d.setDay(nday);
                                }
                                else {
                                   nday -= d.getDaysInMonth(nmonth);
                                   nmonth++;
                                   d.setDay(nday);
                                   d.setMonth(nmonth);
                                }
                            }
                            else if(choice == 2) {
                                p5 = rand() % 100 + 1;
                                if(p5 <= 70) {
                                    p.setDStatus1(true);
                                }
                                else {
                                    cout << "You survived and you aren't sick anymore." << endl;
                                }
                            }
                        }
                        break;
                    case 2:
                        switch(p4) {
                            case 1:
                                sickness = "typhoid";
                                cout << "Oh no! " << p.getName2() << " has " << sickness << endl;
                                break;
                            case 2:
                                sickness = "cholera";
                                cout << "Oh no! " << p.getName2() << " has " << sickness << endl;
                                break;
                            case 3:
                                sickness = "diarrhea";
                                cout << "Oh no! " << p.getName2() << " has " << sickness << endl;
                                break;
                            case 4:
                                sickness = "the measles";
                                cout << "Oh no! " << p.getName2() << " has " << sickness << endl;
                                break;
                            case 5:
                                sickness = "dysentery";
                                cout << "Oh no! " << p.getName2() << " has " << sickness << endl;
                                break;
                            case 6:
                                sickness = "a fever";
                                cout << "Oh no! " << p.getName2() << " has " << sickness << endl;
                                break;
                        }
                        
                        if(s.getTotKit() > 0) {
                            cout << p.getName2() << " will use one of the medical aid kits" << endl;
                            cout << p.getName2() << " has a 50 percent chance of dying" << endl;
                            s.setKit(-1);
                            s.setTotKit();
                            p5 = rand() % 100 + 1;
                            if(p5 <= 50) {
                                p.setDStatus2(true);
                                cout << p.getName2() << " has died of " << sickness << endl;
                            }
                            else {
                                cout << p.getName2() << " survived and isn't sick anymore." << endl;
                            }
                        }
                        else {
                            cout << "You have the option to rest or press on." << endl;
                            cout << "If you rest you will stop for three days and "<< p.getName2() << " has a 30 percent chance of dying." << endl;
                            cout << "If you press on " << p.getName2() << " has a 70 percent chance of dying." << endl;
                            cout << "Rest: 1, Press on: 2" << endl;
                            cin >> choice;
                            // while(choice < 1 && choice > 2) {
                            //     cin >> choice;
                            // }
                            if(choice == 1) {
                                d.setTotDays(3);
                                cout << "Your party rested for three days" << endl;
                                if(check() == 0) {
                                    return 0;
                                }
                                p5 = rand() % 100 + 1;
                                if(p5 <= 30) {
                                    p.setDStatus2(true);
                                    cout << p.getName2() << " has died of " << sickness << endl;
                                }
                                else {
                                    cout << p.getName2() << " survived and isn't sick anymore." << endl;
                                }
                                nday = 3 + d.getDay();
                                nmonth = d.getMonth();
                                if(nday <= d.getDaysInMonth(nmonth)) {
                                    d.setDay(nday);
                                }
                                else {
                                   nday -= d.getDaysInMonth(nmonth);
                                   nmonth++;
                                   d.setDay(nday);
                                   d.setMonth(nmonth);
                                }
                            }
                            else if(choice == 2) {
                                p5 = rand() % 100 + 1;
                                if(p5 <= 70) {
                                    p.setDStatus2(true);
                                    cout << p.getName2() << " has died of " << sickness << endl;
                                }
                                else {
                                    cout << p.getName2() << " survived and isn't sick anymore." << endl;
                                }
                            }
                        }
                        break;
                    case 3:
                        switch(p4) {
                            case 1:
                                sickness = "typhoid";
                                cout << "Oh no! " << p.getName3() << " has " << sickness << endl;
                                break;
                            case 2:
                                sickness = "cholera";
                                cout << "Oh no! " << p.getName3() << " has " << sickness << endl;
                                break;
                            case 3:
                                sickness = "diarrhea";
                                cout << "Oh no! " << p.getName3() << " has " << sickness << endl;
                                break;
                            case 4:
                                sickness = "the measles";
                                cout << "Oh no! " << p.getName3() << " has " << sickness << endl;
                                break;
                            case 5:
                                sickness = "dysentery";
                                cout << "Oh no! " << p.getName3() << " has " << sickness << endl;
                                break;
                            case 6:
                                sickness = "a fever";
                                cout << "Oh no! " << p.getName3() << " has " << sickness << endl;
                                break;
                        }
                        
                        if(s.getTotKit() > 0) {
                            cout << p.getName3() << " will use one of the medical aid kits" << endl;
                            cout << p.getName3() << " has a 50 percent chance of dying" << endl;
                            s.setKit(-1);
                            s.setTotKit();
                            p5 = rand() % 100 + 1;
                            if(p5 <= 50) {
                                p.setDStatus3(true);
                                cout << p.getName3() << " has died of " << sickness << endl;
                            }
                            else {
                                cout << p.getName3() << " survived and isn't sick anymore." << endl;
                            }
                        }
                        else {
                            cout << "You have the option to rest or press on." << endl;
                            cout << "If you rest you will stop for three days and "<< p.getName3() << " has a 30 percent chance of dying." << endl;
                            cout << "If you press on " << p.getName3() << " has a 70 percent chance of dying." << endl;
                            cout << "Rest: 1, Press on: 2" << endl;
                            cin >> choice;
                            // while(choice < 1 && choice > 2) {
                            //     cin >> choice;
                            // }
                            if(choice == 1) {
                                d.setTotDays(3);
                                cout << "Your party rested for three days" << endl;
                                if(check() == 0) {
                                    return 0;
                                }
                                p5 = rand() % 100 + 1;
                                if(p5 <= 30) {
                                    p.setDStatus3(true);
                                    cout << p.getName3() << " has died of " << sickness << endl;
                                }
                                else {
                                    cout << p.getName3() << " survived and isn't sick anymore." << endl;
                                }
                                nday = 3 + d.getDay();
                                nmonth = d.getMonth();
                                if(nday <= d.getDaysInMonth(nmonth)) {
                                    d.setDay(nday);
                                }
                                else {
                                   nday -= d.getDaysInMonth(nmonth);
                                   nmonth++;
                                   d.setDay(nday);
                                   d.setMonth(nmonth);
                                }
                            }
                            else if(choice == 2) {
                                p5 = rand() % 100 + 1;
                                if(p5 <= 70) {
                                    p.setDStatus3(true);
                                    cout << p.getName3() << " has died of " << sickness << endl;
                                }
                                else {
                                    cout << p.getName3() << " survived and isn't sick anymore." << endl;
                                }
                            }
                        }
                        break;
                    case 4:
                        switch(p4) {
                            case 1:
                                sickness = "typhoid";
                                cout << "Oh no! " << p.getName4() << " has " << sickness << endl;
                                break;
                            case 2:
                                sickness = "cholera";
                                cout << "Oh no! " << p.getName4() << " has " << sickness << endl;
                                break;
                            case 3:
                                sickness = "diarrhea";
                                cout << "Oh no! " << p.getName4() << " has " << sickness << endl;
                                break;
                            case 4:
                                sickness = "the measles";
                                cout << "Oh no! " << p.getName4() << " has " << sickness << endl;
                                break;
                            case 5:
                                sickness = "dysentery";
                                cout << "Oh no! " << p.getName4() << " has " << sickness << endl;
                                break;
                            case 6:
                                sickness = "a fever";
                                cout << "Oh no! " << p.getName4() << " has " << sickness << endl;
                                break;
                        }
                        
                        if(s.getTotKit() > 0) {
                            cout << p.getName4() << " will use one of the medical aid kits" << endl;
                            cout << p.getName4() << " has a 50 percent chance of dying" << endl;
                            s.setKit(-1);
                            s.setTotKit();
                            p5 = rand() % 100 + 1;
                            if(p5 <= 50) {
                                p.setDStatus4(true);
                                cout << p.getName4() << " has died of " << sickness << endl;
                            }
                            else {
                                cout << p.getName4() << " survived and isn't sick anymore." << endl;
                            }
                        }
                        else {
                            cout << "You have the option to rest or press on." << endl;
                            cout << "If you rest you will stop for three days and "<< p.getName4() << " has a 30 percent chance of dying." << endl;
                            cout << "If you press on " << p.getName4() << " has a 70 percent chance of dying." << endl;
                            cout << "Rest: 1, Press on: 2" << endl;
                            cin >> choice;
                            // while(choice < 1 && choice > 2) {
                            //     cin >> choice;
                            // }
                            if(choice == 1) {
                                d.setTotDays(3);
                                cout << "Your party rested for three days" << endl;
                                if(check() == 0) {
                                    return 0;
                                }
                                p5 = rand() % 100 + 1;
                                if(p5 <= 30) {
                                    p.setDStatus4(true);
                                    cout << p.getName4() << " has died of " << sickness << endl;
                                }
                                else {
                                    cout << p.getName4() << " survived and isn't sick anymore." << endl;
                                }
                                nday = 3 + d.getDay();
                                nmonth = d.getMonth();
                                if(nday <= d.getDaysInMonth(nmonth)) {
                                    d.setDay(nday);
                                }
                                else {
                                   nday -= d.getDaysInMonth(nmonth);
                                   nmonth++;
                                   d.setDay(nday);
                                   d.setMonth(nmonth);
                                }
                            }
                            else if(choice == 2) {
                                p5 = rand() % 100 + 1;
                                if(p5 <= 70) {
                                    p.setDStatus4(true);
                                    cout << p.getName4() << " has died of " << sickness << endl;
                                }
                                else {
                                    cout << p.getName4() << " survived and isn't sick anymore." << endl;
                                }
                            }
                        }
                        break;
                    case 5:
                        switch(p4) {
                            case 1:
                                sickness = "typhoid";
                                cout << "Oh no! " << p.getName5() << " has " << sickness << endl;
                                break;
                            case 2:
                                sickness = "cholera";
                                cout << "Oh no! " << p.getName5() << " has " << sickness << endl;
                                break;
                            case 3:
                                sickness = "diarrhea";
                                cout << "Oh no! " << p.getName5() << " has " << sickness << endl;
                                break;
                            case 4:
                                sickness = "the measles";
                                cout << "Oh no! " << p.getName5() << " has " << sickness << endl;
                                break;
                            case 5:
                                sickness = "dysentery";
                                cout << "Oh no! " << p.getName5() << " has " << sickness << endl;
                                break;
                            case 6:
                                sickness = "a fever";
                                cout << "Oh no! " << p.getName5() << " has " << sickness << endl;
                                break;
                        }
                        
                        if(s.getTotKit() > 0) {
                            cout << p.getName5() << " will use one of the medical aid kits" << endl;
                            cout << p.getName5() << " has a 50 percent chance of dying" << endl;
                            s.setKit(-1);
                            s.setTotKit();
                            p5 = rand() % 100 + 1;
                            if(p5 <= 50) {
                                p.setDStatus5(true);
                                cout << p.getName5() << " has died of " << sickness << endl;
                            }
                            else {
                                cout << p.getName5() << " survived and isn't sick anymore." << endl;
                            }
                        }
                        else {
                            cout << "You have the option to rest or press on." << endl;
                            cout << "If you rest you will stop for three days and "<< p.getName5() << " has a 30 percent chance of dying." << endl;
                            cout << "If you press on " << p.getName5() << " has a 70 percent chance of dying." << endl;
                            cout << "Rest: 1, Press on: 2" << endl;
                            cin >> choice;
                            // while(choice < 1 && choice > 2) {
                            //     cin >> choice;
                            // }
                            if(choice == 1) {
                                d.setTotDays(3);
                                cout << "Your party rested for three days" << endl;
                                if(check() == 0) {
                                    return 0;
                                }
                                p5 = rand() % 100 + 1;
                                if(p5 <= 30) {
                                    p.setDStatus5(true);
                                    cout << p.getName5() << " has died of " << sickness << endl;
                                }
                                else {
                                    cout << p.getName5() << " survived and isn't sick anymore." << endl;
                                }
                                nday = 3 + d.getDay();
                                nmonth = d.getMonth();
                                if(nday <= d.getDaysInMonth(nmonth)) {
                                    d.setDay(nday);
                                }
                                else {
                                   nday -= d.getDaysInMonth(nmonth);
                                   nmonth++;
                                   d.setDay(nday);
                                   d.setMonth(nmonth);
                                }
                            }
                            else if(choice == 2) {
                                p5 = rand() % 100 + 1;
                                if(p5 <= 70) {
                                    p.setDStatus5(true);
                                    cout << p.getName5() << " has died of " << sickness << endl;
                                }
                                else {
                                    cout << p.getName5() << " survived and isn't sick anymore." << endl;
                                }
                            }
                        }
                        break;
                }
                if(p.getDStatus1() == true) {
                    cout << "You have died of " << sickness << endl;
                    cout << "Game Over" << endl;
                    results();
                    return 0;
                }
                break;
            case 2:
                s.setOxen(-1);
                s.setTotOxen();
                if(check() == 0) {
                    return 0;
                }
                cout << "Oh no! One of the oxen has died! You have " << s.getTotOxen() << " oxen left" << endl;
                cout << "You will become unable to continue your journey if all of your oxen die" << endl;
                break;
            case 3:
                s.setWagon(-1);
                s.setTotWagon();
                cout << "Oh no! One of your wheels is broken!" << endl;
                if(check() == 0) {
                    return 0;
                }
                break;
        }
    }
    return 1;
}

int Driver::attack() {
    int choice(0), pchoice(0), cashAmt(0), p1(0);
    double p(0.0), m(0.0), m2(0.0), m3(0.0), m4(0.0), percent(0.0);
    
    m = (t.getTotMiles()/100) - 4;
    m2 = (m * m) + 72;
    m3 = (m * m) + 12;
    m4 = (m2 / m3) - 1;
    p = m4 / 10;
    percent = p * 100;
    p1 = rand() % 100 + 1;
    if(p1 <= percent) {
        cout << endl << "Riders ahead! They look hostile." << endl;
        cout << "Run: 1, Attack: 2, Surrender: 3" << endl;
        while(choice < 1 || choice > 3) {
            cin >> choice;
        }
        switch(choice) {
            case 1:
                cout << "You all escaped with your lives, but left behind some supplies." << endl;
                cout << "Due to the commotion you left behind one oxen, 10 lbs of food, and one wagon part." << endl;
                s.setOxen(-1);
                s.setFood(-10);
                s.setWagon(-1);
                s.setTotOxen();
                s.setTotFood();
                s.setTotWagon();
                if(check() == 0) {
                    return 0;
                }
                cout << "You have " << s.getTotOxen() << " oxen left, " << s.getTotFood() << " pounds of food left, and " << s.getTotWagon() << " wagon part(s) left" << endl;
                break;
            case 2:
                cout << "You must solve a puzzle correctly to have a successful attack" << endl;
                cout << "You have three tries to guess the correct random number from 1 to 10" << endl;
                t.setPuzzle();
                for(int i = 0; i < 3; i++) {
                    cout << "Guess a number between 1 and 10" << endl;
                    cin >> pchoice;
                    while(pchoice < 1 && pchoice > 10) {
                        cin >> pchoice;
                    }
                    if(pchoice != t.getPuzzle() && i == 2) {
                        cout << "You didn't solve the puzzle and lost the battle." << endl;
                        cout << "You lose a quarter of your cash reserves and 50 bullets." << endl;
                        cashAmt = s.getCash() * 0.25;
                        s.setCash(-cashAmt);
                        s.setBullets(-50);
                        s.setTotBullets();
                    }
                    if(pchoice != t.getPuzzle() && i != 2) {
                        cout << "That number is incorrect. Try again" << endl;
                    }
                    else if(pchoice == t.getPuzzle()) {
                        i = 2;
                        cout << "You have solved the puzzle and won the battle!" << endl;
                        cout << "You gain 50 lbs of food and 50 bullets" << endl;
                        s.setFood(50);
                        s.setBullets(50);
                        s.setTotFood();
                        s.setTotBullets();
                    }
                }
                break;
            case 3:
                cout << "By surrendering to the raiders you lose a quarter of your cash reserves." << endl;
                cashAmt = s.getCash() * 0.25;
                s.setCash(-cashAmt);
                if(check() == 0) {
                    return 0;
                }
                break;
        }
    }
    return 1;
}

void Driver::milestone() {
    int count(0), tcount(0);
    string line, array[2];
    string filename2 = "fort-milestones.txt";
    string filename3 = "river-milestones.txt";
    ifstream myFile2(filename2);
    ifstream myFile3(filename3);
    if(myFile2.is_open()) {
        while(getline(myFile2, line)) {
            if(count % 2 == 0) {
                ft[tcount].setFortName(line);
            } 
            else {
                ft[tcount].setFortMiles(line);
                tcount++;
            }
            count++;
        }
        myFile2.close();
    }
    count = 0;
    tcount = 0;
    if(myFile3.is_open()) {
        while(getline(myFile3, line)) {
            if(count % 2 == 0) {
                rt[tcount].setRiverName(line);
            }
            
            else {
                split(line, ' ', array, 2);
                rt[tcount].setRiverMiles(array[0]);
                rt[tcount].setRiverDepth(array[1]);
                tcount++;
            }
            count++;
        }
        myFile3.close();
    }
}

int Driver::split(string str, char c, string array[], int size) {
   if (str.length() == 0) {
        return 0;//will return 0 if the string is empty
    }
   string word = "";
   int count = 0;
   str = str + c;
   for (int i = 0; i < str.length(); i++)
   {
       if (str[i] == c)
       {
           if (word.length() == 0)//does this if the word length is 0
               continue;
           array[count++] = word;
           word = "";
       } else {
           word = word + str[i];
       }
   }
   return count;
}

int Driver::check() {
    if(s.getTotFood() <= 0) {
        cout << "Oh no! You ran out of food." << endl;
        cout << "Game Over" << endl;
        results();
        return 0;
    }
    if(d.getDifference() <= 0) {
        cout << "Oh no! You didn't make it to Oregon by November 30th, 1847" << endl;
        cout << "Game Over" << endl;
        results();
        return 0;
    }
    if(s.getTotOxen() <= 0) {
        cout << "You don't have any oxen left. You cannot continue your journey." << endl;
        cout << "Game Over" << endl;
        results();
        return 0;
    }
    if(s.getTotWagon() <= 0) {
        cout << "You don't have any spare wagon parts left. You cannot continue your journey." << endl;
        cout << "Game Over" << endl;
        results();
        return 0;
    }
    if(s.getCash() < 0) {
        cout << "You don't have enough money to get out of this situation" << endl;
        cout << "Game Over" << endl;
        results();
        return 0;
    }
    if(t.getTotMiles() >= 2040) {
        cout << "Congratulations! You have reached Oregon City" << endl;
        cout << "Good luck starting your new life and may your days be filled with happiness" << endl;
        results();
        return 0;
    }
    return 1;
}

void Driver::results() {
    string filename4 = "results.txt";
    ofstream myFile(filename4, ios::app);
    if(s.getTotFood() < 0) {
        int a = s.getTotFood();
        s.setFood(-a);
        s.setTotFood();
    }
    if(s.getCash() < 0) {
        int b = s.getCash();
        s.setCash(-b);
    }
    cout << endl << "Leader Name: " << p.getName1() << endl;
    cout << "Miles Travelled: " << t.getTotMiles() << endl;
    cout << "Food Remaining: " << s.getTotFood() << endl;
    cout << "Cash Remaining: " << s.getCash() << endl;
    if(myFile.is_open()) {
        myFile << "Leader Name: " << p.getName1() << endl;
        myFile << "Miles Travelled: " << t.getTotMiles() << endl;
        myFile << "Food Remaining: " << s.getTotFood() << endl;
        myFile << "Cash Remaining: " << s.getCash() << endl << endl;
    }
}