//***********************************************************************************************************
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0.If a copy of the MPL was not distributed with this
// file, You can obtain one at http ://mozilla.org/MPL/2.0/.
//***********************************************************************************************************
#include "json.hpp"
#include "JsonSerializer.hpp"
#include "JsonSerializerPrivate.hpp"

namespace named_tags
{
	JsonSerializer::JsonSerializer()
	{
		_data = new JsonSerializerPrivate;
	}

	JsonSerializer::~JsonSerializer()
	{
		delete _data;
	}

	std::string JsonSerializer::getJsonStr(bool pretty)
	{
		return _data->root.dump(pretty ? 4 : -1);
	}

	void JsonSerializer::treeStart(const std::string& name)
	{
		nlohmann::json tree;
		_data->trace.push({ name, std::move(tree) });
	}

	void JsonSerializer::treeEnd(const std::string& name)
	{
		assert(!_data->trace.empty());
		auto tree = _data->trace.top();
		_data->trace.pop();
		_data->append(tree.first, tree.second);
	}
	
	void JsonSerializer::arrayStart(const std::string& name, size_t length)
	{
		nlohmann::json value = "[]"_json;
		_data->trace.push({ name, std::move(value) });
	}
	
	void JsonSerializer::arrayEnd(const std::string& name)
	{
		assert(!_data->trace.empty());
		auto value = _data->trace.top();
		_data->trace.pop();
		_data->append(value.first, value.second);
	}

	Serializer::Type JsonSerializer::serializerType() const
	{
		return Serializer::Type::serial;
	}
	
	void JsonSerializer::accept(const std::string& name, bool& value)
	{
		_data->append(name, value);
	}
	
	void JsonSerializer::accept(const std::string& name, char& value)
	{
		_data->append(name, value);
	}
	
	void JsonSerializer::accept(const std::string& name, float& value)
	{
		_data->append(name, value);
	}
	
	void JsonSerializer::accept(const std::string& name, double& value)
	{
		_data->append(name, value);
	}
	
	void JsonSerializer::accept(const std::string& name, std::string& value)
	{
		_data->append(name, value);
	}
	
	void JsonSerializer::accept(const std::string& name, uint8_t& value)
	{
		_data->append(name, value);
	}
	
	void JsonSerializer::accept(const std::string& name, int8_t& value)
	{
		_data->append(name, value);
	}
	
	void JsonSerializer::accept(const std::string& name, uint16_t& value)
	{
		_data->append(name, value);
	}
	
	void JsonSerializer::accept(const std::string& name, int16_t& value)
	{
		_data->append(name, value);
	}
	
	void JsonSerializer::accept(const std::string& name, uint32_t& value)
	{
		_data->append(name, value);
	}
	
	void JsonSerializer::accept(const std::string& name, int32_t& value)
	{
		_data->append(name, value);
	}
	
	void JsonSerializer::accept(const std::string& name, uint64_t& value)
	{
		_data->append(name, value);
	}
	
	void JsonSerializer::accept(const std::string& name, int64_t& value)
	{
		_data->append(name, value);
	}
	
	void JsonSerializer::accept(const std::string& name, std::byte& value)
	{
		_data->append(name, std::to_integer<int>(value));
	}
}