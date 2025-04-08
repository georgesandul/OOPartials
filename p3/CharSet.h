#ifndef CHARSET_H
#define CHARSET_H

#include <iostream>
using namespace std;

class CharSet{
    private:
    char *set;
    int length;
    public:

    CharSet(){
        set = new char[256];
        length = 0;
        set[0] = '\0';
    }

    CharSet(const char* x){
        set = new char[256];
        length = 0;
        int xlength = 0;
        while(x[xlength] != '\0'){
            xlength++;
        }

        for(int i = 0; i < xlength; i++){
            bool appeared = false;

            for(int j = 0; j < length; j++){
                if(x[i] == set[j]){
                    appeared = true;
                }
            }

            if(!appeared){
                set[length] = x[i];
                length++;
            }
        }
    }

    CharSet& operator+=(char letter){
        set[length] = letter;
        set[length+1] = '\0';
        length++;
        return *this;
    }

    friend CharSet operator|(const CharSet& x, const CharSet& y) {
        CharSet result;

        // Copy unique characters from 'x'
        for (int i = 0; i < x.length; i++) {
            result += x.set[i];
        }

        // Add unique characters from 'y'
        for (int i = 0; i < y.length; i++) {
            bool appeared = false;
            for (int j = 0; j < result.length; j++) {
                if (y.set[i] == result.set[j]) {
                    appeared = true;
                    break;
                }
            }

            if (!appeared) {
                result += y.set[i];
            }
        }

        for(int i = 0; i < result.length-1; i++){
            for(int j = i; j < result.length; j++){
                char temp;
                if(result.set[j] < result.set[i]){
                    temp = result.set[j];
                    result.set[j] = result.set[i];
                    result.set[i] = temp;
                }
            }
        }

        return result;
    }

    friend CharSet operator&(const CharSet& x, const CharSet& y){
        CharSet result;

        for(int i = 0; i < x.length; i++){
            for(int j = 0; j < y.length; j++){ // initial pusesem ca j pleaca de la i, dar pleaca si el de la 0
                if(x.set[i] == y.set[j]){
                    bool appeared = false;
                    for(int k = 0; k < result.length; k++){
                        if(x.set[i] == result.set[k]) appeared = true;
                    }
                    if(!appeared) result += x.set[i]; 
                }
            }
        }
        return result;
    }

    bool operator[](const char x){
        for(int i=0; i<length; i++){
            if(set[i] == x) return true;
        }

        return false;
    }

    CharSet operator()(const char* x){
        CharSet temp(x);
        CharSet result = *this & temp;

        return result;
    }

    operator int(){
        return length;
    }

    void print(){
        for(int i = 0; i < length; i++){
            cout << set[i] << ",";
        }
        cout << endl;
    }

};

#endif