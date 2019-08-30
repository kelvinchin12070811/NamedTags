//***********************************************************************************************************
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0.If a copy of the MPL was not distributed with this
// file, You can obtain one at http ://mozilla.org/MPL/2.0/.
//***********************************************************************************************************
#pragma once
#include <stdexcept>
#include "Serializer.hpp"

namespace named_tags
{
	struct JsonDeserializerPrivate;
	/**
	* @addtogroup tags
	* @{
	*/
	/**
	* @brief Statically deserialize NBT data from json data.
	*/
	class JsonDeserializer : public Serializer
	{ /** @} */
	public:
		JsonDeserializer(std::string jsonStr);
		JsonDeserializer(const JsonDeserializer&) = default;
		JsonDeserializer(JsonDeserializer&&) noexcept = default;
		JsonDeserializer& operator=(const JsonDeserializer&) = default;
		JsonDeserializer& operator=(JsonDeserializer&&) noexcept = default;
		~JsonDeserializer();

		void treeStart(const std::string& name) override;
		void treeEnd(const std::string& name) override;
		void arrayStart(const std::string& name, size_t length) override;
		void arrayEnd(const std::string& name) override;
		size_t arraySize() override;

		Serializer::Type serializerType() const override;

		void accept(const std::string& name, bool& value);
		void accept(const std::string& name, char& value);
		void accept(const std::string& name, float& value);
		void accept(const std::string& name, double& value);
		void accept(const std::string& name, std::string& value);
		void accept(const std::string& name, uint8_t& value);
		void accept(const std::string& name, int8_t& value);
		void accept(const std::string& name, uint16_t& value);
		void accept(const std::string& name, int16_t& value);
		void accept(const std::string& name, uint32_t& value);
		void accept(const std::string& name, int32_t& value);
		void accept(const std::string& name, uint64_t& value);
		void accept(const std::string& name, int64_t& value);
		void accept(const std::string& name, std::byte& value);
	private:
		std::runtime_error genMessage(const std::string& name, const std::string& type);
	private:
		JsonDeserializerPrivate* _data{ nullptr };
		size_t curArraySz{ 0 };
	};
}