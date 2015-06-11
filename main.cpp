#include <iostream>
#include <string>
#include "array.h"

using namespace std;


int main() 
{

    using namespace LP::simpleIndex;
    Security ibm(string("ibm"), 100); 
    Security goog(string("goog"), 200); 
    Security bp(string("bp"), 300); 
    Security cat(string("cat"), 400); 
    Security coco(string("coco"), 500); 

    Index dow(string("dow"), 1);
    dow.insert(&ibm);
    dow.insert(&bp);
    dow.insert(&goog);
    dow.insert(&cat);
    dow.insert(&coco);
    dow.remove(string("ibm"));
    cout << dow.calIndex() << endl;

    dow.remove(string("goog"));

    cout << dow.calIndex() << endl;
    return 0;
}
