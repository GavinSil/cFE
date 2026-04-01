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
** File: cfe_time_stepping.h
**
** Subsystem: cFE TIME Stepping Hooks
**
** Description: This file contains stepping synchronization hooks for the
**              cFE TIME module, enabling coordinated step control when
**              CFE_SIM_STEPPING is enabled.
**
*/

#ifndef CFE_TIME_STEPPING_H
#define CFE_TIME_STEPPING_H

/*
** Stepping hook declarations - these are called at key points in the TIME
** task cycle to allow external synchronization (simulation stepping, etc)
*/

#ifdef CFE_SIM_STEPPING

/**
 * @brief Hook called at 1Hz boundary transitions
 *
 * This hook is called when the TIME module processes 1Hz boundary state machine updates,
 * allowing stepping controllers to gate 1Hz synchronization points.
 *
 * @note This should be implemented by stepping infrastructure if CFE_SIM_STEPPING is enabled
 */
void CFE_TIME_Stepping_Hook_1HzBoundary(void);

/**
 * @brief Hook called when processing tone signal
 *
 * This hook is called when the TIME module processes a tone signal command,
 * allowing stepping controllers to gate tone signal synchronization.
 *
 * @note This should be implemented by stepping infrastructure if CFE_SIM_STEPPING is enabled
 */
void CFE_TIME_Stepping_Hook_ToneSignal(void);

#else /* CFE_SIM_STEPPING not defined */

/* No-op implementations when stepping is disabled */
#define CFE_TIME_Stepping_Hook_1HzBoundary() ((void)0)
#define CFE_TIME_Stepping_Hook_ToneSignal()  ((void)0)

#endif /* CFE_SIM_STEPPING */

#endif /* CFE_TIME_STEPPING_H */
