#ifndef BUILD_PYTHON_EXTENSION
#include <pybind11/pybind11.h>
#endif

int mycube(int x) {
    return x * x * x;
}

#ifndef BUILD_PYTHON_EXTENSION
PYBIND11_MODULE(example_cube, m) {
    m.doc() = "pybind11 cube example plugin"; // 可选模块文档字符串
    m.def("mycube", &mycube, "A function which cubes an integer");
}
#endif



