// Copyright 2020 Vladimir Alyamkin. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class AndroidX : ModuleRules
{
	public AndroidX(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
			}
			);
			
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
			}
			);
		
		if (Target.Platform == UnrealTargetPlatform.Android)
		{
			PublicDependencyModuleNames.AddRange(new string[] { "Launch" });
			string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
			AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(PluginPath, "AndroidX_UPL_Android.xml"));
		}
	}
}
