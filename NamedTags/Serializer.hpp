#pragma once
#include <string>

namespace named_tags
{
	/**
	 * @addtogroup tags
	 * @{
	 */
	/**
	 * @brief Serializer base class.
	 */
	class Serializer
	{ /** @} */
	public:
		virtual ~Serializer() = 0;
		/** Called when start to parse a tree. */
		virtual void treeStart(std::string name) = 0;
		/** Called when end to parse a tree. */
		virtual void treeEnd(std::string name) = 0;
		/** Called when start to parse an array. */
		virtual void arrayStart(std::string name) = 0; 
		/** Called when end to parse an array. */
		virtual void arrayEnd(std::string name) = 0;

		/**
		 * @name Data reader/writer
		 * @{
		 */
		virtual void accept(std::string name, bool& value) = 0;
		virtual void accept(std::string name, char& value) = 0;
		virtual void accept(std::string name, float& value) = 0;
		virtual void accept(std::string name, double& value) = 0;
		virtual void accept(std::string name, std::string& value) = 0;
		virtual void accept(std::string name, uint8_t& value) = 0;
		virtual void accept(std::string name, int8_t& value) = 0;
		virtual void accept(std::string name, uint16_t& value) = 0;
		virtual void accept(std::string name, int16_t& value) = 0;
		virtual void accept(std::string name, uint32_t& value) = 0;
		virtual void accept(std::string name, int32_t& value) = 0;
		virtual void accept(std::string name, uint64_t& value) = 0;
		virtual void accept(std::string name, int64_t& value) = 0;
		virtual void accept(std::string name, std::byte& value) = 0;
		/** @} */
	};
	inline Serializer::~Serializer() = default;
}