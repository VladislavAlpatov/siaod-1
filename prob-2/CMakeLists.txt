project(prob2)
add_executable(prob2 main.cpp)
target_sources(prob2 PRIVATE
        matrix/IBaseMatrix.cpp
        matrix/StaticMatrix.cpp
        matrix/DynamicMatrix.cpp
        matrix/VectorMatrix.cpp)