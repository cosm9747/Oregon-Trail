#ifndef _DATE_H_
#define _DATE_H_

class Date {
    private:
        int totDays, day, month, diff;
    public:
        Date();
        int getTotDays();
        int getDay();
        int getMonth();
        int getYear();
        int getDifference();
        int getDaysInMonth(int);
        void setTotDays(int);
        void setDay(int);
        void setMonth(int);
};

#endif