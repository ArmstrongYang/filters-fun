cmake_minimum_required(VERSION 2.8)

INCLUDE_DIRECTORIES(../include/)
SET(LIBGRADIENT_SRC ellipseGradient.cpp linearGradient.cpp pointGradient.cpp utility.cpp)

ADD_LIBRARY(gradient SHARED ${LIBGRADIENT_SRC})

FIND_PACKAGE(OpenCV REQUIRED)
TARGET_LINK_LIBRARIES(gradient ${OpenCV_LIBS})

SET_TARGET_PROPERTIES(gradient PROPERTIES OUTPUT_NAME "gradient")
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)


