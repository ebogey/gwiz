#ifndef GWIZ_IREFERENCE_H
#define GWIZ_IREFERENCE_H

#include <stdint.h>
#include <memory>

#include "core/region/Region.h"
#include "core/utils/NonCopyable.h"
#include "core/utils/Types.h"

namespace gwiz
{

	class IReference : private noncopyable
	{
	public:
		typedef std::shared_ptr<IReference> SharedPtr;

	    IReference(){}
		/* IReference(Region::SharedPtr region) : m_region(region) {} */
		virtual ~IReference() {}

		virtual const char* getSequence() = 0;
		virtual size_t getSequenceSize() = 0;

		Region::SharedPtr getRegion() { return this->m_region; }

	protected:
		Region::SharedPtr m_region;

	private:
		IReference(const IReference&) = delete;
		IReference& operator=(const IReference&) = delete;
	};
}

#endif // GWIZ_IREFERENCE_H
