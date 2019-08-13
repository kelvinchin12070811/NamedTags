#pragma once
#include <memory>
#include "TagBase.hpp"

namespace named_tags
{
	/**
	 * @addtogroup
	 * @{
	 */
	/**
	 * @brief Observe a foregin tag without taking it's ownership.
	 */
	class ObserverTag : public TagBase
	{ /** @} */
	public:
		~ObserverTag() = default;
		/**
		 * Create new ObeserverTag.
		 * @param tag Tag to reference, nullptr to not observe.
		 */
		static std::unique_ptr<ObserverTag> create(TagBase* tag = nullptr);
		/** Set tag to reference. */
		void set(TagBase* tag);
		/** Get reference tag. */
		TagBase* get();
		/** Get constant reference tag. */
		const TagBase* get() const;

		void acceptSerializer(const std::string& name, Serializer* engine) override;
		std::type_index tagType() override;
	private:
		ObserverTag(TagBase* tag);
		TagBase* tag{ nullptr };
	};
}