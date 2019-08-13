#pragma once
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
std::ostream& operator<<(std::ostream& lhs, named_tags::WrapperTag<T>& rhs)
{
	return lhs << rhs.get();
}

template <typename T>
std::ostream& operator<<(std::ostream& lhs, named_tags::WrapperTag<T>* rhs)
{
	return lhs << *rhs;
}

template <typename T>
std::ostream& operator<<(std::ostream& lhs, std::unique_ptr<named_tags::WrapperTag<T>>& rhs)
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