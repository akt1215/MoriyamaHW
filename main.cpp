#include <iostream>
#include <sstream>
#include <vector>

void swap_start(int& start, int& end){
    if (start>end){
        std::swap(start, end);
    }
}
std::string fizzbuzz1(int num){
    if (num%15 == 0){
        return "FizzBuzz";
    } else if (num%5 == 0){
        return "Buzz";
    } else if (num%3 == 0){
        return "Fizz";
    }
    std::string word = std::to_string(num);
    return word;
}

std::string fizzbuzz2(int num){
    bool three = false;
    bool five = false;
    switch(num/100){
        case 3: {
            three = true;
            break;
        }
        case 5: {
            five = true;
            break;
        }
    }
    switch ((num%100)/10) {
        case 3:{
            three = true;
            break;
        }
        case 5: {
            five = true;
            break;
        }
    }
    switch (num%10) {
        case 3:{
            three = true;
            break;
        }
        case 5:{
            five = true;
            break;
        }
    }


    if (three & five){
        return "fizzbuzz";
    } else if (three){
        return "fizz";
    } else if (five){
        return "buzz";
    } else{
        return std::to_string(num);
    }
}

std::string fizzbuzz3(int num){
    int i = 0;
    bool three = false;
    bool five = false;
    char numbers;
    std::string number = std::to_string(num);
    while (number[i] != '\0') {
        switch (number[i]) {
            case '3':
                three = true;
                break;
            case '5':
                five = true;
                break;
        }
        i++;
    }
    if (three & five){
        return "fizzbuzz";
    } else if (three){
        return "fizz";
    } else if (five){
        return "buzz";
    } else{
        return number;
    }
}

std::vector<std::string> fizzbuzz4(const std::vector<int>& input){
    std::vector<std::string> output;
    std::string tempo;
    int t;
    for (int i=0; i<input.size();i++){
        tempo = std::to_string(input[i]);
        t = 0;
        while (tempo[t] != '\0') {
            switch (tempo[t]) {
                case '3':
                    tempo.replace(tempo.find('3'), 1, "Fizz");
                    break;
                case '5':
                    tempo.replace(tempo.find('5'), 1, "Buzz");
                    break;
            }
            t++;
        }
        output.push_back(tempo);
    }
    return output;
}

int main() {
    int start, end;
    start = 200;
    end = 100;
    swap_start(start, end);
//  For fizzbuzz1 through fizzbuzz3
//    for (int i = start; i <= end; i++){
//        std::string word = fizzbuzz3(i);
//        std::cout << word << ",";
//    }

//  For fizzbuzz4
    std::vector<int> input;
    std::vector<std::string> output;

    for (int i=start; i<=end;i++){
        input.push_back(i);
    }

    output = fizzbuzz4(input);

    for (int i=0; i<output.size();i++){
        std::cout << output[i] << ",";
    }
    std::cout<<"\n";

    return 0;
}
