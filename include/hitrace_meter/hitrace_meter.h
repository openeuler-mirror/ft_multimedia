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

#ifndef INTERFACES_INNERKITS_NATIVE_HITRACE_METER_H
#define INTERFACES_INNERKITS_NATIVE_HITRACE_METER_H

#include <string>

#ifdef __cplusplus
extern "C" {
#endif

void StartTrace(uint64_t label, const std::string& value, float limit = -1) {};

void FinishTrace(uint64_t label) {};

#ifdef __cplusplus
}
#endif
#endif // INTERFACES_INNERKITS_NATIVE_HITRACE_METER_H
