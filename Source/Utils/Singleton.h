#pragma once

// Cauldron
#include "Utils/NonCopyable.h"

// Cpp
#include <assert.h>

namespace SH
{
	/**
	 * Singleton class which only accepts one instance per runtime
	 * Note that this is *not* the original game Singleton.
	 * However we should merge them eventually.
	 */
	template<typename T>
	class Singleton : public NonCopyable
	{
	public:

		inline Singleton()
		{
		}

		inline virtual ~Singleton()
		{

		}

		inline static T* Get()
		{
			if (Instance == nullptr)
			{
				Instance = new T();
			}

			return Instance;
		}

		inline static T* GetChecked()
		{
			assert(Instance && "GetChecked expects the Instance to be valid");
			return Instance;
		}

		inline static T& GetCheckedRef()
		{
			assert(Instance && "GetCheckedRef expects the Instance to be valid");
			return *Instance;
		}

		inline static void DestroyInstance()
		{
			if (Instance)
			{
				delete Instance;
				Instance = nullptr;
			}
		}

	private:

		inline static T* Instance;
	};
}
