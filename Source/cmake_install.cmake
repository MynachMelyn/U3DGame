# Install script for directory: D:/repos/Urho/urho3d-master/Source

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
  include("D:/repos/Urho/urho3d-master/Source/ThirdParty/FreeType/cmake_install.cmake")
  include("D:/repos/Urho/urho3d-master/Source/ThirdParty/LZ4/cmake_install.cmake")
  include("D:/repos/Urho/urho3d-master/Source/ThirdParty/PugiXml/cmake_install.cmake")
  include("D:/repos/Urho/urho3d-master/Source/ThirdParty/rapidjson/cmake_install.cmake")
  include("D:/repos/Urho/urho3d-master/Source/ThirdParty/SDL/cmake_install.cmake")
  include("D:/repos/Urho/urho3d-master/Source/ThirdParty/StanHull/cmake_install.cmake")
  include("D:/repos/Urho/urho3d-master/Source/ThirdParty/STB/cmake_install.cmake")
  include("D:/repos/Urho/urho3d-master/Source/ThirdParty/AngelScript/cmake_install.cmake")
  include("D:/repos/Urho/urho3d-master/Source/ThirdParty/Lua/cmake_install.cmake")
  include("D:/repos/Urho/urho3d-master/Source/ThirdParty/toluapp/src/lib/cmake_install.cmake")
  include("D:/repos/Urho/urho3d-master/Source/ThirdParty/Civetweb/cmake_install.cmake")
  include("D:/repos/Urho/urho3d-master/Source/ThirdParty/kNet/cmake_install.cmake")
  include("D:/repos/Urho/urho3d-master/Source/ThirdParty/ik/cmake_install.cmake")
  include("D:/repos/Urho/urho3d-master/Source/ThirdParty/Detour/cmake_install.cmake")
  include("D:/repos/Urho/urho3d-master/Source/ThirdParty/DetourCrowd/cmake_install.cmake")
  include("D:/repos/Urho/urho3d-master/Source/ThirdParty/DetourTileCache/cmake_install.cmake")
  include("D:/repos/Urho/urho3d-master/Source/ThirdParty/Recast/cmake_install.cmake")
  include("D:/repos/Urho/urho3d-master/Source/ThirdParty/Box2D/cmake_install.cmake")
  include("D:/repos/Urho/urho3d-master/Source/ThirdParty/WebP/cmake_install.cmake")
  include("D:/repos/Urho/urho3d-master/Source/ThirdParty/Bullet/cmake_install.cmake")
  include("D:/repos/Urho/urho3d-master/Source/ThirdParty/GLEW/cmake_install.cmake")
  include("D:/repos/Urho/urho3d-master/Source/ThirdParty/LibCpuId/cmake_install.cmake")
  include("D:/repos/Urho/urho3d-master/Source/Urho3D/cmake_install.cmake")
  include("D:/repos/Urho/urho3d-master/Source/Tools/cmake_install.cmake")
  include("D:/repos/Urho/urho3d-master/Source/Samples/cmake_install.cmake")

endif()

