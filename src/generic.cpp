#include "generic.h"
#include <cstdlib>
#include <string>

using namespace std;

class LinkedList {
    class Node{
        public:
            void *value;
            Node *next, *previous;

            Node(){
            value = NULL;
            next = NULL;
            previous = NULL;
            }
            
            Node(void *value){
                this->value = value;
                next = NULL;
                previous = NULL;
            }

            Node(void *value, Node *next, Node *previous){
                this->value = value;
                this->next = next;
                this->previous = previous;
            }
    };

    private:
        size_t size;
        Node *head, *tail;

    public:

        LinkedList(){
            size = 0;
            head = NULL;
            tail = NULL;
        }

        LinkedList(void *list){
            // TODO
        }

        void *insert(size_t index, void *value){
            if(0 > index || index > size || !value){
                return NULL;
            }
            Node *currentNode;
            if(index < size / 2){
                currentNode = head;
                for(size_t i = 0; i < index; ++i){
                    currentNode = currentNode->next;
                }
            }else{
                currentNode = tail;
                for(size_t i = size; i > index; --i){
                    currentNode = currentNode->previous;
                }
            }
            Node *newNode = new Node(value, currentNode, currentNode ? currentNode->previous : NULL);
            if(size && !index){
                head->previous = newNode;
            }
            if(!index){
                head = newNode;
            }
            if(size && index == size){
                tail->next=newNode;
            }
            if(index == size){
                tail = newNode;
            }
            if(size && index && index != size){
                currentNode->previous->next = newNode;
                currentNode->previous = newNode;
            }
            ++size;
            return value;
        }

        string toString(){
            return "" + size;
        }

};