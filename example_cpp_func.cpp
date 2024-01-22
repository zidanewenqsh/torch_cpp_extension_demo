#ifndef BUILD_PYTHON_EXTENSION
#include <torch/extension.h>
#else
#include <torch/torch.h>
#endif

torch::Tensor example_function(torch::Tensor x) {
    return x * 2;
}

#ifndef BUILD_PYTHON_EXTENSION
PYBIND11_MODULE(TORCH_EXTENSION_NAME, m) {
    m.def("example_function", &example_function, "A simple example function");
}
#endif
