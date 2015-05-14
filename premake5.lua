-- premake5.lua
solution "HelloWorld"
  configurations { "Debug", "Release" }

project "HelloWorld"
  kind "ConsoleApp"
  language "C"
  targetdir "bin/%{cfg.buildcfg}"

  files { "**.h", "**.c" }

  filter "configurations:Debug"
    defines { "DEBUG" }
    flags { "Symbols" }

  filter "configurations:Release"
    defines { "NDEBUG" }
    optimize "On"
   
