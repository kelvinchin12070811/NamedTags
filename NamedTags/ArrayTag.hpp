//***********************************************************************************************************
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0.If a copy of the MPL was not distributed with this
// file, You can obtain one at http ://mozilla.org/MPL/2.0/.
//***********************************************************************************************************
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

		void acceptSerializer(const std::string& name, Serializer* engine) override
		{
			engine->arrayStart(name);
			for (size_t itr{ 0 }; itr < this->size(); itr++)
			{
				engine->accept(std::to_string(itr), (*this)[itr]);
			}
			engine->arrayEnd(name);
		}

		std::type_index tagType() override
		{
			return typeid(ArrayTag<T>);
		}
	private:
		ArrayTag() = default;
	};
}