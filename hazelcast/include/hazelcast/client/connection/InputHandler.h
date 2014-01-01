//
// Created by sancar koyunlu on 24/12/13.
//


#ifndef HAZELCAST_ReadHandler
#define HAZELCAST_ReadHandler

#include "hazelcast/util/ByteBuffer.h"
#include "hazelcast/client/connection/IOHandler.h"

namespace hazelcast {
    namespace client {
        namespace serialization {
            class DataAdapter;
        }
        namespace spi {
            class ClusterService;
        }
        namespace connection {
            class Connection;

            class ConnectionManager;

            class IListener;

            class HAZELCAST_API InputHandler : public IOHandler{
            public:
                InputHandler(Connection &connection, IListener& ioListener, spi::ClusterService &clusterService, int bufferSize);

                void handle();

                void run();

            private:
                util::ByteBuffer buffer;
                spi::ClusterService &clusterService;
                serialization::DataAdapter *lastData;


            };
        }
    }
}

#endif //HAZELCAST_ReadHandler