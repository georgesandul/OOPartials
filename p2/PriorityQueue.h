#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
using namespace std;

class PriorityQueue{
    private:
    char *data;
    int size;
    int length;

    public:
    PriorityQueue(int s){
        length = 0;
        size = s;
        data = new char[size];
        data[0] = '\0';
    }

    PriorityQueue& operator+=(int numb){
        char c = numb + '0';
        if(length >= size){
            data[length-1] = c;
        }
        else{
            data[length] = c;
            length++;
            data[length] = '\0';
        }
        for(int i=0; i<length-1; i++){
            for(int j=i+1; j<length; j++){
                if(data[j] > data[i]){
                    char temp = data[i];
                    data[i] = data[j];
                    data[j] = temp;
                }
            }
        }
        return *this;
    }

    void show(){
        cout << "Data: " << data << endl;
    }

    operator int() const{
        if (length > size) return size;
        else return length;
    }

    void sort();
};

#endif