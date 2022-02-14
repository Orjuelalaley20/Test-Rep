#include <iostream>
#include <regex>
#include<string>
using namespace std;
int main()
{
    string email="orjuela-------laley@gmail.com";
    auto pattern{"([a-z-]+@([a-z-]+)([a-z]{2,8})([a-z]{2,8})?)"};
    auto reg_ex=regex{pattern,regex_constants::icase};
    if(regex_match(email,reg_ex)){
        cout<<"Email valido\n";
    }
    else{
        cout<<"Email invalido"<<endl;
    }

}