#ifndef _SUPPLIES_H_
#define _SUPPLIES_H_

class Supplies {
    private:
        int cash;
        int numOxen;
        int totOxen;
        int oxenPrice;
        int poundsOfFood;
        int totFood;
        int foodPrice;
        int numBullets;
        int totBullets;
        int bulletPrice;
        int numWagonParts;
        int totWagon;
        int wagonPrice;
        int numMedKits;
        int totKit;
        int kitPrice;
    public:
        Supplies();
        int getCash();
        int getOxen();
        int getTotOxen();
        double getOxenPrice(double);
        int getFood();
        int getTotFood();
        double getFoodPrice(double);
        int getBullets();
        int getTotBullets();
        double getBulletPrice(double);
        int getWagon();
        int getTotWagon();
        double getWagonPrice(double);
        int getKit();
        int getTotKit();
        double getKitPrice(double);
        void setCash(int);
        void setOxen(int);
        void setTotOxen();
        void setFood(int);
        void setTotFood();
        void setBullets(int);
        void setTotBullets();
        void setWagon(int);
        void setTotWagon();
        void setKit(int);
        void setTotKit();
};

#endif