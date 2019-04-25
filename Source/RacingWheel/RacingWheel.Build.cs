/************************************************************************************
* Copyright (c) 2015-2016, TU-Ilmenau
* VWDS - Projekt Vista4F
* ===================================================================================
* ===================================================================================
* Authors:  Luis Rojas (luis-alejandro.rojas-vargas@tu-ilmenau.de)
*************************************************************************************/

using UnrealBuildTool;
using System.IO;

public class RacingWheel : ModuleRules
{
	public RacingWheel(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PrivateIncludePathModuleNames.Add("TargetPlatform");
		//PublicAdditionalLibraries.Add("atls.lib");
		
		PublicIncludePaths.AddRange(
			new string[] {			
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				"RacingWheel/Private",
				
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",      // Provides Actors and Structs
				"Engine",           // Used by Actor
				"Slate",            // Used by InputDevice to fire bespoke FKey events
				"InputCore",        // Provides LOCTEXT and other Input features
				"InputDevice",       // Provides IInputInterface
				"RHI"
				
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject", "Engine", "Slate", "SlateCore"
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				
				// ... add any modules that your module loads dynamically here ...
			}
			);
			
		LoadSDLLib(Target);
	}
	
	/***** Externe Functions *****/

	// Get the actual Path the Plugin
	private string ModulePath
	{
	   // get { return Path.GetDirectoryName(RulesCompiler.GetModuleFilename(this.GetType().Name)); }
	   get { return ModuleDirectory; }
	}

	// Get the full Path the Adtionals Libary to Load
	private string ThirdPartyPath
	{
		get { return Path.GetFullPath(Path.Combine(ModulePath, "../../ThirdParty/")); }
	}

	public bool LoadSDLLib(ReadOnlyTargetRules Target)
	{
		bool isLibrarySupported = false;
		string LibrariesPath = "";

		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			isLibrarySupported = true;
			LibrariesPath = Path.Combine(ThirdPartyPath, "WheelLib", "Libraries", "x64"); 
		}
		else if(Target.Platform == UnrealTargetPlatform.Win32)
		{
			isLibrarySupported = true;
			LibrariesPath = Path.Combine(ThirdPartyPath, "WheelLib", "Libraries"); 
		}

		if (isLibrarySupported)
		{
			// Include Libs
			PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "SDL2.lib"));
			PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "SDL2main.lib"));

			// Include path
			PublicIncludePaths.Add(Path.Combine(ThirdPartyPath, "WheelLib", "Includes"));
		}

		return isLibrarySupported;
	}
}
