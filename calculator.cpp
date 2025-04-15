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
        if(fixed_str[0]=='+'){
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

    int offset = 0;
    if(fixed_str[0]=='-'){
        offset=1;
    }
    size_t found = fixed_str.find_first_of("."); 
    //cout << "pos: " << found << " length: " << expression.length()<< "\n";
    for(int i = offset;i < found;++i){
        //cout << "i: " << i << " expression[i]: " << expression[i] << "\n";
        int val = fixed_str[i]-'0';
        parsed_num+=(val)*pow(10,found-i-1);
    }
    //cout << "After pre-decimal: " << parsed_num << " \n";
    int dec_place = 0;
    for(int i = found+1;i < fixed_str.length();++i){
        dec_place++;
        //cout << "i: " << i << " expression[i]: " << expression[i] << " dec_place: "<<dec_place<<"\n";
        int val = fixed_str[i]-'0';
        //cout << "(val)*pow(0.1,dec_place): " << (val)*pow(0.1,dec_place) << "\n"; 
        parsed_num+=(val)*pow(0.1,dec_place);
    }
        //cout << "After post-decimal: " << parsed_num << " \n";
    if(fixed_str[0]=='-'){
        parsed_num*=-1;
    }
    return parsed_num;
}