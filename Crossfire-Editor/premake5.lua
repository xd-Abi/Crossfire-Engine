project "Crossfire-Editor"
    kind "ConsoleApp"
    language "C++"
    staticruntime "on"

    targetdir (bin)
    objdir (binint)

    files
    {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs
    {
        "src",
        "%{wks.location}/Crossfire-Core/src",
        "%{wks.location}/Crossfire-Core/vendor/spdlog/include"
    }

    libdirs
    {
    }

    links
    {
        "Crossfire-Core"
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