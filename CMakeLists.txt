cmake_minimum_required(VERSION 3.16)

project(HKW-Tools VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        Frm_Main.cpp
        Frm_Main.h
        Frm_Main.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(HKW-Tools
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        HKW_Tools/Core/ADB/App/App.cpp 
        HKW_Tools/Core/ADB/Device/Device.cpp 
        HKW_Tools/Core/ADB/Server/Server.cpp 
        HKW_Tools/Core/Terminal/Terminal.cpp 
        HKW_Tools/Core/ADB.h 
        HKW_Tools/Core/Terminal.h 
        HKW_Tools/Data/CmdResult/CmdResult.cpp 
        HKW_Tools/Data/ErrMessage/ErrMessage.cpp 
        HKW_Tools/Data/StringBox/StringBox.cpp 
        HKW_Tools/Data/CmdResult.h 
        HKW_Tools/Data/ErrMessage.h 
        HKW_Tools/Data/StringBox.h
        Debuger.cpp 
        HKW_Tools.h 
        JMessageBox.cpp 
        JMessageBox.h
        HKW-Tools.qrc
        Frm_InstallApp.h 
        Frm_InstallApp.cpp 
        Frm_InstallApp.ui
        HKW-Tools_Icon.png
        Dlg_Loading.h Dlg_Loading.cpp Dlg_Loading.ui
        
        
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET HKW-Tools APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(HKW-Tools SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(HKW-Tools
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(HKW-Tools PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.HKW-Tools)
endif()
set_target_properties(HKW-Tools PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS HKW-Tools
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(HKW-Tools)
endif()
