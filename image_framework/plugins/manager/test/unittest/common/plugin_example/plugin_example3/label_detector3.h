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

#ifndef LABEL_DETECTOR3_H
#define LABEL_DETECTOR3_H

#include "abs_image_detector.h"
#include "plugin_class_base.h"

namespace OHOS {
namespace PluginExample {
class LabelDetector3 final : public AbsImageDetector, public OHOS::MultimediaPlugin::PluginClassBase {
public:
    LabelDetector3();
    ~LabelDetector3();

    bool Prepare() override;
    std::string Process() override;

private:
    static const std::string RESULT_STR;
};
} // namespace PluginExample
} // namespace OHOS

#endif // LABEL_DETECTOR3_H
