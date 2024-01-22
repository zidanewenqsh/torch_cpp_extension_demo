// test_main.cpp
#include <iostream>
#include <torch/torch.h>

// 声明函数原型
torch::Tensor example_function(torch::Tensor x);

int main() {
    // 创建一个张量
    torch::Tensor tensor = torch::rand({2, 3});

    // 调用函数
    torch::Tensor result = example_function(tensor);

    // 输出结果
    std::cout << result << std::endl;

    return 0;
}
