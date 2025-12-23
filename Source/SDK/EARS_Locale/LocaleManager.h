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

			// Can this language be used by the user?
			bool GetTextLanguageIsUserSelectable(int index);

			// Get the 2-letter code of the language
			char* GetTextLanguageCode(int index);

			// Set the current language
			void SetCurrentLanguage(int index);

			// Fetch the instance of the Crime Manager
			static LocaleManager* GetInstance();
		};
	} // Locale
} // EARS