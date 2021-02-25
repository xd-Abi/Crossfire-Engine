outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
bin = "%{wks.location}/bin/" .. outputdir .. "/%{prj.name}"
binint = "%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}"

workspace "Crossfire"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

include "Crossfire"

project "Sandbox"
location "Sandbox"
kind "ConsoleApp"
language "C++"

targetdir (bin)
objdir (binint)

files
{
    "%{prj.name}/src/**.h",
    "%{prj.name}/src/**.cpp"
}

includedirs
{
    "Crossfire/src",
    "Crossfire/vendor/spdlog/include"
}

links
{
    "Crossfire"
}

filter "system:windows"
    cppdialect "C++17"
    staticruntime "On"
    systemversion "latest"

    defines
    {
        "CF_PLATFORM_WINDOWS"
    }

filter "configurations:Debug"
    defines "CF_DEBUG"
    buildoptions "/MDd"
    symbols "On"

filter "configurations:Release"
    defines "CF_RELEASE"
    buildoptions "/MD"
    optimize "On"

filter "configurations:Dist"
    defines "CF_DIST"
    buildoptions "/MD"
    optimize "On" 