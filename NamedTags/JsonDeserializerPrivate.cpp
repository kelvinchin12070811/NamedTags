//***********************************************************************************************************
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0.If a copy of the MPL was not distributed with this
// file, You can obtain one at http ://mozilla.org/MPL/2.0/.
//***********************************************************************************************************
#include "JsonDeserializerPrivate.hpp"

namespace named_tags
{
	nlohmann::json* JsonDeserializerPrivate::getCurValue()
	{
		return trace.empty() ? &root : trace.top();
	}

	nlohmann::json* JsonDeserializerPrivate::getDataFromCurValue(const std::string& name)
	{
		auto cur = getCurValue();
		return cur->is_array() ? &(*cur)[std::stol(name)] : &(*cur)[name];
	}
}