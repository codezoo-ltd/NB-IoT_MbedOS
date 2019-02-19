/*
 * Copyright (c) 2018, Arm Limited and affiliates.
 * SPDX-License-Identifier: Apache-2.0
 *
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
#include "SERCOMM_TPB23_CellularContext.h"
#include "SERCOMM_TPB23_CellularStack.h"

namespace mbed {

SERCOMM_TPB23_CellularContext::SERCOMM_TPB23_CellularContext(ATHandler &at, CellularDevice *device, const char *apn) :
    AT_CellularContext(at, device, apn)
{
}

SERCOMM_TPB23_CellularContext::~SERCOMM_TPB23_CellularContext()
{
}

#if !NSAPI_PPP_AVAILABLE
NetworkStack *SERCOMM_TPB23_CellularContext::get_stack()
{
    if (!_stack) {
        _stack = new SERCOMM_TPB23_CellularStack(_at, _cid, _ip_stack_type);
    }
    return _stack;
}
#endif // #if !NSAPI_PPP_AVAILABLE

bool SERCOMM_TPB23_CellularContext::stack_type_supported(nsapi_ip_stack_t stack_type)
{
    return stack_type == IPV4_STACK ? true : false;
}

} /* namespace mbed */
