//
// Created by sancar koyunlu on 6/25/13.
// Copyright (c) 2013 hazelcast. All rights reserved.



#ifndef HAZELCAST_ContainsEntryRequest
#define HAZELCAST_ContainsEntryRequest

#include "CollectionProxyId.h"
#include "CollectionRequest.h"
#include "../serialization/Data.h"

namespace hazelcast {
    namespace client {
        namespace collection {
            class ContainsEntryRequest : public CollectionRequest {
            public:
                ContainsEntryRequest(const CollectionProxyId& id, const serialization::Data& key, const serialization::Data& value)
                : CollectionRequest(id)
                , hasKey(true)
                , key(key)
                , value(value) {

                };

                ContainsEntryRequest(const CollectionProxyId& id, const serialization::Data& value)
                : CollectionRequest(id)
                , hasKey(false)
                , value(value) {

                };

                int getClassId() const {
                    return CollectionPortableHook::CONTAINS_ENTRY;
                };


                void writePortable(serialization::PortableWriter& writer) const {
                    serialization::ObjectDataOutput& out = writer.getRawDataOutput();
                    out.writeBoolean(hasKey);
                    if (hasKey) {
                        key.writeData(out);

                    }
                    out.writeBoolean(true);
                    value.writeData(out);
                    CollectionRequest::writePortable(writer);
                };


                void readPortable(serialization::PortableReader& reader) {
                    serialization::ObjectDataInput &in = reader.getRawDataInput();
                    hasKey = in.readBoolean();
                    if (hasKey)
                        key.readData(in);
                    bool isNotNull = in.readBoolean();
                    if (isNotNull)
                        value.readData(in);
                    CollectionRequest::readPortable(reader);
                };

            private:
                bool hasKey;
                serialization::Data key;
                serialization::Data value;
            };
        }
    }
}

#endif //HAZELCAST_ContainsEntryRequest
