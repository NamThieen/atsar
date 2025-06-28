cmake_minimum_required(VERSION 3.19)
project(atsar LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()
set(RUST_LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/atsar-rust-lib")
set(RUST_INCLUDE_DIR "{CMAKE_CURRENT_SOURCE_DIR}/atsar-rust-lib/src")

qt_add_executable(atsar
    WIN32 MACOSX_BUNDLE
    main.cpp
    atsar.cpp
    atsar.h
    atsar.ui
    resources.qrc
    atsarquiz.h atsarquiz.cpp atsarquiz.ui
)
target_include_directories(atsar
    PRIVATE
        ${RUST_INCLUDE_DIR}
)
find_library(ATSA_QUESTIONS_LIB
             NAMES atsa_questions # Base name of the library (lib will be prepended automatically)
             PATHS ${RUST_LIB_DIR} # Search in the specified build output directory
             NO_DEFAULT_PATH # Only search in the specified paths, not system default paths
            )

if (NOT ATSA_QUESTIONS_LIB)
    message(FATAL_ERROR "Could not find libatsa_questions.so. Please ensure it's built and located in ${RUST_LIB_DIR}")
endif()

target_link_libraries(atsar
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt6::QSvgPlugin
        ${ATSA_QUESTIONS_LIB}
)

include(GNUInstallDirs)

install(TARGETS atsar
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET atsar
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
