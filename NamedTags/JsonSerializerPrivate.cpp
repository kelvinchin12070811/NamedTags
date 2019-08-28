//***********************************************************************************************************
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0.If a copy of the MPL was not distributed with this
// file, You can obtain one at http ://mozilla.org/MPL/2.0/.
//***********************************************************************************************************
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