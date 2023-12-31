/*
 * Copyright (C) 2022 Huawei Device Co., Ltd.
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
#ifndef RAW_STREAM_H
#define RAW_STREAM_H
#include "src/piex.h"
#include "src/piex_types.h"
#include "input_data_stream.h"
namespace OHOS {
namespace ImagePlugin {
class RawStream : public piex::StreamInterface {
public:
    explicit RawStream(InputDataStream &sourceStream);
    ~RawStream();

public:
    // api for piex::StreamInterface
    piex::Error GetData(const size_t offset, const size_t length, uint8_t* data) override;

private:
    InputDataStream *inputStream_ {nullptr};
};
} // namespace ImagePlugin
} // namespace OHOS
#endif // RAW_STREAM_H
