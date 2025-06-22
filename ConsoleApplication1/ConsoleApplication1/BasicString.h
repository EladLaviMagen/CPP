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
    * Inserts a character into string
    * :Param index: Index to insert at
    * :Param ch: Character to insert
    * :Return: 0 if successful, -1 if inserting index is out of range
    */
    int insert(int index, const char ch);
    ///Overload, does the same but with const char*
    int insert(int index, const char* strToInsert);
    /// Overload, does the same but with BasicString (uses insert with const char)
    int insert(int index, const BasicString& strToInsert);

    /*
    * Finds first occurance of a character in a string
    * :Param ch: character to find
    * :Param pos: index to start search at, defaults to 0
    * :Return: First occurance start index, -1 returns if character wasn't found
    */
    int find(char ch, int pos=0) const;
    /// Overload, does the same but with a substring to search for
    int find(BasicString& subString, int pos=0) const;

    /*
     * Finds first occurance of a character in a string from right to left
     * :Param ch: character to find
     * :Param pos: index to start search at, defaults to 0
     * :Return: First occurance index, -1 returns if character wasn't found
     */
    int rfind(char ch, int pos = 0) const;
    /// Overload, does the same but with a substring to search for
    int rfind(BasicString& subString, int pos=0) const;

    /// Returns length of string
    int length() const;
    /// Clears string completely (empty string = "")
    void clear();

    /*
    * Checks if string is empty
    * :Return: True if string is empty, False otherwise
    */
    bool empty() const;

    /*
    * Erases a number of character from the string.
    * Will erase a maximum of str_length - start characters
    * :Param start: Index of where erasure starts
    * :Param count: How many characters to erase
    */
    void erase(int start, int count);

    /// Returns represented string as const char*
    const char* c_str() const;

    /*
    * Gets a substring from the string
    * :Param pos: Index to start substring from
    * :Param count: How many characters are in the substring
    * :Return: Substring, as pointer to BasicString
    */
    BasicString* substr(int pos, int count) const;

    /*
    * Compares to strings
    * :Param other: The other string to compare to the string calling the function
    * :Return: True if strings are equal, false otherwise
    */
    bool compare(const BasicString& other) const;

    /*
    * Operator [] - access operator
    * :Param index: Index of character in string
    * :Return: the character at the requested index (if in range)
    */
    char operator[](int index) const;

  private:
    char* m_string;
};
