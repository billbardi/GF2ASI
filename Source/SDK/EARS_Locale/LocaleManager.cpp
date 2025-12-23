#include "LocaleManager.h"

// Hooks
#include "Addons/Hook.h"

int EARS::Locale::LocaleManager::GetNumLanguages()
{
	return MemUtils::CallClassMethod<int, EARS::Locale::LocaleManager*>(0x604350, this);

}

bool EARS::Locale::LocaleManager::GetTextLanguageIsUserSelectable(int index)
{
	return MemUtils::CallClassMethod<bool, EARS::Locale::LocaleManager*, int>(0x602F00, this, index);
}

char* EARS::Locale::LocaleManager::GetTextLanguageCode(int index)
{
	return MemUtils::CallClassMethod<char*, EARS::Locale::LocaleManager*, int>(0x602E60, this, index);
}

void EARS::Locale::LocaleManager::SetCurrentLanguage(int index)
{
	MemUtils::CallClassMethod<void, EARS::Locale::LocaleManager*, int>(0x604360, this, index);
}

EARS::Locale::LocaleManager* EARS::Locale::LocaleManager::GetInstance()
{
	return *(EARS::Locale::LocaleManager**)0x12234A4;
}