//***********************************************************************************************************
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0.If a copy of the MPL was not distributed with this
// file, You can obtain one at http ://mozilla.org/MPL/2.0/.
//***********************************************************************************************************
#pragma once
#include <initializer_list>
#include <map>
#include <memory>
#include <string>
#include "TagBase.hpp"

namespace named_tags
{
	/**
	 * @addtogroup tags
	 * @{
	 */
	/**
	 * @brief Tree that hold the tags with their name.
	 */
	class CompoundTag : public TagBase
	{ /** @} */
	private:
		std::map<std::string, std::unique_ptr<TagBase>> tree;
	public:
		~CompoundTag() = default;

		/**
		 * @name Factory functions
		 * @{
		 */
		/**
		 * Factory function to create new empty CompoundTag instance.
		 */
		static std::unique_ptr<CompoundTag> create();
		/**
		 * Factory function to create new CompoundTag instance.
		 * @param list List of tags to initialize the CompoundTag.
		 */
		static std::unique_ptr<CompoundTag>
			create(std::initializer_list<std::pair<std::string, std::unique_ptr<TagBase>>> tags);
		/** @} */

		/**
		 * Test if contain a specified key.
		 * @return true if @p id found.
		 */
		bool has(const std::string& id) const;
		/**
		 * Insert tag.
		 * @param id Id of the tag.
		 * @param tag Tag to insert.
		 * @return std::pair of std::unique_ptr and bool which indicate as the tag and successness.
		 */
		TagBase* insert(std::string id, std::unique_ptr<TagBase> tag);
		/**
		 * Remove a tag with id from tree.
		 * @return true if success.
		 */
		bool remove(const std::string& id);
		/**
		 * Get tag via id from tree.
		 */
		TagBase* get(const std::string& id);
		/** Get const tag via id from tree. */
		const TagBase* get(const std::string& id) const;
		/** Clear the tree. */
		void clear();

		/** Get reference to the tree for foreach loop. */
		std::map<std::string, std::unique_ptr<TagBase>>& each();
		/** Get constant reference to the tree for foreach loop. */
		const std::map<std::string, std::unique_ptr<TagBase>>& each() const;

		void acceptSerializer(const std::string& name, Serializer* engine) override;
		std::type_index tagType() override;

		/**
		 * @name Iterator
		 * @{
		 */
		decltype(tree)::iterator begin();
		decltype(tree)::iterator end();
		decltype(tree)::const_iterator begin() const;
		decltype(tree)::const_iterator end() const;
		/** @} */
	private:
		CompoundTag() = default;
	};
}