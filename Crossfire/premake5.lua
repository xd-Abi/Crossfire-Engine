
-- Include directories relative to root folder (solution directory)
InlcudeDirs = {}
InlcudeDirs["spdlog"] = "vendor/spdlog/include"
InlcudeDirs["GLFW"] = "vendor/GLFW/include"

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
        InlcudeDirs["spdlog"],
        InlcudeDirs["GLFW"]
    }

    libdirs
    {
        "vendor/GLFW/lib-vc2019"
    }

    links
    {
        "glfw3.lib",
        "glfw3_mt.lib",
        "glfw3dll.lib",

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