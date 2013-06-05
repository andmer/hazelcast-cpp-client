//
// Created by sancar koyunlu on 5/31/13.
// Copyright (c) 2013 hazelcast. All rights reserved.


#ifndef HAZELCAST_LOAD_BALANCER
#define HAZELCAST_LOAD_BALANCER

namespace hazelcast {
    namespace client {
        namespace connection {
            class Member;
        }
        class Cluster;

        class LoadBalancer {
        public:

            virtual void init(Cluster &cluster) = 0;

            virtual const connection::Member& next() = 0;

            virtual ~LoadBalancer() {

            };
        };

    }
}

#endif //HAZELCAST_LOAD_BALANCER