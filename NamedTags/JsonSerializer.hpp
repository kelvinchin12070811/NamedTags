//***********************************************************************************************************
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0.If a copy of the MPL was not distributed with this
// file, You can obtain one at http ://mozilla.org/MPL/2.0/.
//***********************************************************************************************************
#pragma once
#include "Serializer.hpp"

namespace named_tags
{
	class JsonSerializerPrivate;
	/**
	 * @addtogroup tags
	 * @{
	 */
	/**
	 * @brief Serialize to json data.
	 */
	class JsonSerializer : public Serializer
	{ /** @} */
	public:
		JsonSerializer();
		JsonSerializer(const JsonSerializer&) = default;
		JsonSerializer(JsonSerializer&&) noexcept = default;
		JsonSerializer& operator=(const JsonSerializer&) = default;
		JsonSerializer& operator=(JsonSerializer&&) noexcept = default;
		~JsonSerializer();

		/**
		 * Get generated JSON string.
		 * @param pretty determin if the paser generate the formated string or minified string. Default is
		 * true
		 */
		std::string getJsonStr(bool pretty = true);

		void treeStart(const std::string& name) override;
		void treeEnd(const std::string& name) override;
		void arrayStart(const std::string& name) override;
		void arrayEnd(const std::string& name) override;

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
		JsonSerializerPrivate* _data{ nullptr };
	};
}