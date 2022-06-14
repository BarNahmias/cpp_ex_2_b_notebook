////
//// Created by בר נחמיאס on 29/03/2022.
////
#include <iostream>
#include <string>
#include <string.h>
#include "sources/Notebook.hpp"
#include "sources/Direction.hpp"
#include <unordered_map>

using namespace std;
using namespace ariel;

int main()
{
    Notebook notebook;

    notebook.write(1,3,4,Direction::Horizontal ,"wo rld");
    cout<< notebook.read(1,3,4,Direction::Horizontal,12)<<endl;

    string c=notebook.read(1,3,4,Direction::Horizontal,5);
    cout<<c<<endl;
    notebook.erase(1,3,4,Direction::Horizontal ,5);
    cout<< notebook.read(1,3,4,Direction::Horizontal,5)<<endl;

    cout<<"----"<<endl;
    cout<< notebook.read(1,1,98,Direction::Horizontal,5)<<endl;

    return 0;
}