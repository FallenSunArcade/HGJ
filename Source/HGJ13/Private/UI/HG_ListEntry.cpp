// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HG_ListEntry.h"
#include "UI/HG_DialogObject.h"

void UHG_ListEntry::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);

	if(ListItemObject)
	{
		DialogObject = Cast<UHG_DialogObject>(ListItemObject);
	}
}
