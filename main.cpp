// #include "include/game.hpp"
#include "include/ship.hpp"
#include <typeinfo>

int main() {
    int a;
    char b;
    // Ship::type::carrier s = Ship::type::carrier();
    // Ship::type::battleship s2 = Ship::type::battleship();
    // Ship s.alive;

    carrier s = carrier();

    Ship* c = new Ship();

    printf("%d\n", c->alive);

    // Ship sh = Ship();

    // sh = carrier::carrier();

    printf("%s\n", typeid(a).name());
    printf("%s\n", typeid(s).name());
    // printf("%s\n", typeid(s2).name());

    printf("Hello world!\n");

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <string>

// using namespace std;

// int main()
// {
//     vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

//     for (const string& word : msg)
//     {
//         cout << word << " ";
//     }
//     cout << endl;
// }