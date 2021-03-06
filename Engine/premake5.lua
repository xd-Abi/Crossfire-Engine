-- Include directories relative to root folder (solution directory)
IncludeDirs = {}
IncludeDirs["spdlog"] = "vendor/spdlog/include"
IncludeDirs["glfw"] = "vendor/glfw/include"
IncludeDirs["glad"] = "vendor/glad/include"
IncludeDirs["glm"] = "vendor/glm"

LibDirs = {}
LibDirs["glfw"] = "vendor/glfw/lib-vc2019"

project "Engine"
    kind "ConsoleApp"
    language "C++"
    staticruntime "on"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "cfpch.h"
    pchsource "src/Core/cfpch.cpp"

    files
    {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs
    {
        "src",
        "%{wks.location}/Core/src"
    }
    
    links
    {
        "Core"
    }

    defines
    {
        "CF_PLATFORM_WINDOWS"
    }


    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

    filter "configurations:Debug"
        defines "CF_DEBUG"    
        symbols "On"
        buildoptions "/MDd"

    filter "configurations:Release"
        defines "CF_RELEASE"
        optimize "On"
        buildoptions "/MD"

    filter "configurations:Dist"
        defines "CF_DIST"
        optimize "On"
        buildoptions "/MD"