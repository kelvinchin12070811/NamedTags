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
	 * A list of tags with common use data type such as int and float that defined at CommonTags.hpp.
	 * @{
	 */

	/**
	 * @name Basic data type
	 * @{
	 */
	using BooleanTag = WrapperTag<bool>; /**< Boolean type */
	using ByteTag = WrapperTag<std::byte>; /**< Byte type */
	using IntTag = WrapperTag<int>; /**< Int type */
	using UIntTag = WrapperTag<unsigned int>; /**< Unsigned int type */
	using FloatTag = WrapperTag<float>; /**< Float type */
	using DoubleTag = WrapperTag<double>; /**< Double type */
	using CharTag = WrapperTag<char>; /**< Char type */
	using StringTag = WrapperTag<std::string>; /**< String type */
	/** @} */

	/**
	 * @name Signed fixed length
	 * @{
	 */
	using Int8Tag = WrapperTag<int8_t>; /**< 8 bit int type */
	using Int16Tag = WrapperTag<int16_t>; /**< 16 bit int type */
	using Int32Tag = WrapperTag<int32_t>; /**< 32 bit int type */
	using Int64Tag = WrapperTag<int64_t>; /**< 64 bit int type */
	/** @} */

	/**
	 * @name Unsigned fixed length
	 * @{
	 */
	using Uint8Tag = WrapperTag<uint8_t>; /**< 8 bit unsigned int type */
	using Uint16Tag = WrapperTag<uint16_t>; /**< 16 bit unsigned int type */
	using Uint32Tag = WrapperTag<uint32_t>; /**< 32 bit unsigned int type */
	using Uint64Tag = WrapperTag<uint64_t>; /**< 64 bit unsigned int type */
	/** @} */

	/** @} */
	/** @} */ //group

	// Specialization of acceptSerializer for std::string
	template <>
	void WrapperTag<std::string>::acceptSerializer(const std::string& name, Serializer* engine)
	{
		engine->accept(name, data);
	}

	// Specialization of acceptSerializer for std::byte
	template <>
	void WrapperTag<std::byte>::acceptSerializer(const std::string& name, Serializer* engine)
	{
		engine->accept(name, data);
	}
}