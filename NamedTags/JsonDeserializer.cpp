//***********************************************************************************************************
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0.If a copy of the MPL was not distributed with this
// file, You can obtain one at http ://mozilla.org/MPL/2.0/.
//***********************************************************************************************************
#include "JsonDeserializer.hpp"
#include "JsonDeserializerPrivate.hpp"

namespace named_tags
{
	JsonDeserializer::JsonDeserializer(std::string jsonStr)
	{
		if (!_data) _data = new JsonDeserializerPrivate;
		_data->root = nlohmann::json::parse(jsonStr);
	}

	JsonDeserializer::~JsonDeserializer()
	{
		if (_data) delete _data;
	}

	void JsonDeserializer::treeStart(const std::string& name)
	{
		nlohmann::json* cur{ _data->getCurValue() };
		if (!cur->contains(name))
			throw std::runtime_error{ name + " does not found in current data tree" };
		auto tree = &(*cur)[name];
		_data->trace.push(tree);
	}

	void JsonDeserializer::treeEnd(const std::string& name)
	{
		_data->trace.pop();
	}

	void JsonDeserializer::arrayStart(const std::string& name, size_t length)
	{
		auto cur = _data->getCurValue();
		if (!cur->contains(name))
			throw std::runtime_error{ name + " does not found in current data tree" };
		auto arr = &(*cur)[name];
		if (!arr->is_array()) throw std::runtime_error{ name + " is not a valid array type" };
		_data->trace.push(arr);
		curArraySz = arr->size();
	}

	void JsonDeserializer::arrayEnd(const std::string& name)
	{
		_data->trace.pop();
	}

	size_t JsonDeserializer::arraySize()
	{
		return curArraySz;
	}
	
	Serializer::Type JsonDeserializer::serializerType() const
	{
		return Serializer::Type::deserial;
	}
	
	void JsonDeserializer::accept(const std::string& name, bool& value)
	{
		auto rtn = _data->getDataFromCurValue(name);
		if (!rtn->is_boolean())
			throw genMessage(name, "boolean");
		value = rtn->get<bool>();
	}
	
	void JsonDeserializer::accept(const std::string& name, char& value)
	{
		std::string str;
		accept(name, str);
		if (str.length() > 1)
			throw genMessage(name, "char");
		else if (str.empty())
			value = '\0';
		else
			value = str[0];
	}
	
	void JsonDeserializer::accept(const std::string& name, float& value)
	{
		auto rtn = _data->getDataFromCurValue(name);
		if (!rtn->is_number_float())
			throw genMessage(name, "float");
		value = rtn->get<float>();
	}
	
	void JsonDeserializer::accept(const std::string& name, double& value)
	{
		auto rtn = _data->getDataFromCurValue(name);
		if (!rtn->is_number_float())
			throw genMessage(name, "double");
		value = rtn->get<double>();
	}
	
	void JsonDeserializer::accept(const std::string& name, std::string& value)
	{
		auto rtn = _data->getDataFromCurValue(name);
		if (!rtn->is_string())
			throw genMessage(name, "string");
		value = rtn->get<std::string>();
	}
	
	void JsonDeserializer::accept(const std::string& name, uint8_t& value)
	{
		auto rtn = _data->getDataFromCurValue(name);
		if (!rtn->is_number_unsigned())
			throw genMessage(name, "unsigned interger");
		value = rtn->get<uint8_t>();
	}
	
	void JsonDeserializer::accept(const std::string& name, int8_t& value)
	{
		auto rtn = _data->getDataFromCurValue(name);
		if (!rtn->is_number_integer())
			throw genMessage(name, "interger");
		value = rtn->get<int8_t>();
	}
	
	void JsonDeserializer::accept(const std::string& name, uint16_t& value)
	{
		auto rtn = _data->getDataFromCurValue(name);
		if (!rtn->is_number_unsigned())
			throw genMessage(name, "unsigned interger");
		value = rtn->get<uint16_t>();
	}
	
	void JsonDeserializer::accept(const std::string& name, int16_t& value)
	{
		auto rtn = _data->getDataFromCurValue(name);
		if (!rtn->is_number_integer())
			throw genMessage(name, "interger");
		value = rtn->get<int16_t>();
	}
	
	void JsonDeserializer::accept(const std::string& name, uint32_t& value)
	{
		auto rtn = _data->getDataFromCurValue(name);
		if (!rtn->is_number_unsigned())
			throw genMessage(name, "unsigned interger");
		value = rtn->get<uint32_t>();
	}
	
	void JsonDeserializer::accept(const std::string& name, int32_t& value)
	{
		auto rtn = _data->getDataFromCurValue(name);
		if (!rtn->is_number_integer())
			throw genMessage(name, "interger");
		value = rtn->get<int32_t>();
	}
	
	void JsonDeserializer::accept(const std::string& name, uint64_t& value)
	{
		auto rtn = _data->getDataFromCurValue(name);
		if (!rtn->is_number_unsigned())
			throw genMessage(name, "unsigned interger");
		value = rtn->get<uint64_t>();
	}
	
	void JsonDeserializer::accept(const std::string& name, int64_t& value)
	{
		auto rtn = _data->getDataFromCurValue(name);
		if (!rtn->is_number_integer())
			throw genMessage(name, "interger");
		value = rtn->get<int64_t>();
	}
	
	void JsonDeserializer::accept(const std::string& name, std::byte& value)
	{
		auto rtn = _data->getDataFromCurValue(name);
		if (!rtn->is_number_unsigned())
			throw genMessage(name, "interger");
		value = static_cast<std::byte>(rtn->get<unsigned int>());
	}
	
	std::runtime_error JsonDeserializer::genMessage(const std::string& name, const std::string& type)
	{
		return std::runtime_error{ name + " is not a valid " + type + " value." };
	}
}