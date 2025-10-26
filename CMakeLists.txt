cmake_minimum_required(VERSION 3.16)

project(QtProject VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Core)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(app
        src/main.cpp
        src/CppWorker.cpp
        src/CppSignalSender.cpp
        src/PropertyWrapper.cpp
        src/QmlJSCaller.cpp
)

qt_add_qml_module(app
    URI QtProject
    VERSION 1.0
    QML_FILES
        style/Main.qml
        style/Other.qml
)

add_subdirectory(src/Movie)
add_subdirectory(src/Singleton)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(app PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.app
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE FALSE
)

target_link_libraries(app
    PRIVATE Qt6::Quick MovieLibplugin SingletonLibplugin
)

target_include_directories(app PRIVATE src)

include(GNUInstallDirs)
install(TARGETS app
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
