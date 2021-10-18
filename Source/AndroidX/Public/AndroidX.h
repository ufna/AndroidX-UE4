// Copyright 2020 Vladimir Alyamkin. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "Modules/ModuleInterface.h"

class UAndroidXSettings;

class FAndroidXModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	UAndroidXSettings* ModuleSettings = nullptr;
};
