project "Crossfire"
    kind "ConsoleApp"
    language "C++"
    staticruntime "on"

    targetdir (bin)
    objdir (binint)

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
        "vendor/spdlog/include"
    }

    libdirs
    {
    }

    links
    {
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