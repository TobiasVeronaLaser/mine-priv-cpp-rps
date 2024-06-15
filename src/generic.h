#ifndef GENERIC_H
#define GENERIC_H

class LinkedList {
    public:

        LinkedList();

        LinkedList(void *list);

        void *insert(size_t index, void *value);

        string toString();

};

#endif