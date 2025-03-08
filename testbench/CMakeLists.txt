macro(add_calib_test TARGET_NAME)
    add_executable(${TARGET_NAME} ${ARGN})

    target_link_libraries(${TARGET_NAME} PRIVATE
        Eigen3::Eigen
        GTest::Gtest
        GTest::Main)

    target_include_directories(${TARGET_NAME} PRIVATE
        ${calibration_SOURCE_DIR}/include
        ${GTEST_INCLUDE_DIRS})

    set_target_properties(${TARGET_NAME} PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF) 
endmacro()


add_executable(market_assets "market-assets.cc" "${calibration_SOURCE_DIR}/source/options.cc" "${calibration_SOURCE_DIR}/source/underlying.cc")

target_link_libraries(market_assets PRIVATE
        Eigen3::Eigen
        GTest::GTest
        GTest::Main)

target_include_directories(market_assets PRIVATE
        ${calibration_SOURCE_DIR}/include
        ${GTEST_INCLUDE_DIRS})

set_target_properties(market_assets PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF) 


add_test(NAME MarketAssetsTest COMMAND market_assets)
