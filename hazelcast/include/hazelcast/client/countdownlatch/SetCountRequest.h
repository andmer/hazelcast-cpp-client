//
// Created by sancar koyunlu on 6/25/13.
// Copyright (c) 2013 hazelcast. All rights reserved.



#ifndef HAZELCAST_SetCountRequest
#define HAZELCAST_SetCountRequest

#include "../serialization/SerializationConstants.h"
#include "CountDownLatchPortableHook.h"
#include "PortableWriter.h"
#include "PortableReader.h"
#include <string>

namespace hazelcast {
    namespace client {
        namespace countdownlatch {
            class SetCountRequest {
            public:
                SetCountRequest(const std::string& instanceName, long count)
                : instanceName(instanceName)
                , count(count) {

                };

                int getFactoryId() const {
                    return CountDownLatchPortableHook::F_ID;
                };

                int getSerializerId() const {
                    return serialization::SerializationConstants::CONSTANT_TYPE_PORTABLE;
                };

                int getClassId() const {
                    return CountDownLatchPortableHook::SET_COUNT;
                };


                void writePortable(serialization::PortableWriter& writer) const {
                    writer.writeUTF("name", instanceName);
                    writer.writeLong("count", count);
                };


                void readPortable(serialization::PortableReader& reader) {
                    instanceName = reader.readUTF("name");
                    count = reader.readLong("count");
                };
            private:

                std::string instanceName;
                long count;
            };
        }
    }
}

#endif //HAZELCAST_SetCountRequest
