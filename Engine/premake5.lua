project "Engine"
    kind "ConsoleApp"
    language "C++"
    staticruntime "on"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs
    {
        "src",
        "%{wks.location}/Core/src",
        "%{IncludeDirs.spdlog}",
        "%{IncludeDirs.glfw}",
        "%{IncludeDirs.glad}",
        "%{IncludeDirs.glm}"
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
        symbols "On"
        buildoptions "/MDd"

    filter "configurations:Release"
        optimize "On"
        buildoptions "/MD"

    filter "configurations:Dist"
        optimize "On"
        buildoptions "/MD"