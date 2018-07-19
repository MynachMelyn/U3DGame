# Install script for directory: D:/repos/Urho/urho3d-master

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files/Urho3D")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM FILES
    "D:/repos/Urho/urho3d-master/bin/ConvertModels.bat"
    "D:/repos/Urho/urho3d-master/bin/Editor.bat"
    "D:/repos/Urho/urho3d-master/bin/NinjaSnowWar.bat"
    "D:/repos/Urho/urho3d-master/bin/PBRDemo.bat"
    "D:/repos/Urho/urho3d-master/bin/PBRDemoDeferred.bat"
    "D:/repos/Urho/urho3d-master/bin/PBRDemoDeferredHWDepth.bat"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/./CMake" TYPE DIRECTORY FILES "D:/repos/Urho/urho3d-master/CMake/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/./Scripts" TYPE PROGRAM FILES
    "D:/repos/Urho/urho3d-master/cmake_android.bat"
    "D:/repos/Urho/urho3d-master/cmake_clean.bat"
    "D:/repos/Urho/urho3d-master/cmake_codeblocks.bat"
    "D:/repos/Urho/urho3d-master/cmake_codelite.bat"
    "D:/repos/Urho/urho3d-master/cmake_emscripten.bat"
    "D:/repos/Urho/urho3d-master/cmake_generic.bat"
    "D:/repos/Urho/urho3d-master/cmake_mingw.bat"
    "D:/repos/Urho/urho3d-master/cmake_ninja.bat"
    "D:/repos/Urho/urho3d-master/cmake_vs2015.bat"
    "D:/repos/Urho/urho3d-master/cmake_vs2017.bat"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("D:/repos/Urho/urho3d-master/Source/cmake_install.cmake")
  include("D:/repos/Urho/urho3d-master/Docs/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "D:/repos/Urho/urho3d-master/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
