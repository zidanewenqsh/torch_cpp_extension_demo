#ifndef BUILD_PYTHON_EXTENSION
#include <pybind11/pybind11.h>
#endif

int mysquare(int x) {
    return x * x;
}

#ifndef BUILD_PYTHON_EXTENSION
PYBIND11_MODULE(example_square, m) {
    m.doc() = "pybind11 square example plugin"; // 可选模块文档字符串
    m.def("mysquare", &mysquare, "A function which squares an integer");
}
#endif



