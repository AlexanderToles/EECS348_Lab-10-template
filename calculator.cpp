#include "calculator.hpp"
#include <string>
#include <cmath>
using namespace std;

double parse_number(const string &expression){
    string fixed_str = expression;
    double parsed_num = 0.0;
    bool decimal_flag = 0;
    bool operator_flag = 0;
    if((fixed_str[0] == '+')||( fixed_str[0] == '-')){
        operator_flag = 1;
    }
    for(int j = 0; j < fixed_str.length();++j){
        //check for duplicated decimals
        if(fixed_str[j] == '.'){
            if(!decimal_flag){
                decimal_flag = 1;
            }
        }
    }
    if(!decimal_flag){
        fixed_str = fixed_str+".0";
    }
    else{
        while((fixed_str[fixed_str.length()-1]=='0')&&(fixed_str[fixed_str.length()-2]!='.')){
            fixed_str.pop_back();
        }
    }
    //remove leading 0s
    if(operator_flag){
        if(fixed_str[1]=='+'){
            fixed_str.erase(fixed_str.begin(),fixed_str.begin()+1);
        }
        while(fixed_str[1]=='0' && fixed_str[2]!='.'){
            fixed_str.erase(fixed_str.begin()+1,fixed_str.begin()+2);
        }
    }
    else{
        while(fixed_str[0]=='0' && fixed_str[1]!='.'){
            fixed_str.erase(fixed_str.begin(),fixed_str.begin()+1);
        }
    }
    if(fixed_str[0]=='-'){
        size_t found = fixed_str.find_first_of("."); 
        for(int i = found;i > 0;--i){
            parsed_num+=fixed_str[i]*i;
        }
        for(int i = fixed_str.length();i > found;--i){
            parsed_num+=fixed_str[i]*pow(0.1,i);
        }
    }
    
    return(parsed_num);
}