// Fill out your copyright notice in the Description page of Project Settings.


#include "NBFunctionLibrary.h"
#define MAX_NUMBER_COUNT 3

void UNBFunctionLibrary::MyPrintString(const FString& Str)
{
	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Green, Str);
}

FString UNBFunctionLibrary::GenerateRandomNum()
{
	FString ZeroToNine = TEXT("123456789");
	FString Result;

	for (int i = 0; i < MAX_NUMBER_COUNT;i++)
	{
		int32 RandIndex = FMath::RandRange(0, ZeroToNine.Len() - 1);
		Result.AppendChar(ZeroToNine[RandIndex]);
		ZeroToNine.RemoveAt(RandIndex);
	}
	return Result;

}

void UNBFunctionLibrary::GetSBO(const FString& MyNum, const FString& RandomNum, int InS, int InB, int& OutS, int& OutB, FString& OutMsg)
{
	InS = 0;
	InB = 0;
	OutS = 0;
	OutB = 0;

	if (MyNum.Len() > 0 && MyNum[0] != '/')
	{
		OutMsg = MyNum;
		return;
	}

	FString ChoppedNum = MyNum.RightChop(1);
	if (ChoppedNum.Len() != 3)
	{
		OutMsg = TEXT("Notice - Number should be three digits");
		return;
	}

	for (int i = 0; i < ChoppedNum.Len(); i++)
	{
		if (RandomNum[i] == ChoppedNum[i])
		{
			InS++;
		}
		else if (RandomNum.Contains(FString::Chr(ChoppedNum[i])))
		{
			InB++;
		}
	}

	OutS = InS;
	OutB = InB;
	if (InS == 0 && InB == 0)
	{
		OutMsg = TEXT("is out");
	}
	else
	{
		OutMsg = FString::Printf(TEXT("S%dB%d"), OutS, OutB);
	}
}
