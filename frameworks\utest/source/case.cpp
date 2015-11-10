/****************************************************************************
 * Copyright (c) 2015, ARM Limited, All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ****************************************************************************
 */

 #include "mbed-test-async/async_test.h"

using namespace mbed::test::v0;


Case::Case(const char *description,
           const case_handler_t handler,
           const case_set_up_handler_t set_up_handler,
           const case_tear_down_handler_t tear_down_handler,
           const case_failure_handler_t failure_handler) :
    description(description),
    handler(handler),
    control_flow_handler(NULL),
    set_up_handler(set_up_handler),
    tear_down_handler(tear_down_handler),
    failure_handler(failure_handler),
    timeout_ms(-1)
{}

Case::Case(const char *description,
           const case_control_flow_handler_t control_flow_handler,
           const case_set_up_handler_t set_up_handler,
           const case_tear_down_handler_t tear_down_handler,
           const case_failure_handler_t failure_handler) :
    description(description),
    handler(NULL),
    control_flow_handler(control_flow_handler),
    set_up_handler(set_up_handler),
    tear_down_handler(tear_down_handler),
    failure_handler(failure_handler),
    timeout_ms(-1)
{}

Case::Case(const char *description,
           const case_handler_t handler,
           const case_control_flow_handler_t control_flow_handler,
           const case_set_up_handler_t set_up_handler,
           const case_tear_down_handler_t tear_down_handler,
           const case_failure_handler_t failure_handler,
           const int32_t timeout_ms) :
    description(description),
    handler(handler),
    control_flow_handler(control_flow_handler),
    set_up_handler(set_up_handler),
    tear_down_handler(tear_down_handler),
    failure_handler(failure_handler),
    timeout_ms(timeout_ms)
{}

const char*
Case::get_description() const {
    return description;
}


AsyncCase::AsyncCase(const char *description,
                     const case_handler_t handler,
                     const uint32_t timeout_ms,
                     const case_set_up_handler_t set_up_handler,
                     const case_tear_down_handler_t tear_down_handler,
                     const case_failure_handler_t failure_handler) :
    Case(description, handler, NULL, set_up_handler, tear_down_handler, failure_handler, timeout_ms)
{}

AsyncCase::AsyncCase(const char *description,
                     const case_control_flow_handler_t control_flow_handler,
                     const uint32_t timeout_ms,
                     const case_set_up_handler_t set_up_handler,
                     const case_tear_down_handler_t tear_down_handler,
                     const case_failure_handler_t failure_handler) :
    Case(description, NULL, control_flow_handler, set_up_handler, tear_down_handler, failure_handler, timeout_ms)
{}
