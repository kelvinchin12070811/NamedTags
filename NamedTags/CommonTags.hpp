//***********************************************************************************************************
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0.If a copy of the MPL was not distributed with this
// file, You can obtain one at http ://mozilla.org/MPL/2.0/.
//***********************************************************************************************************
#pragma once
#include <cstddef>
#include <numeric>
#include <WrapperTag.hpp>

namespace named_tags
{
	/**
	 * @addtogroup tags Tags
	 * @brief Named Tags
	 *
	 * @{
	 */

	/**
	 * @defgroup alias_tags Common tags
	 * 
	 * @brief Tags with commonly used data type.
	 *
	 * @{
	 */

	/**
	 * @name Basic data type
	 * @{
	 */
	using BooleanTag = WrapperTag<bool>;
	using ByteTag = WrapperTag<std::byte>;
	using IntTag = WrapperTag<int>;
	using FloatTag = WrapperTag<float>;
	using DoubleTag = WrapperTag<double>;
	using CharTag = WrapperTag<char>;
	using StringTag = WrapperTag<std::string>;
	/** @} */

	/**
	 * @name Signed fixed length
	 * @{
	 */
	using Int8Tag = WrapperTag<int8_t>;
	using Int16Tag = WrapperTag<int16_t>;
	using Int32Tag = WrapperTag<int32_t>;
	using Int64Tag = WrapperTag<int64_t>;
	/** @} */

	/**
	 * @name Unsigned fixed length
	 * @{
	 */
	using Uint8Tag = WrapperTag<uint8_t>;
	using Uint16Tag = WrapperTag<uint16_t>;
	using Uint32Tag = WrapperTag<uint32_t>;
	using Uint64Tag = WrapperTag<uint64_t>;
	/** @} */

	/** @} */
	/** @} */ //group

	// Specialization of acceptSerializer for std::string
	template <>
	void WrapperTag<std::string>::acceptSerializer(const std::string& name, Serializer* engine)
	{
		engine->accept(name, data);
	}

	template <>
	void WrapperTag<std::byte>::acceptSerializer(const std::string& name, Serializer* engine)
	{
		engine->accept(name, data);
	}
}