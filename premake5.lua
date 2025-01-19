workspace "Pow"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Pow"
	location "Pow"
	kind "SharedLib"
	language "C++"

	targetdir ("Binaries/"..outputdir.."/%{prj.name}")
	objdir ("Intermediate/"..outputdir.."/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"POW_PLATFORM_WINDOWS",
			"POW_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../Binaries/" ..outputdir.. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "POW_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "POW_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "POW_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("Binaries/"..outputdir.."/%{prj.name}")
	objdir ("Intermediate/"..outputdir.."/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Pow/vendor/spdlog/include",
		"Pow/src"
	}

	links
	{
		"Pow"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"POW_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "POW_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "POW_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "POW_DIST"
		optimize "On"