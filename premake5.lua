workspace "Spck"
    architecture "x64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Spck"
    location "Spck"
    kind "SharedLib"
    language "C++"
    targetdir ("Build/" .. outputdir .. "/%{prj.name}")
    objdir ("Build/Intermediate/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/Vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "SPCK_PLATFORM_WINDOWS",
            "SPCK_BUILD_DLL"
        }

        postbuildcommands
        {
            "{MKDIR} ../Build/" .. outputdir .. "/Sandbox",
            "{COPY} %{cfg.buildtarget.relpath} ../Build/" .. outputdir .. "/Sandbox"
        }

    filter "configurations:Debug"
        defines "SPCK_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "SPCK_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "SPCK_DIST"
        optimize "On"

    filter { "system:windows", "configurations:Release" }
        buildoptions "/MT"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    targetdir ("Build/" .. outputdir .. "/%{prj.name}")
    objdir ("Build/Intermediate/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Spck/Vendor/spdlog/include",
        "Spck/src"
    }

    links
    {
        "Spck"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "SPCK_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "SPCK_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "SPCK_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "SPCK_DIST"
        optimize "On"

    filter { "system:windows", "configurations:Release" }
        buildoptions "/MT"