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

/****************************************************************************************
                                  STEPPING HOOK IMPLEMENTATIONS
 ***************************************************************************************/

/**
 * @brief Hook called at each TIME task cycle
 *
 * Stub implementation called once per TIME task main loop iteration.
 * Real implementations can use this to gate task cycle execution.
 */
void CFE_TIME_Stepping_Hook_TaskCycle(void)
{
    /* Stub implementation - no-op */
}

/**
 * @brief Hook called at 1Hz boundary transitions
 *
 * Stub implementation called when the TIME module processes 1Hz boundary state machine updates.
 * Real implementations can use this to gate 1Hz synchronization points.
 */
void CFE_TIME_Stepping_Hook_1HzBoundary(void)
{
    /* Stub implementation - no-op */
}

/**
 * @brief Hook called when processing tone signal
 *
 * Stub implementation called when the TIME module processes a tone signal command.
 * Real implementations can use this to gate tone signal synchronization.
 */
void CFE_TIME_Stepping_Hook_ToneSignal(void)
{
    /* Stub implementation - no-op */
}

#endif /* CFE_SIM_STEPPING */
