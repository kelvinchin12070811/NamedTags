//***********************************************************************************************************
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0.If a copy of the MPL was not distributed with this
// file, You can obtain one at http ://mozilla.org/MPL/2.0/.
//***********************************************************************************************************
#pragma once
#include <cassert>
#include <iostream>
#include <memory>
#include <type_traits>
#include "TagBase.hpp"

namespace named_tags
{
	/**
	 * @addtogroup tags
	 * @{
	 */
	/**
	 * @brief A wrapper that convert almost any data type into tag.
	 */
	template <typename T>
	class WrapperTag : public TagBase
	{ /** @} */
	public:
		~WrapperTag() = default;

		/**
		 * @name Factory functions
		 * @{
		 */
		/**
		 * Factory function to create new empty instance of WrapperTag.
		 */
		static std::unique_ptr<WrapperTag<T>> create()
		{
			return std::unique_ptr<WrapperTag<T>>(new WrapperTag<T>);
		}

		/**
		 * Factory function to create new instance of WrapperTag with value.
		 * @param data Value to initialize the tag
		 */
		static std::unique_ptr<WrapperTag<T>> create(T data)
		{
			return std::unique_ptr<WrapperTag<T>>(new WrapperTag<T>(std::move(data)));
		}
		/** @} */

		/**
		 * Get data stored.
		 */
		T& get()
		{
			return data;
		}

		/**
		 * Get constant variant of data stored.
		 */
		const T& get() const
		{
			return data;
		}

		void acceptSerializer(const std::string& name, Serializer* engine) override
		{
			static_assert(std::numeric_limits<T>::is_specialized,
				"Non built in numeric data type must specialize this function");
			engine->accept(name, data);
		}

		std::type_index tagType() override
		{
			return typeid(WrapperTag<T>);
		}
	private:
		WrapperTag(T data = T{}):
			data(data)
		{
		}
	private:
		T data;
	};
}

template <typename T>
std::ostream& operator<<(std::ostream& lhs, const named_tags::WrapperTag<T>& rhs)
{
	return lhs << rhs.get();
}

template <typename T>
std::ostream& operator<<(std::ostream& lhs, const named_tags::WrapperTag<T>* rhs)
{
	return lhs << *rhs;
}

template <typename T>
std::ostream& operator<<(std::ostream& lhs, const std::unique_ptr<named_tags::WrapperTag<T>>& rhs)
{
	return lhs << *rhs;
}

template <typename T>
std::istream& operator>>(std::istream& lhs, named_tags::WrapperTag<T>& rhs)
{
	return lhs >> rhs.get();
}

template <typename T>
std::istream& operator>>(std::istream& lhs, named_tags::WrapperTag<T>* rhs)
{
	return lhs >> *rhs;
}

template <typename T>
std::istream& operator>>(std::istream& lhs, std::unique_ptr<named_tags::WrapperTag<T>>& rhs)
{
	return lhs >> *rhs;
}

template <typename T>
std::istream& operator>>(std::istream& lhs, const named_tags::WrapperTag<T>& rhs)
{
	static_assert(false, "const tag can't use as input");
	return lhs;
}

template <typename T>
std::istream& operator>>(std::istream& lhs, const named_tags::WrapperTag<T>* rhs)
{
	static_assert(false, "const tag can't use as input");
	return lhs;
}

template <typename T>
std::istream& operator>>(std::istream& lhs, const std::unique_ptr<named_tags::WrapperTag<T>>& rhs)
{
	static_assert(false, "const tag can't use as input");
	return lhs;
}