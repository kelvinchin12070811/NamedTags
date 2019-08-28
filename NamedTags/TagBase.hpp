//***********************************************************************************************************
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0.If a copy of the MPL was not distributed with this
// file, You can obtain one at http ://mozilla.org/MPL/2.0/.
//***********************************************************************************************************
#pragma once
#include <cassert>
#include <typeindex>
#include <type_traits>
#include "Serializer.hpp"

namespace named_tags
{
	/**
	 * @addtogroup tags
	 * @{
	 */
	/**
	 * @brief The foundation type of all tags
	 */
	class TagBase
	{ /** @} */
	public:
		virtual ~TagBase() = 0;
		/**
		 * Accept a serializer for serialize or deserialize.
		 * @param name Name of current tag.
		 * @param engine Serializer engine to use.
		 */
		virtual void acceptSerializer(const std::string& name, Serializer* engine) = 0;
		/** Get tag type via typeid. */
		virtual std::type_index tagType() = 0;

		/** Convert TagBase to targeted tag. */
		template <typename T>
		typename std::enable_if<!std::is_same<T, TagBase>::value, T*>::type as()
		{
			auto ptr = dynamic_cast<T*>(this);
			assert((ptr == nullptr ? 0 : 1));
			return ptr;
		}
		/** Convert TagBase to targeted tag. Const version */
		template <typename T>
		typename std::enable_if<!std::is_same<T, TagBase>::value, const T*>::type as() const
		{
			auto ptr = dynamic_cast<const T*>(this);
			assert((ptr == nullptr ? 0 : 1));
			return ptr;
		}
		
		/**
		 * Convert TagBase to targeted tag statically.
		 * @warning This function might cause undefined behaviour if casted to wrong data type.
		 */
		template <typename T>
		typename std::enable_if<!std::is_same<T, TagBase>::value, T*>::type staticAs()
		{
			static_assert(std::is_base_of<TagBase, T>::value, "T must be a child of TagBase.");
			return static_cast<T*>(this);
		}
		/**
		 * Convert TagBase to targeted tag statically. Const version
		 * @warning This function might cause undefined behaviour if casted to wrong data type.
		 */
		template <typename T>
		typename std::enable_if<!std::is_same<T, TagBase>::value, const T*>::type staticAs() const
		{
			static_assert(std::is_base_of<TagBase, T>::value, "T must be a child of TagBase.");
			return static_cast<const T*>(this);
		}
	};
	inline TagBase::~TagBase() = default;
}