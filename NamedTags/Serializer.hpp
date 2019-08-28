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
		/** Determine the type of the common serializer engine. */
		enum class Type {
			serial, /**< Serializer engine. */
			deserial /**< Deserializer engine. */
		};

		Serializer() = default;
		Serializer(const Serializer&) = default;
		Serializer(Serializer&&) noexcept = default;
		Serializer& operator=(const Serializer&) = default;
		Serializer& operator=(Serializer&&) noexcept = default;
		virtual ~Serializer() = 0;

		/**
		 * Called when start to parse a tree.
		 * @param name Name of the tag.
		 */
		virtual void treeStart(const std::string& name) = 0;
		/**
		 * Called when end to parse a tree.
		 * @param name Name of the tag.
		 */
		virtual void treeEnd(const std::string& name) = 0;
		/**
		 * Called when start to parse an array.
		 * @param name Name of the tag.
		 * @param length Length of the array to serailize, ignore when deserialize.
		 */
		virtual void arrayStart(const std::string& name, size_t length) = 0; 
		/**
		 * Called when end to parse an array.
		 * @param name Name of the tag.
		 */
		virtual void arrayEnd(const std::string& name) = 0;
		/**
		 * Get the size of array. Return maximum of size_t if size is unknow.
		 */
		virtual inline size_t arraySize()
		{
			return std::numeric_limits<size_t>::max();
		}
		/** Get current type of serializer. */
		virtual Serializer::Type serializerType() const = 0;

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