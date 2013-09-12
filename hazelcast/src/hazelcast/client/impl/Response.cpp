//
// Created by sancar koyunlu on 9/12/13.
// Copyright (c) 2013 hazelcast. All rights reserved.


#include "Response.h"
#include "PortableWriter.h"


namespace hazelcast {
    namespace client {
        namespace impl {
            Response::~Response() {

            }

            void Response::writePortable(serialization::PortableWriter& writer) const {
                throw exception::IOException("void Response::writePortable(serialization::PortableWriter& writer)", "write of Client response is not implemented ");
            }
        }
    }
}