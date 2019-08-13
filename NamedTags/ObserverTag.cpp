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

	void ObserverTag::acceptSerializer(const std::string& name, Serializer* engine)
	{
		tag->acceptSerializer(name, engine);
	}
	
	ObserverTag::ObserverTag(TagBase* tag):
		tag(tag)
	{
	}
}