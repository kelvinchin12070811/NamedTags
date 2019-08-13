#pragma once
#include <iterator>
#include <vector>
#include <memory>
#include "TagBase.hpp"

namespace named_tags
{
	/**
	 * @addtogroup tags
	 * @{
	 */
	/**
	 * @brief Tag that store an array of data.
	 */
	template <typename T>
	class ArrayTag : public TagBase, public std::vector<T>
	{ /** @} */
	public:
		ArrayTag(std::vector<T> data)
		{
			this->reserve(data.size());
			this->insert(this->end(),
				std::make_move_iterator(data.begin()), std::make_move_iterator(data.end()));
		}
		~ArrayTag() = default;

		/**
		 * @name Factory functions
		 * @{
		 */

		/** Create empty tag. */
		static std::unique_ptr<ArrayTag<T>> create()
		{
			return std::unique_ptr<ArrayTag<T>>(new ArrayTag<T>);
		}

		/** Create tag with data. */
		static std::unique_ptr<ArrayTag<T>> create(std::vector<T> data)
		{
			return std::unique_ptr<ArrayTag<T>>(new ArrayTag<T>(std::move(data)));
		}
		/** @} */

		/** Retrun a reference to current instance for foreach loop. */
		ArrayTag& each()
		{
			return const_cast<ArrayTag&>(const_cast<const ArrayTag*>(this)->each());
		}

		/** Retrun a constant reference to current instance for foreach loop. */
		const ArrayTag& each() const
		{
			return *this;
		}

	private:
		ArrayTag() = default;
	};
}