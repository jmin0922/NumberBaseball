// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NBFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class NUMBERBASEBALL_API UNBFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "NB")
	static void MyPrintString(const FString& Str);
	UFUNCTION(BlueprintCallable, Category = "NB")
	static FString GenerateRandomNum();
	UFUNCTION(BlueprintCallable, Category = "NB")
	static void GetSBO(const FString& MyNum, const FString& RandomNum, int InS, int InB, int& OutS, int& OutB, FString& OutMsg);

};
