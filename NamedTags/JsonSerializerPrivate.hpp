//***********************************************************************************************************
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0.If a copy of the MPL was not distributed with this
// file, You can obtain one at http ://mozilla.org/MPL/2.0/.
//***********************************************************************************************************
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