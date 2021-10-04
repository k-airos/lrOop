#define MoveCommand_H

#include <ctime>
#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

class MoveCommand{
public:
    MoveCommand();

    MoveCommand(int speed);

    MoveCommand(const MoveCommand &MoveCommand);
    MoveCommand(int speed, std::string str);


    std::string getTime() {
        return time;
    }

    int getSpeed() {
        return speed;
    }

    std::string setTime();

    void setSpeed(int speed);


private:
    std::string time;
    int speed;
};


class Queue {
private:
    int count = 0;
    struct ListElement{
        ListElement() {
            this->obj =  MoveCommand();
            this->next = NULL;
        };
        ListElement(const MoveCommand &item): obj( item ), next ( NULL ) {};
        ListElement(const ListElement &item){
            this->obj = MoveCommand(item.obj);
            this->next = NULL;
        }

        MoveCommand obj;
        ListElement *next = NULL;
    };

    ListElement *TAIL = NULL;
    ListElement *preTAIL = NULL;
    ListElement *tmp = NULL;


public:
    ListElement *HEAD = NULL;
    Queue();
    Queue(const Queue &obj);
    void add(const MoveCommand &obj);
    void del(int pos);
    void insert(int pos, const MoveCommand &d);
    MoveCommand &get(int pos);
    int getCount() const {return count;};
    void getFile();
    Queue setFile();
    void allDelete();
    bool equalty( const Queue &obj1 );
    double xCoordinate(std::string timePoint);



    class Iterator {
    public:
        Iterator( ListElement* node ) : m_node( node ) { }

        bool operator==( const Iterator& other ) const {
            if( this == &other ) {
                return true;
            }
            return m_node == other.m_node;
        }

        bool operator!=( const Iterator& other ) const {
            return !operator==( other );
        }


        MoveCommand operator*() const {
            if( m_node ) {
                return m_node->obj;
            }
            else{
                assert(0);
            }
        }

        void operator++() {
            if( m_node ) {
                m_node = m_node->next;
            } else{
                assert(0);
            }
        }

    private:
        ListElement* m_node;
    };
};
