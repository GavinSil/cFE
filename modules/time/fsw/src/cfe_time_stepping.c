/************************************************************************
 * NASA Docket No. GSC-19,200-1, and identified as "cFS Draco"
 *
 * Copyright (c) 2023 United States Government as represented by the
 * Administrator of the National Aeronautics and Space Administration.
 * All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License. You may obtain
 * a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ************************************************************************/

/*
** File: cfe_time_stepping.c
**
** Subsystem: cFE TIME Stepping Hooks
**
** Description: This file contains stepping synchronization hook implementations
**              for the cFE TIME module, enabling coordinated step control when
**              CFE_SIM_STEPPING is enabled.
**
*/

#ifdef CFE_SIM_STEPPING

#include "esa_stepping_shim.h"
#include "esa_stepping_core.h"

/****************************************************************************************
                                   STEPPING HOOK IMPLEMENTATIONS
 ***************************************************************************************/

/**
 * @brief TIME 任务循环边界 hook
 *
 * 薄转发器：在 TIME 主任务循环每次迭代开始时上报事件至统一 stepping shim。
 * 该事件标记 TIME 服务任务的调度周期边界。
 * Shim 将此事件转发到核心状态机进行 stepping 同步。
 */
void CFE_TIME_Stepping_Hook_TaskCycle(void)
{
    ESA_Stepping_ShimEvent_t event = {0};

    event.event_kind = ESA_SIM_STEPPING_EVENT_TIME_TASK_CYCLE;
    event.entity_id  = ESA_SIM_STEPPING_SERVICE_BIT_TIME;

    ESA_Stepping_Shim_ReportEvent(&event);
}

/**
 * @brief 1Hz 边界转换 hook
 *
 * 薄转发器：在 TIME 模块执行 1Hz 边界状态机更新时上报事件至统一 stepping shim。
 * 该事件标记本地 1Hz 同步点，用于协调周期性定时边界。
 * Shim 将此事件转发到核心状态机进行 stepping 同步。
 */
void CFE_TIME_Stepping_Hook_1HzBoundary(void)
{
    ESA_Stepping_ShimEvent_t event = {0};

    event.event_kind = ESA_SIM_STEPPING_EVENT_1HZ_BOUNDARY;
    event.entity_id  = ESA_SIM_STEPPING_CHILDPATH_BIT_TIME_LOCAL_1HZ;

    ESA_Stepping_Shim_ReportEvent(&event);
}

/**
 * @brief Tone 信号处理 hook
 *
 * 薄转发器：在 TIME 模块处理 tone 信号命令时上报事件至统一 stepping shim。
 * 该事件标记时间同步 tone 信号边界，用于协调硬件/软件时间同步点。
 * Shim 将此事件转发到核心状态机进行 stepping 同步。
 */
void CFE_TIME_Stepping_Hook_ToneSignal(void)
{
    ESA_Stepping_ShimEvent_t event = {0};

    event.event_kind = ESA_SIM_STEPPING_EVENT_TONE_SIGNAL;
    event.entity_id  = ESA_SIM_STEPPING_CHILDPATH_BIT_TIME_TONE;

    ESA_Stepping_Shim_ReportEvent(&event);
}

#endif /* CFE_SIM_STEPPING */
