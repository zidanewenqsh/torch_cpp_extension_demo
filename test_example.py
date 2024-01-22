import torch
import example_cpp
import example_cuda

x = torch.tensor([1, 2, 3, 4, 5], dtype=torch.float32)

# 测试 C++ 函数
y_cpp = example_cpp.example_function(x)
print("C++ Function Output:", y_cpp)

# 测试 CUDA 函数（假设 CUDA 可用）
if torch.cuda.is_available():
    x_cuda = x.cuda()
    example_cuda.example_cuda_function(x_cuda)
    print("CUDA Function Output:", x_cuda.cpu())
else:
    print("CUDA is not available.")
