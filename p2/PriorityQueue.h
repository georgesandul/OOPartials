#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
using namespace std;

class PriorityQueue {
    int data[100];
    int length;
    int size;
    int lastPopped;

public:
    PriorityQueue(int cap) {
        size = cap;
        length = 0;
        lastPopped = -1;
    }

    PriorityQueue& operator+=(int value) {
        if(length>=size) {
            data[size-1] = value;
        }
        else{
            data[length] = value;
            length++;
        }
        for(int i=0; i<length-1; i++){
            for(int j=i+1; j<length; j++){
                if(data[j] > data[i]){
                    int temp = data[i];
                    data[i] = data[j];
                    data[j] = temp;
                }
            }
        }
        return *this;
    }

    operator int() {
        if(length > 0){
            return length;
        }
        else return 0;
    }

    int operator--(int) {
        if (length == 0) {
            return 0;
        }
        lastPopped = data[0];
        for (int i = 0; i < length - 1; i++) {
            data[i] = data[i + 1];
        }
        length--;
        return lastPopped;
    }

    int operator()(const char* cmd) {
        // Manual strcmp
        if (equal(cmd, "sum")) {
            int s = 0;
            for (int i = 0; i < length; i++) s += data[i];
            return s;
        } else if (equal(cmd, "count")) {
            return length;
        } else if (equal(cmd, "min")) {
            if (size == 0) return -1;
            int min = data[0];
            for (int i = 1; i < length; i++) {
                if (data[i] < min) min = data[i];
            }
            return min;
        } else if (equal(cmd, "max")) {
            if (size == 0) return -1;
            int max = data[0];
            for (int i = 1; i < length; i++) {
                if (data[i] > max) max = data[i];
            }
            return max;
        }
        return -1;
    }

private:
    bool equal(const char* a, const char* b) {
        while (*a && *b && *a == *b) {
            a++;
            b++;
        }
        return *a == *b;
    }
};


#endif