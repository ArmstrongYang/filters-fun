cmake_minimum_required(VERSION 2.8)

INCLUDE_DIRECTORIES(../include/)
SET(LIBWINDOW_SRC gammaEditWindow.cpp imgEditWindow.cpp)

ADD_LIBRARY(window SHARED ${LIBWINDOW_SRC})

FIND_PACKAGE(OpenCV REQUIRED)
TARGET_LINK_LIBRARIES(window ${OpenCV_LIBS})

SET_TARGET_PROPERTIES(window PROPERTIES OUTPUT_NAME "window")
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)


