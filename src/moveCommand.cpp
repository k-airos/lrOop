#include "../includes/moveCommand.h"

MoveCommand::MoveCommand() {
    this->time = "there have been no commands recently";
    this->speed = 0;
}

MoveCommand::MoveCommand(int NewSpeed) {
    this->speed = NewSpeed;
    this->time = setTime();
}

MoveCommand::MoveCommand(const MoveCommand &item) {
    speed = item.speed;
    time  = item.time;
}

void MoveCommand::setSpeed(int speed) {
    this->speed = speed;
    this->time = setTime();
}

std::string MoveCommand::setTime(){
    time_t rawtime;
    struct tm * timeinfo;
    std::time(&rawtime);
    timeinfo = localtime( &rawtime );
    std::string commandTime = std::to_string(timeinfo->tm_hour)+ ':' + std::to_string(timeinfo->tm_min)+ ':' + std::to_string(timeinfo->tm_sec);
    return commandTime;
}
