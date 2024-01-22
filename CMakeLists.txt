cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(example_project)

add_definitions(-DBUILD_PYTHON_EXTENSION)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 设置 CUDA
set(CMAKE_CUDA_COMPILER "/usr/local/cuda/bin/nvcc")
set(CMAKE_CUDA_ARCHITECTURES 75)
enable_language(CUDA)

# 设置 LibTorch
set(CMAKE_PREFIX_PATH "~/libtorch_gpu")
# set(Torch_DIR "~/libtorch_gpu/share/cmake/Torch") # 和上面的二选一 
find_package(Torch REQUIRED)
message(STATUS "TORCH_LIBRARIES: ${TORCH_LIBRARIES}")

# 设置 Pybind11
set(Python3_ROOT_DIR "~/anaconda3")
set(pybind11_DIR "${Python3_ROOT_DIR}/lib/python3.9/site-packages/pybind11/share/cmake/pybind11")
list(APPEND CMAKE_PREFIX_PATH "${pybind11_DIR}")

# 查找 Python3 (若需要)
find_package(Python3 REQUIRED COMPONENTS Interpreter Development) 
# find_package(pybind11 REQUIRED) # 这个暂时不需要了,改用宏控制了
# find_package(pybind11 REQUIRED HINTS "<path-to-pybind11>/share/cmake/pybind11")
message(STATUS "Python Include Directories: ${Python3_INCLUDE_DIRS}")
message(STATUS "Python Libraries: ${Python3_LIBRARIES}")

# 编译项目
add_executable(example_libtorch example_libtorch.cpp)
target_link_libraries(example_libtorch "${TORCH_LIBRARIES}")

add_executable(test_example test_example.cpp example_cuda_func.cu example_cpp_func.cpp 
    example_square.cpp example_cube.cpp)
target_link_libraries(test_example "${TORCH_LIBRARIES}")

# 设置 C++ 标准
set_property(TARGET example_libtorch PROPERTY CXX_STANDARD 17)
set_property(TARGET test_example PROPERTY CXX_STANDARD 17)
