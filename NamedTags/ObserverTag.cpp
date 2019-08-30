//***********************************************************************************************************
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0.If a copy of the MPL was not distributed with this
// file, You can obtain one at http ://mozilla.org/MPL/2.0/.
//***********************************************************************************************************
#include "ObserverTag.hpp"

namespace named_tags
{
	std::unique_ptr<ObserverTag> ObserverTag::create(TagBase* tag)
	{
		return std::unique_ptr<ObserverTag>(new ObserverTag(tag));
	}

	void ObserverTag::set(TagBase* tag)
	{
		tag = tag;
	}

	TagBase* ObserverTag::get()
	{
		return const_cast<TagBase*>(const_cast<const ObserverTag*>(this)->get());
	}

	const TagBase* ObserverTag::get() const
	{
		return tag;
	}

	bool ObserverTag::isObserving() const
	{
		return tag != nullptr;
	}

	void ObserverTag::acceptSerializer(const std::string& name, Serializer* engine)
	{
		tag->acceptSerializer(name, engine);
	}

	std::type_index ObserverTag::tagType()
	{
		return typeid(ObserverTag);
	}
	
	ObserverTag::ObserverTag(TagBase* tag):
		tag(tag)
	{
	}
}