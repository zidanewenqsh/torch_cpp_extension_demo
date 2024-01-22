# torch_cpp_extension_demo
打包pytorch的cpp代码和cuda代码给python使用

这是一个使用 PyTorch C++ API (LibTorch) 和 Pybind11 创建的示例项目。项目包括用于测试 LibTorch 的 C++ 代码，以及一个使用 Pybind11 封装的 Python 扩展模块。

# 文件结构
- example_libtorch.cpp: 测试 LibTorch 功能的独立 C++ 文件。
- example_cpp_func.cpp 和 example_cuda_func.cu: 包含要封装到 Python 扩展的功能的 C++ 和 CUDA 文件。
- example_square.cpp 包含要封装到 Python 扩展的功能的不用PyTorch 的 C++文件, 使用Extension进行封装案例。
- example_cube.cpp 包含要封装到 Python 扩展的功能的不用PyTorch 的 C++文件, 使用Pybind11Extension进行封装案例。
- setup.py: 用于构建和安装 Python 扩展的脚本。
- test_example.py: 测试 Python 扩展的 Python 脚本。
- test_example.cpp: 用于测试封装函数的 C++ 文件。
- CMakeLists.txt: CMake 配置文件，用于构建 C++ 测试和 Python 扩展。
- README.md: 项目说明文件。

# 构建和安装
## 构建 C++ 测试
要构建 C++ 测试，请确保您的系统上安装了 PyTorch (LibTorch) 和 CMake，并执行以下步骤：
```bash
mkdir build
cd build
cmake ..
make
```
这将构建 test_example 和 example_libtorch 可执行文件。

## 构建和安装 Python 扩展

要构建 Python 扩展，首先确保您的系统上安装了 Python、PyTorch 和 Pybind11。然后运行：

1. 构建 Python 扩展
首先，可以构建扩展，而不立即安装它。这在调试和开发过程中非常有用：

```bash
python setup.py build
```
这个命令将编译 Python 扩展，但不会将其安装到您的 Python 环境中。编译后的文件将位于 build 目录下。

2. 安装 Python 扩展
一旦确认构建无误，可以使用以下命令安装扩展：

```bash
python setup.py install
```
这将编译（如果尚未编译）并安装 Python 扩展到 Python 环境中。



# 测试
## 测试 Python 扩展
1. 将生成的so文件复制到根目录下
2. 运行 test_example.py 来测试 Python 扩展：
```bash
python test_example.py
```

## 测试 C++ 代码

运行构建的 test_example 可执行文件来测试 C++ 代码：

```bash
./test_example
```
注意
使用 BUILD_PYTHON_EXTENSION 宏来在 C++ 代码中切换 Python 扩展和纯 C++ 测试代码的编译。这在 example.cpp 和 example_cuda.cu 中使用。
详细信息在CMakeLists.txt中有所说明.

# GitHub
项目源代码可在 GitHub 上找到：[GitHub 项目链接](https://github.com/zidanewenqsh/torch_cpp_extension_demo)

# 许可证
该项目采用 MIT 许可证。详情请见 LICENSE 文件。

