add_executable(counter counter.cc cpu-cycles.cc)

set_target_properties(counter PROPERTIES 
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON)
