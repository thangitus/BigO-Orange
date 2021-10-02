cmake_minimum_required(VERSION 3.17)
project(BigO-Orange)

set(CMAKE_CXX_STANDARD 14)

file(GLOB APP_SOURCES */*.cpp)
foreach (source_file ${APP_SOURCES})
    get_filename_component(file_name ${source_file} NAME_WLE)
    get_filename_component(dirname ${source_file} DIRECTORY)
    get_filename_component(parent_dir_name ${dirname} NAME)

    string(REPLACE " " "-" parent_dir_name ${parent_dir_name})
    string(REPLACE " " "-" file_name_replace ${file_name})
    string(CONCAT executable_name ${parent_dir_name} "__" ${file_name_replace})

    message("executable_name: ${executable_name} | path: ${dirname}/${file_name}.cpp \n")
    add_executable("${executable_name}" ${dirname}//${file_name}.cpp)
endforeach (source_file ${APP_SOURCES})