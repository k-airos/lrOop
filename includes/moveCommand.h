#ifndef MoveCommand_H
#define MoveCommand_H

#include <ctime>
#include <iostream>
#include <string>


using namespace std;

class MoveCommand{
private:
    std::string time;
    int speed;

public:
    MoveCommand();

    MoveCommand(int speed);

    MoveCommand(const MoveCommand &MoveCommand);


    std::string getTime() {
        return time;
    }
    
    int getSpeed() {
        return speed;
    }

    std::string setTime();
    void setSpeed(int speed);
};


#endif  

