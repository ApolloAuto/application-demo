/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
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
 *****************************************************************************/
#include "example_components/src/timer_common_component_example.h"

bool TimerCommonComponentSample::Init() {
    using apollo::cyber::ComponentBase;
    using example::proto::Driver;
    AINFO << "Commontest component init";
    driver_writer_ = ComponentBase::node_->CreateWriter<Driver>("/apollo/channel_example/driver_test");
    second_driver_writer_ = ComponentBase::node_->CreateWriter<Driver>("/apollo/channel_example/driver_test2");
    return true;
}

bool TimerCommonComponentSample::Proc() {
    static int i = 0;
    auto out_msg = std::make_shared<example::proto::Driver>();
    out_msg->set_msg_id(i++);
    driver_writer_->Write(out_msg);
    second_driver_writer_->Write(out_msg);
    AINFO << "timer_component_example: Write same drivermsg to mutliple channel->"
            << out_msg->ShortDebugString();
    return true;
}
