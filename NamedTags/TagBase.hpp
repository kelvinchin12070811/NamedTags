#pragma once
#include <cassert>
#include <type_traits>
#include "Serializer.hpp"

namespace named_tags
{
	/**
	 * @addtogroup tags
	 * @{
	 */
	/**
	 * @brief The foundation type of all tags
	 */
	class TagBase
	{ /** @} */
	public:
		virtual ~TagBase() = 0;
		/**
		 * Accept a serializer for serialize or deserialize.
		 * @param name Name of current tag.
		 * @param engine Serializer engine to use.
		 */
		virtual void acceptSerializer(const std::string& name, Serializer* engine) = 0;

		/** Convert TagBase to targeted tag. */
		template <typename T>
		typename std::enable_if<!std::is_same<T, TagBase>::value, T*>::type as()
		{
			auto ptr = dynamic_cast<T*>(this);
			assert((ptr == nullptr ? 0 : 1));
			return ptr;
		}
	};
	inline TagBase::~TagBase() = default;
}