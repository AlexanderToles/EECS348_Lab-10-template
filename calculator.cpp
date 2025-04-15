#include "calculator.hpp"
#include <string>
#include <cmath>
using namespace std;

double parse_number(const string &expression){
    double parsed_num = 0.0;
    size_t found = expression.find_first_of("."); 
    for(int i = 0;i < found;++i){
        int val = expression[i]-'0';
        parsed_num+=(val)*pow(10,found-i-1);
    }
    int dec_place = 0;
    for(int i = found+1;i < expression.length();++i){
        dec_place++;
        int val = expression[i]-'0';
        parsed_num+=(val)*pow(0.1,dec_place);
    }
    if(expression[0] == '-'){
        parsed_num*= -1;
    }
    return(parsed_num);
}