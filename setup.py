from setuptools import setup
from torch.utils.cpp_extension import BuildExtension, CppExtension, CUDAExtension

setup(
    name='example_extension',
    ext_modules=[
        CppExtension(
            name='example_cpp',
            sources=['example_cpp_func.cpp']
        ),
        CUDAExtension(
            name='example_cuda',
            sources=['example_cuda_func.cu']
        )
    ],
    cmdclass={
        'build_ext': BuildExtension
    }
)
