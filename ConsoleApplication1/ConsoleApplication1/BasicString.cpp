#include "BasicString.h"

BasicString::BasicString(const char* string) {
    this->m_string = new char[strlen(string) + 1];
    this->m_string[strlen(string)] = '\0';
    for (unsigned int i = 0; i < strlen(string); i++) {
        this->m_string[i] = string[i];
    }
}

BasicString::~BasicString() {
    delete[] this->m_string;
}

int BasicString::insert(int index, const char ch) {
    if (index > this->length()) {
        return OUT_OF_RANGE;
    }
    BasicString temp = BasicString(this->c_str());
    delete[] m_string;
    m_string = new char[temp.length() + 2];
    m_string[temp.length() + 1] = '\0';
    for (int i = 0; i < index; i++) {
        m_string[i] = temp[i];
    }
    for (int i = temp.length() - 1; i >= index; i--) {
        m_string[i + 1] = temp[i];
    }
    m_string[index] = ch;
    return SUCCESS;
}

int BasicString::insert(int index, const char* strToInsert) {
    if (index > this->length()) {
        return OUT_OF_RANGE;
    }
    for (unsigned int i = 0; i < strlen(strToInsert); i++) {
        this->insert(i + index, strToInsert[i]);
    }
    return SUCCESS;
}

int BasicString::insert(int index, const BasicString& strToInsert) {
    return insert(index, strToInsert.c_str());
}

int BasicString::find(char ch, int pos) const {
    if (pos < 0) {
        throw std::out_of_range("Out of range!");
    }
    for (int i = pos; i < this->length(); i++) {
        if (m_string[i] == ch) {
            return i;
        }
    }
    return NOT_FOUND;
}

int BasicString::find(const BasicString& subString, int pos) const {
    int start = find(subString[0], pos);
    if (start == NOT_FOUND || this->length() - start < subString.length()) {
        return NOT_FOUND;
    }
    for (int i = start; i <= this->length() - subString.length(); i++) {
        if (m_string[i] == subString[0]) {
            BasicString* testTemp = this->substr(i, subString.length());
            if (testTemp->compare(subString)) {
                delete testTemp;
                return i;
            }
            delete testTemp;
        }
    }
    return NOT_FOUND;
}

char BasicString::operator[](int index) const {
    if (index >= this->length()) {
        throw std::out_of_range("Out of range!");
    }
    return this->m_string[index];
}

int BasicString::length() const{
    return strlen(this->m_string);
}

void BasicString::clear() {
    int length = this->length();
    for (int i = 0; i < length; i++) {
        this->m_string[i] = '\0';
    }
}

bool BasicString::empty() const {
    return this->length() == 0;
}

void BasicString::erase(int start, int count) {
    if (count + start > this->length()) {
        count = this->length() - start;
    }
    int keepLength = this->length();
    for (int i = start; i < start + count; i++) {
        this->m_string[i] = '\0';
    }
    for (int i = start + count; i < keepLength; i++) {
        this->m_string[i - count] = this->m_string[i]; 
        this->m_string[i] = '\0';
    }
    
}

const char* BasicString::c_str() const {
    return this->m_string;
}

int BasicString::rfind(char ch, int pos) const {
    if (pos < 0) {
        throw std::out_of_range("Out of range!");
    }
    for (int i = this->length(); i >= pos; i--) {
        if (m_string[i] == ch) {
            return i;
        }
    }
    return NOT_FOUND;
}



int BasicString::rfind(const BasicString& subString, int pos) const {
    int start = find(subString[0], pos);
    if (start == NOT_FOUND || this->length() - start < subString.length()) {
        return NOT_FOUND;
    }
    for (int i = this->length() - subString.length(); i >= start; i--) {
        if (m_string[i] == subString[0]) {
            BasicString* testTemp = this->substr(i, subString.length());
            if (testTemp->compare(subString)) {
                delete testTemp;
                return i;
            }
            delete testTemp;
        }
    }
    return NOT_FOUND;
}


BasicString* BasicString::substr(int pos, int count) const {
    if (pos >= this->length()) {
        throw std::out_of_range("Out of range!");
    }
    int end = pos + count > this->length() ? this->length() : pos + count;
    char* temp = new char[end - pos + 1];
    temp[end - pos] = '\0';
    for (int i = 0; i < end - pos; i++) {
        temp[i] = m_string[i + pos];
    }
    BasicString* subString = new BasicString(temp);
    delete[] temp;
    return subString;
}

bool BasicString::compare(const BasicString& other) const {
    return strcmp(m_string, other.m_string) == 0;
}