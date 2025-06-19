#include "BasicString.h"

BasicString::BasicString(const char* string) {
    this->m_string = (char*)malloc(sizeof(char) * strlen(string) + 1);
    strncpy_s(this->m_string, string);
}

int BasicString::insert(int index, const char ch) {
    if (index > this->length()) {
        return OUT_OF_RANGE;
    }
    realloc(m_string, this->length() + 2);
    m_string[this->length() + 1] = '\0';
    for (int i = this->length() - 1; i <= index; i--) {
        m_string[i + 1] = m_string[i];
    }
    m_string[index] = ch;
    return SUCCESS;
}

int BasicString::insert(int index, const char* strToInsert) {
    if (index > this->length()) {
        return OUT_OF_RANGE;
    }
    realloc(m_string, this->length() + strlen(strToInsert) + 1);
    m_string[this->length() + strlen(strToInsert) + 1] = '\0';
    for (int i = this->length() - 1; i <= index; i--) {
        m_string[i + strlen(strToInsert)] = m_string[i];
    }
    for (unsigned int i = 0; i < strlen(strToInsert); i++) {
        m_string[i + index] = strToInsert[i];
    }
    return SUCCESS;
}

int BasicString::insert(int index, const BasicString& strToInsert) {
    return insert(index, strToInsert.c_str());
}

int BasicString::find(char ch, int pos=0) {
    for (int i = pos; i < this->length(); i++) {
        if (m_string[i] == ch) {
            return i;
        }
    }
    return NOT_FOUND;
}

int BasicString::find(BasicString& subString, int pos=0) {
    int start = find(subString[0], pos);
    if (start == NOT_FOUND || this->length() - start < subString.length()) {
        return NOT_FOUND;
    }
    for (int i = start; i < this->length(); i++) {
        int j = i;
        int k = 0;
        while (m_string[j] == subString[k] && j < this->length() && k < subString.length()) {
            j++;
            k++;
        }
        if (k == subString.length()) {
            return i;
        }
    }
    return NOT_FOUND;
}

char BasicString::operator[](int index) {
    if (index >= this->length()) {
        return NOT_FOUND;
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
    int end = start + count;
    if (end > this->length()) {
        end = this->length();
    }
    for (int i = start; i < end; i++) {
        this->m_string[i] = '\0';
    }
    for (int i = end; i < this->length(); i++) {
        this->m_string[start] = m_string[i];
        this->m_string[i] = '\0';
    }
}

const char* BasicString::c_str() const {
    return this->m_string;
}

int BasicString::rfind(char ch, int pos=0) {
    int foundLast = NOT_FOUND;
    for (int i = pos; i < this->length(); i++) {
        if (m_string[i] == ch) {
            foundLast = i;
        }
    }
    return foundLast;
}



int BasicString::rfind(BasicString& subString, int pos=0) {
    int start = find(subString[0], pos);
    if (start == NOT_FOUND || this->length() - start < subString.length()) {
        return NOT_FOUND;
    }
    int foundLast = NOT_FOUND;
    for (int i = start; i < this->length(); i++) {
        int j = i;
        int k = 0;
        while (m_string[j] == subString[k] && j < this->length() && k < subString.length()) {
            j++;
            k++;
        }
        if (k == subString.length()) {
            foundLast = i;
        }
    }
    return foundLast;
}


BasicString BasicString::substr(int pos, int count) {
    if (pos >= this->length()) {
        throw std::out_of_range("Out of range!");
    }
    int end = pos + count;
    if (end > this->length()) {
        end = this->length();
    }
    char* temp = (char*)malloc(sizeof(char) * (end - pos + 1));
    temp[end - pos + 1] = '\0';
    for (int i = 0; i < end - pos + 1; i++) {
        temp[i] = m_string[i + pos];
    }
    BasicString subString = BasicString(temp);
    delete[] temp;
    return subString;
}

bool BasicString::compare(const BasicString& other) {
    return strcmp(m_string, other.m_string) == 0;
}