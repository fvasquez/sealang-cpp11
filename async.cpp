#include <future>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <chrono>

using namespace std;

string flip(string && name)
{
    //cout << this_thread::get_id() << endl;
    //this_thread::sleep_for(chrono::seconds(2));
    reverse(begin(name), end(name));
    return name;
}

int main()
{
    vector<future<string>> futures;
    vector<string> names = { "Jimi Hendrix", "Marilyn Monroe", "James Dean" };

    for (auto& name : names) {
        futures.push_back(async([&name] { return flip(move(name)); }));
    }

    for (auto& ftr : futures) {
        cout << ftr.get() << endl;
    }

    return 0;
}
