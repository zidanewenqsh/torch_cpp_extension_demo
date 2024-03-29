import torch
import example_cpp
import example_cuda
import example_square
import example_cube
import example_extension
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

a = 100
b = example_square.mysquare(a)
print("Python Function Output:", b)
c = example_cube.mycube(a)
print("Python Function Output:", c)
# export LD_LIBRARY_PATH=/home/hjimi/libtorch_gpu/lib

a = 100
b = 200
c = example_extension.add(a, b)
print("Extension Function Output:", c)