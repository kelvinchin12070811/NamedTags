//***********************************************************************************************************
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0.If a copy of the MPL was not distributed with this
// file, You can obtain one at http ://mozilla.org/MPL/2.0/.
//***********************************************************************************************************
#pragma once
#include <stack>
#include <string>
#include "json.hpp"

namespace named_tags
{
	struct JsonDeserializerPrivate
	{
		nlohmann::json root;
		std::stack<nlohmann::json*> trace;
		nlohmann::json* getCurValue();
		nlohmann::json* getDataFromCurValue(const std::string& name);
	};
}