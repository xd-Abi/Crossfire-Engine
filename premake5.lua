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

include "Crossfire-Core"
include "Crossfire-Editor"