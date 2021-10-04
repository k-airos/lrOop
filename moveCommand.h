#define MoveCommand_H

#include <ctime>
#include <iostream>
#include <string>
#include <fstream>
#include <cassert>

using namespace std;

class MoveCommand{
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

        MoveCommand obj;
        ListElement *next = NULL;
    };


public:
    ListElement *first = NULL;
    Queue();
    Queue(const MoveCommand &obj);
    void add(const MoveCommand &obj);
    void del(int pos);
    void insert(int pos, const MoveCommand &d);
    MoveCommand &get(int pos) const;
    int getCount() const {return count;};
    void getFile();
    void setFile();
    void allDelete();

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
                m_node = NULL;
            }
        }

    private:
        ListElement* m_node;
    };
};
