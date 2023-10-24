#include<iostream>

main(){
    double a = 0;
    double b = 0;                               //double is used for every number so answer will show correctly
    std::cout<<"a = ";
    std::cin>>a;
    std::cout<<"b = ";
    std::cin>>b;
    if(a==0 && b!=0){
        std::cout<<"a == 0!";
    }
    else{
        if(a == b && a == 0){
            std::cout<<"Every real number";
        }
        else{
            std::cout<<"x = "<<-b/a;
        }
    }
    return 0;
}