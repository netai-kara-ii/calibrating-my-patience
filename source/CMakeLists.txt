add_executable(market market-assets.cc options.cc underlying.cc)

target_include_directories(market PRIVATE
    ${calibration_SOURCE_DIR}/include)

target_link_libraries(market PRIVATE
    Eigen3::Eigen)

set_target_properties(market PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF)

