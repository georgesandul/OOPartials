#ifndef CIRCULARSTRING_H
#define CIRCULARSTRING_H

#include <iostream>

using namespace std;

class CircularString{
    private:
    char* str;
    int size;
    char fillChar;
    int length;

    public:
    CircularString(char ch, int s){
        size = s;
        str = new char[size+1];
        fillChar = ch;
        length = 0;

        for(int i = 0; i < size; i++){
            str[i] = ch;
        }

        str[size] = '\0';
    }

    // CircularString(const CircularString& other){
    //     size = other.size;
    //     str = new char[other.size + 1];
    //     fillChar = other.fillChar;
    //     length = other.length;

    //     for(int i = 0; i < size; i++){
    //         str[i] = other.str[i];
    //     }

    //     str[size] = '\0';
    // }

    operator const char*() const{
        return str;
    }

    CircularString operator+=(char ch){
        if(length < size-1){
            if(str[length] == fillChar) str[length] = ch;
            length++;
        }
        else if(length == size-1){
            if(str[length] == fillChar) str[length] = ch;
        }

        for(int i = 0; i < length-1; i++){
            for(int j = i; j < length; j++){
                char temp;
                if(str[i] < str[j]){
                    temp = str[i];
                    str[i] = str[j];
                    str[j] = temp;
                }
            }
        }
        return *this;
    }

    CircularString& operator++() {
        if (size > 0) {
            char lastChar = str[size - 1];
            for (int i = size - 1; i > 0; i--) {
                str[i] = str[i - 1];
            }
            str[0] = lastChar;
        }
        return *this;
    }

    CircularString operator++(int) {
        CircularString temp = *this;
        ++(*this); // Use the prefix increment logic
        return temp;
    }

    CircularString& operator--(){
        if (size > 0) {
            char firstChar = str[0];
            for (int i = 0; i < size - 1; i++) {
                str[i] = str[i + 1];
            }
            str[size - 1] = firstChar;
        }
        return *this;
    }

    CircularString operator--(int){
        CircularString temp = *this;
        --(*this);
        return temp;
    }

    int operator()(int x) const {
            return static_cast<int>(str[x]);
    }

    operator int() const {
        return size;
    }

};

#endif