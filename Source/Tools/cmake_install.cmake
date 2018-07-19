# Install script for directory: D:/repos/Urho/urho3d-master/Source/Tools

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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("D:/repos/Urho/urho3d-master/Source/Tools/Urho3DPlayer/cmake_install.cmake")
  include("D:/repos/Urho/urho3d-master/Source/Tools/AssetImporter/cmake_install.cmake")
  include("D:/repos/Urho/urho3d-master/Source/Tools/OgreImporter/cmake_install.cmake")
  include("D:/repos/Urho/urho3d-master/Source/Tools/PackageTool/cmake_install.cmake")
  include("D:/repos/Urho/urho3d-master/Source/Tools/RampGenerator/cmake_install.cmake")
  include("D:/repos/Urho/urho3d-master/Source/Tools/SpritePacker/cmake_install.cmake")
  include("D:/repos/Urho/urho3d-master/Source/Tools/ScriptCompiler/cmake_install.cmake")

endif()

