#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>
using namespace std;

class Player {
    private:
        string name1;
        string name2;
        string name3;
        string name4;
        string name5;
        bool dStatus1;
        bool dStatus2;
        bool dStatus3;
        bool dStatus4;
        bool dStatus5;
    public:
        Player();
        string getName1();
        string getName2();
        string getName3();
        string getName4();
        string getName5();
        bool getDStatus1();
        bool getDStatus2();
        bool getDStatus3();
        bool getDStatus4();
        bool getDStatus5();
        void setName1(string);
        void setName2(string);
        void setName3(string);
        void setName4(string);
        void setName5(string);
        void setDStatus1(bool);
        void setDStatus2(bool);
        void setDStatus3(bool);
        void setDStatus4(bool);
        void setDStatus5(bool);
};

#endif