workspace "Crossfire"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDirs = {}
IncludeDirs["spdlog"] = "%{wks.location}/Core/vendor/spdlog/include"
IncludeDirs["glfw"] = "%{wks.location}/Core/vendor/glfw/include"
IncludeDirs["glad"] = "%{wks.location}/Core/vendor/glad/include"
IncludeDirs["glm"] = "%{wks.location}/Core/vendor/glm"

LibDirs = {}
LibDirs["glfw"] = "%{wks.location}/Core/vendor/glfw/lib-vc2019"

include "Core"
include "Core/vendor/glad"
include "Engine"