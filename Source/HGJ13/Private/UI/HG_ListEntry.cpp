// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HG_ListEntry.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "UI/HG_DialogObject.h"

void UHG_ListEntry::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);

	if(ListItemObject)
	{
		DialogObject = Cast<UHG_DialogObject>(ListItemObject);
		check(DialogObject);
		DialogText->SetText(DialogObject->PlayerReply.Reply);
		DialogButton->OnClicked.AddDynamic(this, &UHG_ListEntry::OnButtonClicked);
		DialogButton->OnHovered.AddDynamic(this, &UHG_ListEntry::OnButtonHovered);
		DialogButton->OnUnhovered.AddDynamic(this, &UHG_ListEntry::OnButtonUnHovered);
	}
}

void UHG_ListEntry::OnButtonClicked()
{
	check(DialogObject);
	DialogObject->ReplySelectedDelegate.Broadcast(DialogObject->PlayerReply.Reply,
		DialogObject->PlayerReply.IsHostile, DialogObject->PlayerReply.Index);
}

void UHG_ListEntry::OnButtonHovered()
{
	check(DialogObject);
	if(DialogObject->PlayerReply.IsHostile)
	{
		DialogButton->SetBackgroundColor({1.f, 0.f, 0.f, 0.5f});
	}
	else
	{
		DialogButton->SetBackgroundColor({0.f, 0.2f, 0.f, 0.5f});
	}
}

void UHG_ListEntry::OnButtonUnHovered()
{
	check(DialogObject);
	DialogButton->SetBackgroundColor({0.f, 0.f, 0.f, 0.5f});
}
