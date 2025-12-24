#pragma once

namespace EARS
{
	namespace Locale
	{
		class LocaleManager
		{
		public:

			// Get the number of languages
			int GetNumLanguages();

			// Get the index of the audio with the 2-letter language code
			int FindAudioLanguageIndex(const char* code);

			// Can this language be used by the user?
			bool GetTextLanguageIsUserSelectable(int index);

			// Get the 2-letter code of the language
			char* GetTextLanguageCode(int index);

			// Set the current language
			void SetCurrentLanguage(int index);

			// Set the current audio language
			void SetCurrentAudioLanguage(int index);

			// Fetch the instance of the Locale Manager
			static LocaleManager* GetInstance();
		};
	} // Locale
} // EARS
