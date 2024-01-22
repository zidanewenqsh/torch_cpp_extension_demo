cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(example_project)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
# 设置 CUDA 编译器路径
set(CMAKE_CUDA_COMPILER "/usr/local/cuda/bin/nvcc")
set(CMAKE_CUDA_ARCHITECTURES 75)
enable_language(CUDA)
add_definitions(-DBUILD_PYTHON_EXTENSION)

# link_directories("/usr/lib/x86_64-linux-gnu")  # 或者适合您系统的实际 CUDA 库路径


# 添加 LibTorch 的 CMake 配置
# list(APPEND CMAKE_PREFIX_PATH "~/anaconda/lib/python3.x/site-packages/torch/share/cmake/Torch")


# 设置libtorch的安装路径
set(Torch_DIR "~/libtorch_gpu/share/cmake/Torch")  # 替换<path_to_libtorch>为实际路径
# 设置 Python 解释器路径
set(Python3_ROOT_DIR "~/anaconda3")
set(Python3_FIND_STRATEGY "LOCATION")
set(pybind11_DIR "${Python3_ROOT_DIR}/lib/python3.9/site-packages/pybind11/share/cmake/pybind11")
set(CMAKE_PREFIX_PATH "~/libtorch_gpu")
list(APPEND CMAKE_PREFIX_PATH "${pybind11_DIR}")

# 设置 Python 解释器路径
# set(Python3_EXECUTABLE "/path/to/anaconda/envs/your_env_name/bin/python")

# 查找 Python 库和头文件
find_package(Python3 REQUIRED COMPONENTS Interpreter Development) # 这个其实也暂时不需要了

# find_package(pybind11 REQUIRED) # 这个暂时不需要了,改用宏控制了
# find_package(pybind11 REQUIRED HINTS "<path-to-pybind11>/share/cmake/pybind11")


# 输出 Python 头文件和库的路径
message(STATUS "Python Include Directories: ${Python3_INCLUDE_DIRS}")
message(STATUS "Python Libraries: ${Python3_LIBRARIES}")
message(STATUS "pybind11_DIR: ${pybind11_DIR}")
message(STATUS "pybind11_LIBRARIES: ${pybind11_LIBRARIES}") # 这个为空,pybind11是一个头文件（header-only）库
message(STATUS "pybind11_INCLUDE_DIRS: ${pybind11_INCLUDE_DIRS}")


# set(PYTHON_INCLUDE_DIRS "/home/hjimi/anaconda3/include/python3.9")
find_package(Torch REQUIRED)

message(STATUS "TORCH_LIBRARIES: ${TORCH_LIBRARIES}")
# message(STATUS "pybind11_DIR: ${pybind11_DIR}")
# # 找到 Python 头文件和库
# find_package(PythonLibs REQUIRED)
add_executable(example_libtorch example_libtorch.cpp)
target_link_libraries(example_libtorch "${TORCH_LIBRARIES}")
# set_property(TARGET example_app PROPERTY CXX_STANDARD 17)

add_executable(test_example test_example.cpp example_cuda_func.cu example_cpp_func.cpp 
    example_square.cpp example_cube.cpp)
# target_include_directories(test_example PRIVATE "${Python3_INCLUDE_DIRS}")
# target_link_libraries(test_example "${Python3_LIBRARIES}" "${TORCH_LIBRARIES}" pybind11::pybind11)
target_link_libraries(test_example "${TORCH_LIBRARIES}")