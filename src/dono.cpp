/** Rock-Paper-Scissors Console-Version Prototype-Version
 * Author: Tobias Laser
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

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

class LinkedList{
    private:
        size_t size;
        Node *head, *tail;
    
    public:
        LinkedList(){

        }

        size_t getSize(){
            return size;
        }
        
        

        // if size == 0
        void *insert(size_t index, void *value){
            Node *newNode = new Node(value);
            head = newNode;
            tail = newNode;
            ++size;
            return value;
        }

        // if size != 0 and index == 0
        void *insert(size_t index, void *value){
            Node *newNode = new Node(value, head, NULL);
            head->previous = newNode;
            head = newNode;
            ++size;
            return value;
        }

        // if size != 0 and index == size
        void *insert(size_t index, void *value){
            Node *newNode = new Node(value, NULL, tail);
            tail->next = newNode;
            tail = newNode;
            ++size;
            return value;
        }

        // if size != 0 and index != 0 and index != size
        void *insert(size_t index, void *value){
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
            Node *newNode = new Node(value, currentNode, currentNode->previous);
            currentNode->previous->next = newNode;
            currentNode->previous = newNode;
            ++size;
            return value;
        }
};

class Hand{

};

int main(){
    return EXIT_SUCCESS;
}