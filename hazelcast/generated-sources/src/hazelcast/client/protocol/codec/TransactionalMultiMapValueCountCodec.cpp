/*
 * Copyright (c) 2008-2018, Hazelcast, Inc. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "hazelcast/util/Util.h"
#include "hazelcast/util/ILogger.h"

#include "hazelcast/client/protocol/codec/TransactionalMultiMapValueCountCodec.h"
#include "hazelcast/client/serialization/pimpl/Data.h"

namespace hazelcast {
    namespace client {
        namespace protocol {
            namespace codec {
                const TransactionalMultiMapMessageType TransactionalMultiMapValueCountCodec::REQUEST_TYPE = HZ_TRANSACTIONALMULTIMAP_VALUECOUNT;
                const bool TransactionalMultiMapValueCountCodec::RETRYABLE = false;
                const ResponseMessageConst TransactionalMultiMapValueCountCodec::RESPONSE_TYPE = (ResponseMessageConst) 102;

                std::auto_ptr<ClientMessage> TransactionalMultiMapValueCountCodec::encodeRequest(
                        const std::string &name,
                        const std::string &txnId,
                        int64_t threadId,
                        const serialization::pimpl::Data &key) {
                    int32_t requiredDataSize = calculateDataSize(name, txnId, threadId, key);
                    std::auto_ptr<ClientMessage> clientMessage = ClientMessage::createForEncode(requiredDataSize);
                    clientMessage->setMessageType((uint16_t) TransactionalMultiMapValueCountCodec::REQUEST_TYPE);
                    clientMessage->setRetryable(RETRYABLE);
                    clientMessage->set(name);
                    clientMessage->set(txnId);
                    clientMessage->set(threadId);
                    clientMessage->set(key);
                    clientMessage->updateFrameLength();
                    return clientMessage;
                }

                int32_t TransactionalMultiMapValueCountCodec::calculateDataSize(
                        const std::string &name,
                        const std::string &txnId,
                        int64_t threadId,
                        const serialization::pimpl::Data &key) {
                    int32_t dataSize = ClientMessage::HEADER_SIZE;
                    dataSize += ClientMessage::calculateDataSize(name);
                    dataSize += ClientMessage::calculateDataSize(txnId);
                    dataSize += ClientMessage::calculateDataSize(threadId);
                    dataSize += ClientMessage::calculateDataSize(key);
                    return dataSize;
                }

                TransactionalMultiMapValueCountCodec::ResponseParameters::ResponseParameters(
                        ClientMessage &clientMessage) {


                    response = clientMessage.get<int32_t>();

                }

                TransactionalMultiMapValueCountCodec::ResponseParameters
                TransactionalMultiMapValueCountCodec::ResponseParameters::decode(ClientMessage &clientMessage) {
                    return TransactionalMultiMapValueCountCodec::ResponseParameters(clientMessage);
                }


            }
        }
    }
}

