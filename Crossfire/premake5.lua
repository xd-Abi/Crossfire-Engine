
-- Include directories relative to root folder (solution directory)
IncludeDirs = {}
IncludeDirs["spdlog"] = "vendor/spdlog/include"
IncludeDirs["GLFW"] = "vendor/GLFW/include"
IncludeDirs["glew"] = "vendor/glew/include"

project "Crossfire-Core"
    kind "ConsoleApp"
    language "C++"
    staticruntime "on"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "cfpch.h"
    pchsource "src/cfpch.cpp"

    files
    {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs
    {
        "src",
        IncludeDirs["spdlog"],
        IncludeDirs["GLFW"],
        IncludeDirs["glew"]
    }

    libdirs
    {
        "vendor/GLFW/lib-vc2019",
        "vendor/glew/lib/Release/x64"
    }

    links
    {
        "glfw3.lib",
        "glfw3_mt.lib",
        "glfw3dll.lib",
        "glew32.lib",
        "glew32s.lib",

        "opengl32.lib"
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