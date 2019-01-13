cmake_minimum_required(VERSION 3.2)

project(ip_filter VERSION 1.0.$ENV{TRAVIS_BUILD_NUMBER})

add_executable(ip_filter main.cpp ip4.cpp util.cpp)

set_target_properties(ip_filter PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

install(TARGETS ip_filter RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_NAME ip-filter)
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE amd64)
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Anton Sochnev <an.sochnev@yandex.ru>")
set(CPACK_DEBIAN_PACKAGE_SECTION "homework")
set(CPACK_DEBIAN_PACKAGE_DESCRIPTION 
"some description should be here
 And here."
)
set(CPACK_PACKAGE_FILE_NAME ${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION})

include(CPack)