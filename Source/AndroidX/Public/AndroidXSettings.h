// Copyright 2020 Vladimir Alyamkin. All Rights Reserved.

#pragma once

#include "AndroidXSettings.generated.h"

UCLASS(config = Engine, defaultconfig)
class ANDROIDX_API UAndroidXSettings : public UObject
{
	GENERATED_BODY()

public:
	UAndroidXSettings();

	/* Force Android build to use AndroidX libraries */
	UPROPERTY(Config, EditAnywhere, Category = "AndroidX")
	bool bAndroidXEnabled;

	/* Enable multidex for AndroidX */
	UPROPERTY(Config, EditAnywhere, Category = "AndroidX", meta = (EditCondition = "bAndroidXEnabled"))
	bool bMultiDexEnabled;
};
