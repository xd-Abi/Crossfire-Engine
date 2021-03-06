-- Include directories relative to root folder (solution directory)
IncludeDirs = {}
IncludeDirs["spdlog"] = "vendor/spdlog/include"
IncludeDirs["glfw"] = "vendor/glfw/include"
IncludeDirs["glad"] = "vendor/glad/include"
IncludeDirs["glm"] = "vendor/glm"

LibDirs = {}
LibDirs["glfw"] = "vendor/glfw/lib-vc2019"

project "Core"
    kind "StaticLib"
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
        IncludeDirs["spdlog"],
        IncludeDirs["glfw"],
        IncludeDirs["glad"],
        IncludeDirs["glm"]
    }

    libdirs
    {
        LibDirs["glfw"]
    }

    links
    {
        "glad",

        "glfw3.lib",
        "glfw3_mt.lib",
        "glfw3dll.lib",

        "opengl32.lib"
    }

    defines
    {
        "CF_PLATFORM_WINDOWS",
        "_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
    }

    postbuildcommands
    {
        ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Engine")
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