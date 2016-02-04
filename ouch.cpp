#include <stdexcept>
#include <map>
#include <iostream>

using namespace std;

int main()
{
    int * dynArray = new int[88];
    delete dynArray;

    try {
        throw runtime_error("say what");
    } catch (exception e) {
        cout << "e.what() is " << e.what() << endl;
    }

    map<int, string> elems;
    elems[3] = "maps";
    elems[19] = "are";
    elems[35] = "not";
    elems[47] = "arrays";

    for(uint i = 0; i < elems.size(); ++i) {
        if (elems[i] == "arrays") {
            return i;
        }
    }

    return 0;
}

