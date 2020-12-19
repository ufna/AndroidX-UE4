// Copyright 2020 Vladimir Alyamkin. All Rights Reserved.

#include "AndroidX.h"

#include "AndroidXSettings.h"

#include "Developer/Settings/Public/ISettingsModule.h"
#include "Modules/ModuleManager.h"
#include "UObject/Package.h"

#define LOCTEXT_NAMESPACE "FAndroidXModule"

void FAndroidXModule::StartupModule()
{
	ModuleSettings = NewObject<UAndroidXSettings>(GetTransientPackage(), "AndroidXSettings", RF_Standalone);
	ModuleSettings->AddToRoot();

	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "AndroidX",
			LOCTEXT("AndroidXSettingsName", "AndroidX"),
			LOCTEXT("AndroidXSettingsDescription", "AndroidX and Multidex settings"),
			ModuleSettings);
	}
}

void FAndroidXModule::ShutdownModule()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "AndroidX");
	}

	if (!GExitPurge)
	{
		ModuleSettings->RemoveFromRoot();
	}
	else
	{
		ModuleSettings = nullptr;
	}
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FAndroidXModule, AndroidX)
