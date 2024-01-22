#include <torch/torch.h>

struct Net : torch::nn::Module {
    Net() {
        fc1 = register_module("fc1", torch::nn::Linear(784, 64));
        fc2 = register_module("fc2", torch::nn::Linear(64, 32));
        fc3 = register_module("fc3", torch::nn::Linear(32, 10));
    }

    torch::Tensor forward(torch::Tensor x) {
        x = torch::relu(fc1->forward(x.reshape({x.size(0), 784})));
        x = torch::relu(fc2->forward(x));
        x = torch::log_softmax(fc3->forward(x), 1);
        return x;
    }

    torch::nn::Linear fc1{nullptr}, fc2{nullptr}, fc3{nullptr};
};

int main() {
    // 实例化模型
    Net model;

    // 模拟一个输入张量
    torch::Tensor input = torch::randn({1, 784}); // 假设输入是28x28的图像，展平为784维

    // 通过网络前向传播得到输出
    torch::Tensor output = model.forward(input);

    std::cout << "Output Tensor: " << output << std::endl;

    return 0;
}
