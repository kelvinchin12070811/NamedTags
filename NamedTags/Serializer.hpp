//***********************************************************************************************************
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0.If a copy of the MPL was not distributed with this
// file, You can obtain one at http ://mozilla.org/MPL/2.0/.
//***********************************************************************************************************
#pragma once
#include <string>

namespace named_tags
{
	/**
	 * @addtogroup tags
	 * @{
	 */
	/**
	 * @brief Static serializer base class.
	 * A bidirectional serializer base class for all serializer and deserializer.
	 */
	class Serializer
	{ /** @} */
	public:
		Serializer() = default;
		Serializer(const Serializer&) = default;
		Serializer(Serializer&&) noexcept = default;
		Serializer& operator=(const Serializer&) = default;
		Serializer& operator=(Serializer&&) noexcept = default;
		virtual ~Serializer() = 0;

		/** Called when start to parse a tree. */
		virtual void treeStart(const std::string& name) = 0;
		/** Called when end to parse a tree. */
		virtual void treeEnd(const std::string& name) = 0;
		/** Called when start to parse an array. */
		virtual void arrayStart(const std::string& name) = 0; 
		/** Called when end to parse an array. */
		virtual void arrayEnd(const std::string& name) = 0;

		/**
		 * @name Data reader/writer
		 * @{
		 */
		virtual void accept(const std::string& name, bool& value) = 0;
		virtual void accept(const std::string& name, char& value) = 0;
		virtual void accept(const std::string& name, float& value) = 0;
		virtual void accept(const std::string& name, double& value) = 0;
		virtual void accept(const std::string& name, std::string& value) = 0;
		virtual void accept(const std::string& name, uint8_t& value) = 0;
		virtual void accept(const std::string& name, int8_t& value) = 0;
		virtual void accept(const std::string& name, uint16_t& value) = 0;
		virtual void accept(const std::string& name, int16_t& value) = 0;
		virtual void accept(const std::string& name, uint32_t& value) = 0;
		virtual void accept(const std::string& name, int32_t& value) = 0;
		virtual void accept(const std::string& name, uint64_t& value) = 0;
		virtual void accept(const std::string& name, int64_t& value) = 0;
		virtual void accept(const std::string& name, std::byte& value) = 0;
		/** @} */
	};
	inline Serializer::~Serializer() = default;
}