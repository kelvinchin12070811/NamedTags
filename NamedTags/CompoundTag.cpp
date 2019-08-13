#include <stdexcept>
#include "CompoundTag.hpp"

namespace named_tags
{
	std::unique_ptr<CompoundTag> CompoundTag::create()
	{
		return std::unique_ptr<CompoundTag>(new CompoundTag());
	}

	std::unique_ptr<CompoundTag> CompoundTag::create(
		std::initializer_list<std::pair<std::string, std::unique_ptr<TagBase>>> tags)
	{
		auto ptr = create();
		for (auto&& itr : tags)
		{
			std::pair<std::string, std::unique_ptr<TagBase>>& target = const_cast<decltype(target)>(itr);
			ptr->tree.insert({ std::move(target.first), std::move(target.second) });
		}
		return ptr;
	}
	
	bool CompoundTag::has(const std::string& id) const
	{
		auto result = tree.find(id);
		return result != tree.end();
	}

	TagBase* CompoundTag::insert(std::string id, std::unique_ptr<TagBase> tag)
	{
		auto result = tree.insert({ std::move(id), std::move(tag) });
		return result.first->second.get();
	}
	
	bool CompoundTag::remove(const std::string& id)
	{
		return tree.erase(id) != 0;
	}
	
	TagBase* CompoundTag::get(const std::string& id)
	{
		return const_cast<TagBase*>(const_cast<const CompoundTag*>(this)->get(id));
	}
	
	const TagBase* CompoundTag::get(const std::string& id) const
	{
		try
		{
			return tree.at(id).get();
		}
		catch (std::out_of_range&)
		{
			throw std::logic_error{ "Id " + id + " does not contain in the tree." };
		}
	}

	void CompoundTag::clear()
	{
		tree.clear();
	}

	std::map<std::string, std::unique_ptr<TagBase>>& CompoundTag::each()
	{
		return const_cast<std::map<std::string, std::unique_ptr<TagBase>>&>(
			const_cast<const CompoundTag*>(this)->each());
	}

	const std::map<std::string, std::unique_ptr<TagBase>>& CompoundTag::each() const
	{
		return tree;
	}

	void CompoundTag::acceptSerializer(const std::string& name, Serializer* engine)
	{
		engine->treeStart(name);
		for (auto&& [id, tag] : tree)
			tag->acceptSerializer(id, engine);
		engine->treeEnd(name);
	}

	decltype(CompoundTag::tree)::iterator CompoundTag::begin()
	{
		return tree.begin();
	}

	decltype(CompoundTag::tree)::iterator CompoundTag::end()
	{
		return tree.end();
	}

	decltype(CompoundTag::tree)::const_iterator CompoundTag::begin() const
	{
		return tree.begin();
	}

	decltype(CompoundTag::tree)::const_iterator CompoundTag::end() const
	{
		return tree.end();
	}
}