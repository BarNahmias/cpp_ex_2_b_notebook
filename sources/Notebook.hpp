
#pragma once
#include <string>
#include <cctype>
#include <string.h>
#include <iostream>
#include "Direction.hpp"
#include "Notebook.hpp"
#include <utility>
#include <unordered_map>






namespace ariel{
    class Notebook{



       private:
             int maxRow;
             int maxCol;
             int minRow;
             int minCol;        

             std::unordered_map<int, std ::unordered_map <int ,std ::unordered_map<int ,char>>> notebook;
             std::unordered_map<int, int> limit_page;
            bool check_clean(int page,int row,int column,Direction d,  const  std:: string &str );
            static bool check_char(const  std::string  &str);
            void static no_space(std:: string str);
            void update_limit( int page, int row, Direction d,int len);
            static bool my_isprint(const std::string  &str);
            public:
            Notebook();

            void write( int page, int row,  int column, Direction d, const std::string &str );
            std::string read( int page, int row,  int column, Direction d,  int length);
            void erase ( int page, int row,  int column, Direction d,  int length );
            void show( int page);


        };

    }







