#include <iostream>

#define arr_size01(x) (sizeof(x) / sizeof((x)[0]))

template <typename T, size_t N>
consteval size_t arr_size02 (T(&)[N]) { return N; }

int main()
{
    int a[5];
    int g = a[0];
    int *p = a;
    std::cout << std::size(a) << std::endl; // 5
    //std::cout << std::size(p) << std::endl; // compl time error
    //std::cout << std::size(g) << std::endl; // compl time error
    std::cout << arr_size01(a) << std::endl; // 5
    std::cout << arr_size01(p) << std::endl; // 2 - :(
    //std::cout << arr_size01(g) << std::endl; // compl time error
    std::cout << arr_size02(a) << std::endl; // 5
    //std::cout << arr_size02(p) << std::endl; // compl time error
    //std::cout << arr_size02(g) << std::endl; // compl time error

    return 0;
}
