int main(){
    auto a = 5;         // auto -> int
    auto b = 17.0;      // auto -> float
    auto r1 = ++a;      // = 6
    r1 = a++;           // = 6
    r1 = --a;           // = 6
    r1 = a--;           // = 6
    auto op1 = 17;      // auto -> int
    auto op2 = 2;       // auto -> int
    r1 = op1 >> op2;    // = 4
    r1 = op1 & op2;     // = 0
    r1 = op1 | op2;     // = 19
    r1 = op1 ^ op2;     // = 19
    r1 ^= op2;          // = 1
    a += 5;             // a = 10
    a <<= 7;            // a = 1280
    return 0;
}