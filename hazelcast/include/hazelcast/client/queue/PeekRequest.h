//
// Created by sancar koyunlu on 5/23/13.
// Copyright (c) 2013 hazelcast. All rights reserved.
#ifndef HAZELCAST_QUEUE_PEEK_REQUEST
#define HAZELCAST_QUEUE_PEEK_REQUEST

#include "../serialization/SerializationConstants.h"
#include "QueuePortableHook.h"
#include <string>

namespace hazelcast {
    namespace client {
        namespace queue {
            class PeekRequest : public Portable, public RetryableRequest {
            public:
                PeekRequest(const std::string& name)
                :name(name) {

                };

                int getFactoryId() const {
                    return queue::QueuePortableHook::F_ID;
                }

                int getClassId() const {
                    return queue::QueuePortableHook::PEEK;
                };


                void writePortable(serialization::PortableWriter& writer) const {
                    writer.writeUTF("n", name);
                };


                void readPortable(serialization::PortableReader& reader) {
                    name = reader.readUTF("n");
                };
            private:
                std::string name;
            };
        }
    }
}

#endif //HAZELCAST_MAP_PUT_REQUEST