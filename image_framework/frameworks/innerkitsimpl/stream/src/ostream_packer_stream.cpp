/*
 * Copyright (C) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "ostream_packer_stream.h"

namespace OHOS {
namespace Media {
using namespace OHOS::HiviewDFX;

OstreamPackerStream::OstreamPackerStream(std::ostream &outputStream) : outputStream_(&outputStream) {}

bool OstreamPackerStream::Write(const uint8_t *buffer, uint32_t size)
{
    if ((buffer == nullptr) || (size == 0)) {
        HiLog::Error(LABEL, "input parameter invalid.");
        return false;
    }
    outputStream_->write(reinterpret_cast<const char *>(buffer), size);
    return true;
}

void OstreamPackerStream::Flush()
{
    if (outputStream_ != nullptr) {
        outputStream_->flush();
    }
}

int64_t OstreamPackerStream::BytesWritten()
{
    return (outputStream_ != nullptr) ? static_cast<int64_t>(outputStream_->tellp()) : 0;
}
} // namespace Media
} // namespace OHOS
