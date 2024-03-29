#include <iostream>
#include <ArrayTag.hpp>
#include <CommonTags.hpp>
#include <CompoundTag.hpp>
#include <JsonSerializer.hpp>
#include <JsonDeserializer.hpp>

using namespace std;

int main(int argc, char** argv)
{
	try
	{
		auto ctag = named_tags::CompoundTag::create();
		const named_tags::TagBase* tag = ctag->insert("int", named_tags::IntTag::create(12));
		auto tag2 = ctag->insert("str", named_tags::StringTag::create("Hello World"));
		ctag->insert("test", named_tags::StringTag::create("test from tag"));

		auto arrayTag = ctag->insert("array", named_tags::ArrayTag<int>::create({ 12, 32, 45, 87 }))
			->staticAs<named_tags::ArrayTag<int>>();

		cout << tag->as<named_tags::IntTag>() << endl;

		cout << arrayTag->size() << endl;

		cout << ctag->get("test")->staticAs<named_tags::StringTag>() << endl;
		cout << (ctag->get("test")->tagType() == typeid(named_tags::IntTag)) << endl;
		for (auto&& itr : arrayTag->each())
		{
			cout << itr << endl;
		}

		auto testin = named_tags::IntTag::create();
		cin >> testin;
		cout << testin << endl;

		cout << endl;
		named_tags::JsonSerializer engine;
		ctag->acceptSerializer("test", &engine);
		cout << engine.getJsonStr(false) << endl;

		std::string str = R"({ "test":{"array": [14,32,45,87,98] ,"int" : 32,"str" : "Hello JSON","test" : "test from tags"} })";
		named_tags::JsonDeserializer des{ str };

		ctag->acceptSerializer("test", &des);

		ctag->acceptSerializer("test", &engine);
		cout << engine.getJsonStr(false) << endl;
	}
	catch (std::exception & e)
	{
		cerr << e.what() << endl;
	}
	return 0;
}