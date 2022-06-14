#include <iostream>
#include <string>
#include <string.h>
#include "Notebook.hpp"
#include "Direction.hpp"
#include <cctype>
#include <unordered_map>

constexpr unsigned int LIM_ROW = 100;
constexpr unsigned int LIM = 99;

using namespace ariel;
using namespace std;

const char no = '_';

const char tilda = '~';
const char space = ' ';
const char nl = '\n';


namespace ariel{

       Notebook:: Notebook(){
        minRow = minCol = 0;
        maxRow = (int)UINT32_MAX;
        maxCol = LIM_ROW;
        }

         void Notebook:: update_limit (int page, int row, Direction d,int len ) {
            if (d == Direction::Horizontal) {
                limit_page[page] = {row + len};
            } else {
                limit_page[page] = {row};
            }
        }

         bool Notebook::check_clean(int page,int row,int column,Direction d, const string &str ){
           int len=str.length();
                    if (d == Direction::Horizontal){
                        try { notebook[page][row];

                        }
                        catch(exception &e){
                            return true;
                        }
                            for(int i = 0;i<len ;i++ ) {
                                auto it = notebook[page][row].find(column + i);
                                if ((it != notebook[page][row].end()) && (it->second != no)) {
                                    return false;
                                }
                            }
                    }
                    else{
                        try { notebook[page];

                        }
                        catch(exception &e){
                            return true;}
                        for(int i = 0;i<len ;i++ ){
                            auto it = notebook[page].find(row+i);
                            if( it !=notebook[page].end()) {
                                if (it->second.find(column) != notebook[page][row+i].end() && it->second[column]!=no) {
                                    return false;
                                }
                            }
                        }
                    }return true;
            }


            bool Notebook::my_isprint(const string &str){
               for(unsigned i=0;i<str.length();i++){
                   if(isprint(str[i])==0){
                       return false;
                   }
               }
                    return true;
                }

             bool Notebook::check_char(const  string  &str){
                int len=str.length();
                for(unsigned i=0;i<len;i++){
                    if((str.at(i)==tilda)||(str.at(i)==nl)){
                        return false;
                    }
                }return true;
            }

             void Notebook:: no_space( string str){
                unsigned len=str.length();
                for(unsigned i=0;i<len;i++){
                    if(str[i]==space){
                        str[i]=no;}
                }
            }


            void Notebook::write(int page, int row, int column, Direction d, const string &str){
            int len=str.length();


            if (page<0||row<0||column<0 ){
                    throw std::out_of_range("negative input");}


            if (column > LIM){
                    throw std::out_of_range("illegal column location");}

            if (!check_char(str)||!my_isprint(str)){
                throw std::out_of_range("illegal char");}


            if (!check_clean(page,row,column,d,str)){
                throw std::out_of_range("illegal location");}

            update_limit(page,row,d,len);
            string new_str =str ;
             no_space(str);


                    if (d == Direction::Horizontal){
                        if (column+len > LIM ){
                            throw std::out_of_range("can't write on this column location");}

                            for(int i = 0;i<len ;i++ ){
                                unsigned j=(unsigned)i;
                            notebook[page][row][column+i]=new_str[j];}

                    }
                    else{
                            for(int i = 0;i<len ;i++ ){
                                unsigned j=(unsigned)i;
                            notebook[page][row+i][column]=new_str[j];

                            }
                    }
        }





        string Notebook::read( int page, int row,  int column, Direction d,  int length)
        {
            if (page<0||row<0||column<0 ||length<0){
                throw std::out_of_range("negative input");}

            if (column> LIM ){
                throw std::out_of_range("illegal column location,column>99");}


            string read_str;


           if(notebook.find(page)==notebook.end()){
               if (!((d == Direction::Horizontal )&&(column + length-1 > LIM))) {
                   for(unsigned i=0 ;i<length;i++){
                       read_str.push_back(no);
                   }
               } else {throw std::out_of_range("illegal column7 location");}

               return read_str;

        }




            if (d == Direction::Horizontal)
            {
                if (column+length-1 > LIM){
                    throw std::out_of_range("illegal column5 location");}

                for (int i =  column; i < column + length; i++)
                {
                    auto it = notebook[page][row].find(i);
                    if( it !=notebook[page][row].end()){
                        read_str += it->second;
                    }
                    else
                    {
                        read_str += no;
                    }
                }
            }
            else
            {
                for ( int  i = row; i < row + length; i++)
                {
                    auto it = notebook[page][i].find(column);
                    if (it !=notebook[page][i].end())
                    {
                        read_str += it->second;
                    }
                    else
                    {
                        read_str += no;
                    }
                }
            }

            return read_str;
        }




        void  Notebook:: erase ( int page, int row,  int column, Direction d,  int length )         
        {
            if (page<0||row<0||column<0||length<0 ){
                throw std::out_of_range("negative input");}

            if (column > LIM ){
                throw std::out_of_range("illegal column location");
            }


                    if (d == Direction::Horizontal){
                        if (column+length > LIM ){
                            throw std::out_of_range("illegal column location");
                        }
                            for(int i = 0;i<length ;i++ ){
                            notebook[page][row][column+i]=tilda;
                            }
                    }
                    else{
                            for(int  i = 0;i<length ;i++ ){
                            notebook[page][row+i][column]=tilda;
                            }
                    }


            cout << " Deleted row number "<< row << " on page number " <<page << endl;
           
        }








        void Notebook::show(int page)
        {

            if(page<0){
                throw out_of_range("out of range");

            }

//               if (notebook[page].empty()){
//                   throw out_of_range("the page is empty");
//
//               }

        int max=limit_page[page];
        for (int i = minRow; i <= max; i++)
        {
            cout << read(page,i, minCol, Direction::Horizontal, maxCol - minCol) << endl;
        }
    }

    }
