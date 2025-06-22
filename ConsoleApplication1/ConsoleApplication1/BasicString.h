#pragma once
#include <string.h>
#include <stdlib.h>
#include <stdexcept>

#define NOT_FOUND -1
#define OUT_OF_RANGE -1
#define SUCCESS 0;

class BasicString {
  public:
    /*
    * C'tor for Basic String
    * :Param string: String to represent
    */
    explicit BasicString(const char* string);

    ///D'tor for Basic String
    ~BasicString();

    /*
    * Inserters, overloaded versions but all perform the same action :
    * Inserts a value into string
    * :Param index
    */
    int insert(int index, const char ch);
    int insert(int index, const char* strToInsert);
    int insert(int index, const BasicString& strToInsert);
    int find(char ch, int pos=0);
    int find(BasicString& subString, int pos=0);
    int rfind(char ch, int pos = 0);
    int rfind(BasicString& subString, int pos=0);
    int length() const;
    void clear();
    bool empty() const;
    void erase(int start, int count);
    const char* c_str() const;

    BasicString* substr(int pos, int count);
    bool compare(const BasicString& other);

    char operator[](int index);

  private:
    char* m_string;
};
