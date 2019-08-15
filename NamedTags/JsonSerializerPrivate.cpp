#include "JsonSerializerPrivate.hpp"

namespace named_tags
{
	void JsonSerializerPrivate::append(const std::string& name, nlohmann::json value)
	{	
		nlohmann::json* pos{ nullptr };
		if (trace.empty()) pos = &root;
		else pos = &trace.top().second;

		if (pos->is_array())
		{
			pos->push_back(std::move(value));
		}
		else
		{
			(*pos)[name] = std::move(value);
		}
	}
}