#ifndef _TURN_H_
#define _TURN_H_
#include <string>
using namespace std;

class Turn {
    private:
        int totMiles;
        int milestone;
        int toNextMilestone;
        int puzzle;
        int rcount;
        int fcount;
        string mName;
        string fName;
        string fMiles;
        string rName;
        string rMiles;
        string rDepth;
    public:
        Turn();
        int getTotMiles();
        int getMilestone();
        int getToNextMilestone();
        int getPuzzle();
        int getRCount();
        int getFCount();
        string getMilestoneName();
        string getFortName();
        string getFortMiles();
        string getRiverName();
        string getRiverMiles();
        string getRiverDepth();
        void setTotMiles(int);
        void setMilestone(int);
        void setToNextMilestone(int);
        void setPuzzle();
        void setRCount();
        void setFCount();
        void setMilestoneName(string);
        void setFortName(string);
        void setFortMiles(string);
        void setRiverName(string);
        void setRiverMiles(string);
        void setRiverDepth(string);
};
#endif