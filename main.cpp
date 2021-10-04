#include <assert.h>
#include <unistd.h>
#include <iostream>
#include "moveCommand.h"

int main() {

    MoveCommand MoveCommand1;
    cout << MoveCommand1.getTime() << endl;
    
    MoveCommand MoveCommand2(100);
    assert( MoveCommand2.getSpeed() == 100 );
    cout << "Current time: " << MoveCommand2.getTime() << endl;
    sleep(3);

    MoveCommand MoveCommand3 = MoveCommand2;
    assert( MoveCommand3.getSpeed() == 100 );
    cout << "Current time: " << MoveCommand3.getTime() << endl;
    sleep(3);

    MoveCommand2.setSpeed(150);
    assert(MoveCommand2.getSpeed() == 150);
    cout << "Current time: " << MoveCommand2.getTime() << endl;
    MoveCommand MoveCommand4(666);


    Queue myList;
    myList.add(MoveCommand4); //determ head
    cout << myList.get(0).getSpeed()<<endl;  
    myList.add(MoveCommand2);// new head
    cout << myList.get(0).getSpeed()<<endl; 
    cout << myList.get(1).getSpeed()<<endl;
    myList.del(1);
    cout<< myList.getCount()<<endl;
    myList.insert(1,MoveCommand3);
    cout<< myList.getCount()<<endl;
    cout << myList.get(0).getSpeed()<<endl;
    cout << myList.get(1).getSpeed()<<endl;
    cout << myList.get(2).getSpeed()<<endl;
    cout << myList.get(5).getSpeed()<<endl;
    cout << myList.get(1).getTime()<<endl;
    return 0;
}
