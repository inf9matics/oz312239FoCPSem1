#include<iostream>
#include<math.h>


void linear(){
    int a = 0,b = 0;
    std::cout<<"A = ";
    std::cin>>a;
    if(a==0){
        std::cout<<"A can't be 0";
        return;
    }
    std::cout<<"B = ";
    std::cin>>b;
    std::cout<<" x ="<<-b/a;
}

void double_linear(){
    int a1 = 0,b1 = 0,a2 = 0,b2 = 0;
    std::cout<<"A1 = ";
    std::cin>>a1;
    std::cout<<"B1 = ";
    std::cin>>b1;
    std::cout<<"A2 = ";
    std::cin>>a2;
    std::cout<<"B2 = ";
    std::cin>>b2;
    if((a1==0 || a2==0) && (a1 == a2 || b1 != b2) && (a1 == a2 || b1 == b2)){
        std::cout<<"Solution doesn't exist";
        return;
    }
    std::cout<<"("<<(b2-b1)/(a1-a2)<<","<<a1*(b2-b1)/(a1-a2)+b1<<")\n";
}

void quadratic(){
    double a = 0,b = 0,c = 0;
    std::cout <<"A = ";
    std::cin >>a;
    std::cout <<"B = ";
    std::cin >> b;
    std::cout <<"C = ";
    std::cin >>c;
    double delta = (b * b) - (4 * a * c);
    std::cout << "delta : " << delta << std::endl;
    if (delta == 0){
        std::cout << "x = " << -(b / (2 * a));
    }
    else {
        auto sqrt_delta = sqrt(delta);
        std::cout<<"x1 = " << (-b - sqrt_delta) / (2 * a) <<std::endl;
        std::cout<<"x2 = " << (-b + sqrt_delta) / (2 * a);
    }
}

int equations(){
    std::cout<<"Choose type of equations :\n"
             <<"[1] Linear equation\n"
             <<"[2] System of two linear equations\n"
             <<"[3] Quadratic equations\n";
    
    int s = 0;
    std::cin>>s;
    switch(s){
        case 1:
            linear();
            break;
        case 2:
            double_linear();
            break;
        case 3:
            quadratic();
            break;
    }
    return 0;
}