//
// Created by sancar koyunlu on 6/25/13.
// Copyright (c) 2013 hazelcast. All rights reserved.



#ifndef HAZELCAST_CountDownRequest
#define HAZELCAST_CountDownRequest

#include "../serialization/SerializationConstants.h"
#include "CountDownLatchPortableHook.h"
#include "PortableWriter.h"
#include "PortableReader.h"
#include "Portable.h"
#include <string>

namespace hazelcast {
    namespace client {
        namespace countdownlatch {
            class CountDownRequest : public Portable {
            public:
                CountDownRequest(const std::string& instanceName);

                int getFactoryId() const;

                int getClassId() const;

                void writePortable(serialization::PortableWriter& writer) const;

                void readPortable(serialization::PortableReader& reader);

            private:

                std::string instanceName;
            };
        }
    }
}
#endif //HAZELCAST_CountDownRequest
