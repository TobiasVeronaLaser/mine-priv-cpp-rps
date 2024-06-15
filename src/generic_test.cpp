#include <iostream>
#include "generic.h"

using namespace std;

int main(void){
    LinkedList ll = new LinkedList();
    cout  << ll.toString();
    int i = 0;
    ll.insert(0, &i);
    cout  << ll.toString();
    return EXIT_SUCCESS;
}