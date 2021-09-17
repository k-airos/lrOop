#include <assert.h>
#include <unistd.h>
#include <iostream>
#include "../includes/moveCommand.h"

int main() {
    MoveCommand MoveCommand1;
    assert(MoveCommand1.getSpeed() == 0 );
    cout << MoveCommand1.getTime() << endl;
    MoveCommand MoveCommand2(100);
    assert( MoveCommand2.getSpeed() == 100 );
    cout << "Current time: " << MoveCommand2.getTime() << endl;
    sleep(5);

    MoveCommand MoveCommand3 = MoveCommand2;
    assert( MoveCommand3.getSpeed() == 100 );
    cout << "Current time: " << MoveCommand3.getTime() << endl;
    sleep(5);

    MoveCommand2.setSpeed(150);
    assert(MoveCommand2.getSpeed() == 150);
    cout << "Current time: " << MoveCommand2.getTime() << endl;
    
}