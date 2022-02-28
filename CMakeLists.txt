cmake_minimum_required(VERSION 3.21)
project(gif_process)

set(CMAKE_CXX_STANDARD 17)

include_directories(D:\\package\\ImageMagick-7.1.0-Q16-HDRI\\include)
add_executable(gif_process main.cpp)

target_link_directories(gif_process PUBLIC D:\\package\\ImageMagick-7.1.0-Q16-HDRI\\lib)
target_link_libraries(gif_process CORE_RL_Magick++_ CORE_RL_MagickCore_ CORE_RL_MagickWand_)