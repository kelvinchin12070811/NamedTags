#include <iostream>
#include <ArrayTag.hpp>
#include <CommonTags.hpp>
#include <CompoundTag.hpp>

using namespace std;

int main(int argc, char** argv)
{
	try
	{
		auto ctag = named_tags::CompoundTag::create({
			{ "test", named_tags::StringTag::create("Hello my friend") },
			{ "test2", named_tags::FloatTag::create(3.142f) }
		});
		auto tag = ctag->insert("int", named_tags::IntTag::create(12));
		auto tag2 = ctag->insert("str", named_tags::StringTag::create("Hello World"));

		auto arrayTag = named_tags::ArrayTag<int>::create({ 12, 32, 45, 87 });

		cout << tag->as<named_tags::IntTag>() << endl;


		cout << arrayTag->size() << endl;

		cout << ctag->get("test")->as<named_tags::StringTag>() << endl;

		for (auto&& itr : arrayTag->each())
		{
			cout << itr << endl;
		}

		auto testin = named_tags::IntTag::create();
		cin >> testin;
		cout << testin << endl;
	}
	catch (std::exception & e)
	{
		cerr << e.what() << endl;
	}
	return 0;
}