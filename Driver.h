#ifndef _DRIVER_H_
#define _DRIVER_H_

class Driver {
    private:
        Supplies s;
        Turn t;
        Turn ft[6];
        Turn rt[4];
        Date d;
        Player p;
        double m;
    public:
        Driver();
        void begin();
        void supplies();
        int turn();
        int misfortunes();
        int attack();
        void milestone();
        int split(string, char, string[], int);
        int check();
        void results();
};

#endif