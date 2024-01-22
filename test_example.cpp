#include <torch/torch.h>
#include <iostream>

// 假设这些是您的自定义函数原型
torch::Tensor example_function(torch::Tensor x);
void example_cuda_function(torch::Tensor x);
int mysquare(int x);
int mycube(int x);

int main() {
    // 创建一个 Tensor
    torch::Tensor x = torch::tensor({1, 2, 3, 4, 5}, torch::dtype(torch::kFloat32));

    // 测试 C++ 函数
    torch::Tensor y_cpp = example_function(x);
    std::cout << "C++ Function Output: " << y_cpp << std::endl;

    // 测试 CUDA 函数（假设 CUDA 可用）
    if (torch::cuda::is_available()) {
        torch::Tensor x_cuda = x.to(torch::kCUDA);
        // torch::Tensor y_cuda = example_cuda_function(x_cuda);
        std::cout << "CUDA Function Output: " << x_cuda.to(torch::kCPU) << std::endl;
    } else {
        std::cout << "CUDA is not available." << std::endl;
    }

    int a = 100;
    int b = mysquare(a);
    std::cout << "Python Function Output (Square): " << b << std::endl;

    int c = mycube(a);
    std::cout << "Python Function Output (Cube): " << c << std::endl;

    return 0;
}
