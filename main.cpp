#include "mystring.h"
#include <iostream>
#include <utility>

int main() {
    String s1; // ""
    String s2("Hello"); // "Hello"
    String s3(s2); // "Hello" (копия)
    String s4(std::move(s3)); // "Hello" (перемещение, s3 теперь пуст)
    s1 = s2; // копирующее присваивание
    s1.append(", World!");

    std::cout << "s2: "; s2.print(std::cout); std::cout << std::endl;
    std::cout << "s3: "; s3.print(std::cout); std::cout << std::endl;
    std::cout << "s4: "; s4.print(std::cout); std::cout << std::endl;

    s1.print(std::cout); // "Hello, World!"
    std::cout << std::endl;
    size_t pos = s1.find("World");
    std::cout << pos << std::endl; // 7
    return 0;
}