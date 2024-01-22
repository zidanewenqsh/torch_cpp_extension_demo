from setuptools import setup, Extension
from torch.utils.cpp_extension import BuildExtension, CppExtension, CUDAExtension
from pybind11.setup_helpers import Pybind11Extension, build_ext
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
        ),
        Extension(
            name='example_square',
            sources=['example_square.cpp'],
            include_dirs=['/home/hjimi/anaconda3/lib/python3.9/site-packages/pybind11/include'],  # 可能需要指定 Pybind11 头文件的路径
            extra_compile_args=['-std=c++14']  # 或其它需要的编译标志
        ),
        Pybind11Extension(
            name='example_cube',
            sources=['example_cube.cpp']
        ),
    ],
    cmdclass={
        'build_ext': BuildExtension
    }
)


# from setuptools import setup, Extension
# from pybind11.setup_helpers import Pybind11Extension, build_ext

# ext_modules = [
#     Pybind11Extension(
#         "example",
#         ["example.cpp"],
#     ),
# ]

# setup(
#     name="example",
#     version="0.1",
#     author="Your Name",
#     description="A simple example",
#     ext_modules=ext_modules,
#     cmdclass={"build_ext": build_ext},
# )
