#include <assert.h>
#include <unistd.h>
#include <iostream>
#include "moveCommand.h"

void print(const Queue &obj){
    int i = 1;
    auto cur = obj.HEAD;
    if(cur){
        while( cur ){
            cout<< i << " Объект" <<endl;
            cout<< "Speed: " <<cur->obj.getSpeed() << "Time: " << cur->obj.getTime() <<endl;
            i++;
            cur=cur->next;
        }
    } else cout<<"there is no elements in collection"<<endl;

}

int main() {
    MoveCommand MoveCommand4(666);
    sleep(5);

    MoveCommand MoveCommand1;
    sleep(5);
    
    MoveCommand MoveCommand2(101);
    sleep(5);


    Queue myList;
    myList.add(MoveCommand4); //determ head
    cout << myList.get(0).getSpeed()<<endl;
    myList.add(MoveCommand2);// new head
    cout << myList.get(0).getSpeed()<<endl;
    cout << myList.get(1).getSpeed()<<endl;
    myList.del(1);
    cout<< myList.getCount()<<endl;
    myList.insert(1,MoveCommand2);
    cout<< myList.getCount()<<endl;
    cout << myList.get(0).getSpeed()<<endl;
    cout << myList.get(1).getSpeed()<<endl;
    cout << myList.get(2).getSpeed()<<endl;
    cout << myList.get(5).getSpeed()<<endl;
    cout << myList.get(1).getTime()<<endl;
    myList.getFile();
    Queue myQueue =  myList.setFile();
    Queue myConstQueue(myList);
    if(myList.equalty(myConstQueue)){
        cout<< "This Queues are equal"<<endl;
    }else{
        cout << "Different Queues" <<endl;
    }
    myQueue.allDelete();
    if(myList.equalty(myQueue)){
        cout<< "This Queues are equal"<<endl;
    }else{
            cout << "Different Queues" <<endl;
    }
    MoveCommand MoveCommand5(999);
    int cnt = myList.getCount();
    myList.add(MoveCommand5);
    if(cnt == myList.getCount()) cout<< "This Queues are equal"<<endl;
    else cout<< "Not equal"<<endl;
    print(myQueue);
    print(myList);
    double sumX = myList.xCoordinate("23:59:00");
    return 0;
}
