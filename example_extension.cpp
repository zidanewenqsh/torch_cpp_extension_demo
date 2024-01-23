#include <pybind11/pybind11.h>

// namespace py = pybind11;

int add(int a, int b) {
    return a + b; // 简单的加法
}

PYBIND11_MODULE(example_extension, m) {
    m.def("add", &add, "A function that adds two numbers");
}
