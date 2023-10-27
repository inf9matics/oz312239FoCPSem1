#include<iostream>

void Ex1(){
    int N;
    std::cout<<"Length =";
    std::cin>>N;
    for(int i = 0; i < N; i++){
        std::cout<<"*";
    }
}

void Ex2(){
    int N;
    std::cout<<"Length =";
    std::cin>>N;
    for(int i = 0; i < N; i++){
        if(i % 2 == 0){
            std::cout<<"*";
        }
        else{
            std::cout<<".";
        }
    }
}

void Ex3(){
    int R, C;
    std::cout<<"Columns = ";
    std::cin>>C;
    std::cout<<"Rows = ";
    std::cin>>R;
    for(int r = 0; r < R; r++){
        if(r % 2 == 0){
            for(int c = 0; c < C; c++){
                std::cout<<"X";
            }
            std::cout<<std::endl;
        }
        else{
            for(int c = 0; c < C; c++){
                std::cout<<".";
            }
            std::cout<<std::endl;
        }
    }
}

void Ex4(){
    int N;
    std::cout<<"Length = ";
    std::cin>>N;
    for(int i = 0; i < N; i++){
        for(int x = 0;x < i; x++){
            std::cout<<".";
        }
        for(int x = 0;x < (N - i); x++){
            std::cout<<"X";
        }
        std::cout<<std::endl;
    }
}

void Ex5(){
    int N;
    std::cout<<"Length = ";
    std::cin>>N;
    for(int i = 0; i < N; i++){
        if(i % 2 == 0){
            for(int x = 0; x < N; x++){
                if(x % 2 == 0){
                    std::cout<<"X";}
                else{
                    std::cout<<".";}
            }
        }
        else{
            for(int x = 0; x < N; x++){
                if(x % 2 == 0){
                    std::cout<<".";}
                else{
                    std::cout<<"X";}
            }
        }
        std::cout<<std::endl;
    }
}

void Ex6(){
    int N;
    std::cout<<"Size = ";
    std::cin>>N;
    if(N % 2 == 1){
        N = N + 1;
    }
    for(int i = 0; i < N/2; i++){
        for(int x = 0; x < N/2; x++){
            std::cout<<"X";
        }
        for(int x = 0; x < N/2; x++){
            std::cout<<".";
        }
        std::cout<<std::endl;
    }
    for(int i = 0; i < N/2; i++){
        for(int x = 0; x < N/2; x++){
            std::cout<<".";
        }
        for(int x = 0; x < N/2; x++){
            std::cout<<"X";
        }
        std::cout<<std::endl;
    }
}


int main(){
    int exc;
    std::cout<<"Choose exercise (1-6): \n";
    std::cin>>exc;
    switch(exc){
        case 1:
            Ex1();
            break;
        case 2:
            Ex2();
            break;
        case 3:
            Ex3();
            break;
        case 4:
            Ex4();
            break;
        case 5:
            Ex5();
            break;
        case 6:
            Ex6();
            break;
    }
    return 0;
}