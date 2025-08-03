#include "../exercise.h"

// READ: 有 cv 限定符的成员函数 <https://zh.cppreference.com/w/cpp/language/member_functions>

struct Fibonacci {
    int numbers[11] = {0, 1}; // 初始化前两个斐波那契数
    
    int get(int i) {
        // 边界检查
        if (i < 0 || i >= 11) return -1;
        
        // 动态计算未缓存的部分
        for (int n = 2; n <= i; ++n) {
            numbers[n] = numbers[n-1] + numbers[n-2];
        }
        
        return numbers[i]; // 返回计算结果
    }
};

int main(int argc, char **argv) {
    Fibonacci FIB{{0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55}};
    ASSERT(FIB.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << FIB.get(10) << std::endl;
    return 0;
}