cmake_minimum_required(VERSION 3.19)
project(atsar LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(atsar
    WIN32 MACOSX_BUNDLE
    main.cpp
    atsar.cpp
    atsar.h
    atsar.ui
    resources.qrc
    atsarquiz.h atsarquiz.cpp atsarquiz.ui
)

target_link_libraries(atsar
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt6::QSvgPlugin
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
