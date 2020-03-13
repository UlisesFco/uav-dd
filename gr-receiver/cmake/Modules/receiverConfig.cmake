INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_RECEIVER receiver)

FIND_PATH(
    RECEIVER_INCLUDE_DIRS
    NAMES receiver/api.h
    HINTS $ENV{RECEIVER_DIR}/include
        ${PC_RECEIVER_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    RECEIVER_LIBRARIES
    NAMES gnuradio-receiver
    HINTS $ENV{RECEIVER_DIR}/lib
        ${PC_RECEIVER_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(RECEIVER DEFAULT_MSG RECEIVER_LIBRARIES RECEIVER_INCLUDE_DIRS)
MARK_AS_ADVANCED(RECEIVER_LIBRARIES RECEIVER_INCLUDE_DIRS)

