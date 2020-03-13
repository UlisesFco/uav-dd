INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_JAMMER jammer)

FIND_PATH(
    JAMMER_INCLUDE_DIRS
    NAMES jammer/api.h
    HINTS $ENV{JAMMER_DIR}/include
        ${PC_JAMMER_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    JAMMER_LIBRARIES
    NAMES gnuradio-jammer
    HINTS $ENV{JAMMER_DIR}/lib
        ${PC_JAMMER_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(JAMMER DEFAULT_MSG JAMMER_LIBRARIES JAMMER_INCLUDE_DIRS)
MARK_AS_ADVANCED(JAMMER_LIBRARIES JAMMER_INCLUDE_DIRS)

