//
// Created by sancar koyunlu on 6/11/13.
// Copyright (c) 2013 hazelcast. All rights reserved.


#ifndef HAZELCAST_MAP_SIZE_REQUEST
#define HAZELCAST_MAP_SIZE_REQUEST

#include "PortableHook.h"
#include "../serialization/SerializationConstants.h"
#include <string>

namespace hazelcast {
    namespace client {
        namespace map {
            class SizeRequest : public Portable{
            public:
                SizeRequest(const std::string& name)
                :name(name) {

                };

                int getFactoryId() const {
                    return PortableHook::F_ID;
                }

                int getClassId() const {
                    return PortableHook::SIZE;
                }


                inline void writePortable(serialization::PortableWriter& writer) const {
                    writer.writeUTF("n", name);
                };


                inline void readPortable(serialization::PortableReader& reader) {
                    name = reader.readUTF("n");
                };
            private:
                std::string name;
            };
        }
    }
}


#endif //MAP_CLEAR_REQUEST
