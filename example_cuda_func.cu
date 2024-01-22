#ifndef BUILD_PYTHON_EXTENSION
#include <torch/extension.h>
#else
#include <torch/torch.h>
#endif

// namespace py = pybind11;
__global__ void example_cuda_kernel(float *x, int size) {
    const int index = blockIdx.x * blockDim.x + threadIdx.x;
    if (index < size) {
        x[index] *= 2;
    }
}

void example_cuda_function(torch::Tensor x) {
    const int threads = 1024;
    const int blocks = (x.numel() + threads - 1) / threads;
    example_cuda_kernel<<<blocks, threads>>>(x.data_ptr<float>(), x.numel());
}

#ifndef BUILD_PYTHON_EXTENSION
PYBIND11_MODULE(TORCH_EXTENSION_NAME, m) {
    m.def("example_cuda_function", &example_cuda_function, "A simple CUDA example function");
}
#endif

