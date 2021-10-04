#include "moveCommand.h"

MoveCommand::MoveCommand() {
    this->time = "00:00:00";
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

MoveCommand::MoveCommand(int NewSpeed, std::string Ntime) {
    speed = NewSpeed;
    time  = Ntime;
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

int  parse(std::string mytime){
    int sec = stoi(mytime.substr(0,2))*60*60 + stoi(mytime.substr(3,2))*60 + stoi(mytime.substr(6,2));
    return sec;
}

Queue::Queue(){
    this->HEAD = NULL;
    this->count = 0;
}

Queue::Queue(const Queue &obj) {
    this->count = obj.getCount();
    this->HEAD = new ListElement(MoveCommand(obj.HEAD->obj));
//    this->TAIL = new ListElement(MoveCommand(obj.TAIL->obj));
    if( this->tmp ){
        this->tmp = new ListElement(MoveCommand(obj.tmp->obj));
    }else{
        this->tmp = NULL;
    }
    auto cur = obj.HEAD;
    this->TAIL = this->HEAD;
    while( cur ){
        cur=cur->next;
        if( cur ){
            ListElement* node = new ListElement(MoveCommand( cur->obj ));
            this->TAIL->next = node;
            this->preTAIL = this->TAIL;
            this->TAIL = node;
        }

    }
}


 MoveCommand &Queue::get(int pos) {
     auto cur = HEAD;

     for(auto i=0; i<pos&&cur; i++, cur=cur->next);
     if( cur ) return cur->obj;
     tmp = new ListElement;

     return tmp->obj;


 }
//MoveCommand &Queue::get(int pos) const{
//    ListElement* cur = HEAD;
//    int cnt = this->count;
//    int smth = 0;
//    for(auto i=0; (i<pos) && (pos<cnt); i++){
//        smth++;
//        cur++;
//    };
//    if ( cur ) return cur->obj;
//    else return HEAD->obj;
//}



void Queue::add(const MoveCommand &d){ //ДОбавляет объект в список
    if( ListElement* node = new ListElement( d )){
        if( HEAD==NULL ){
            HEAD = node;
            TAIL = HEAD;
            this->count++;
        }else {
            TAIL->next = node;
            preTAIL = TAIL;
            TAIL = node;
            this->count++;
            }

    } else{
        cout<<"something went wrong...";
    }
}

bool Queue::equalty(const Queue &obj1){
    bool flag = 1;
    auto cur1 = obj1.HEAD;
    auto cur2 = this->HEAD;
    while(cur2 && cur1){
        if(!(cur2->obj.getSpeed()==cur1->obj.getSpeed() && cur2->obj.getTime() == cur1->obj.getTime())) flag = 0;
        cur1= cur1->next;
        cur2= cur2->next;
    };
    if((cur2 && !cur1) || (!cur2 && cur1)) flag = 0;
    return flag;
}



void Queue::del(int pos=0){
    auto cur = HEAD;
    ListElement *prev;

    for(auto i=0; i<pos && pos<count; i++){
        prev=cur;
        cur=cur->next;
    };

    if (HEAD == cur){
        HEAD = HEAD->next;
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
        auto cur = HEAD;
        ListElement *prev = NULL;
        for(auto i=0; i<pos&& pos < count+1; i++){
            prev=cur;
            cur=cur->next;
        };
        if( prev ){
            if( prev == TAIL){
               TAIL = preTAIL;
               prev->next = node;
               node->next = cur;
               this->count++;
            }else{
                prev->next = node;
                node->next = cur;
                this->count++;
            }
        }else{
            assert(0);
        }
    }else{
        cout<<"something went wrong...";
    }
}

void Queue::allDelete(){
    auto a = HEAD->next;
    while(a){
        this->del();
        a = HEAD->next;
    }
    this->del();

}

void Queue::getFile(){
    ofstream myfile;
    myfile.open ("/home/kairos/OOP/info.txt");
    auto cur = HEAD;
    if( HEAD ){
        int i = 1;
        while(cur){
            myfile << cur->obj.getTime() + ' ' + to_string(cur->obj.getSpeed())<<endl;
            cur=cur->next;
            i++;
        }
        myfile.close();
    }
}
double Queue::xCoordinate(std::string timePoint){

    auto cur = this->HEAD;
    double sumX = 0;
    int a = parse(timePoint),b = parse(cur->obj.getTime()), c = parse(cur->next->obj.getTime());
    while(cur&& b<= a){
        b = parse(cur->obj.getTime());
        if(a>= c && cur->next){
            c = parse(cur->next->obj.getTime());
            sumX = sumX + ((cur->obj.getSpeed()*0.1)/(3600*0.1))*(c-b);//в км
        }else sumX += ((cur->obj.getSpeed()*0.1)/(3600*0.1))*(a-b);
            cur= cur->next;
        }
    return sumX;
}


Queue Queue::setFile(){
    ifstream file;
    file.open("/home/kairos/OOP/info.txt");
    std::string str;
    Queue myQueue;
    if(file.is_open()){
        while(std::getline(file,str)){
            if(str.find(":") != string::npos){
                       myQueue.add(MoveCommand(stoi(str.substr(str.find(' ')+1)),str.substr(0,str.find(' '))));
            }
        }

     return myQueue;
     }else{
        cout<<"Error";
        Queue smth;
        return smth;
     }
}

