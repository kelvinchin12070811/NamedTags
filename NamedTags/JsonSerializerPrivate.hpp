#pragma once
#include <stack>
#include "json.hpp"

namespace named_tags
{
	struct JsonSerializerPrivate
	{
		nlohmann::json root;
		std::stack<std::pair<std::string, nlohmann::json>> trace;
		void append(const std::string& name, nlohmann::json value);
	};
}