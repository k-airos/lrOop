#include "moveCommand.h"

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

Queue::Queue(){
    this->first = new ListElement();
    this->count = 1;
}

Queue::Queue(const MoveCommand &obj){
    this->count = 1;
    this->first = new ListElement( obj );
}

// MoveCommand &Queue::get(int pos) const{
//     auto cur = first;

//     for(auto i=0; i<pos&&cur; i++, cur=cur->next);
//     if( cur ) return cur->obj;
//     else return first->obj;

// }
MoveCommand &Queue::get(int pos) const{
    ListElement* cur = first;
    int cnt = this->count;
    for(auto i=0; i<pos&& pos<cnt; i++, cur++);
    if ( cur ) return cur->obj;
    else return first->obj;
}



void Queue::add(const MoveCommand &d){
    if( ListElement* node = new ListElement( d )){
        node->next = first;
        first = node;
        this->count++;
    } else{
        cout<<"something went wrong...";
    }
}

void Queue::del(int pos=0){
    auto cur = first;
    ListElement *prev;

    for(auto i=0; i<pos&& pos<count; i++){
        prev=cur;
        cur=cur->next;
    };

    if (first == cur){
        first = first->next;
        free(cur);
        this->count--;
    }
    else{
        prev->next = cur->next;
        free(cur);
        this->count--;
    }

    }


void Queue::insert(int pos, const MoveCommand &d){
    if( ListElement* node = new ListElement( d )){
        auto cur = first;
        ListElement *prev = NULL;
        for(auto i=0; i<pos&& pos < count; i++){
            prev=cur;
            cur=cur->next;
        };
        if( prev ){
            prev->next = node;
            node->next = cur;
            this->count++;
        }else{
            assert(0);
        }
    }else{
        cout<<"something went wrong...";
    }
}

void Queue::allDelete(){
    auto a = first->next;
    while(a){
        this->del();
        a = first->next;
    }
    this->del();

}

void Queue::getFile(){
    ofstream myfile;
    myfile.open ("info.txt");
    auto cur = first;
    if( first ){
        int i = 1;
        while(cur){
            myfile << i << " элемент списка: " <<endl;
            myfile << "Время: " + cur->obj.getTime() + "Скорость: "  + to_string(cur->obj.getSpeed());
        }
        myfile.close();
    }
}

// void Queue::setFile(){
//     FILE *my_file;
//     my_file = fopen("data.txt", "r");
//     if (my_file == 0)
//     {
//         printf("Error of file opening!");
//     }else{
//         while(fscanf(my_file, "%d",)!=EOF)
//     }
// }

