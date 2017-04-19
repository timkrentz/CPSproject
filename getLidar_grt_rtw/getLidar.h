/*
 * getLidar.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "getLidar".
 *
 * Model version              : 1.97
 * Simulink Coder version : 8.10 (R2016a) 10-Feb-2016
 * C source code generated on : Tue Apr 18 17:38:38 2017
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_getLidar_h_
#define RTW_HEADER_getLidar_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef getLidar_COMMON_INCLUDES_
# define getLidar_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* getLidar_COMMON_INCLUDES_ */

#include "getLidar_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T robotX;                       /* '<Root>/robotX' */
  real_T robotY;                       /* '<Root>/robotY' */
  real_T orientation;                  /* '<Root>/orientation' */
  real_T walls[8];                     /* '<Root>/walls' */
} ExtU_getLidar_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T lidarRays[512];               /* '<Root>/lidarRays' */
} ExtY_getLidar_T;

/* Real-time Model Data Structure */
struct tag_RTM_getLidar_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* External inputs (root inport signals with auto storage) */
extern ExtU_getLidar_T getLidar_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_getLidar_T getLidar_Y;

/* Model entry point functions */
extern void getLidar_initialize(void);
extern void getLidar_step(void);
extern void getLidar_terminate(void);

/* Real-time Model object */
extern RT_MODEL_getLidar_T *const getLidar_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('Steering/getLidar')    - opens subsystem Steering/getLidar
 * hilite_system('Steering/getLidar/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Steering'
 * '<S1>'   : 'Steering/getLidar'
 */
#endif                                 /* RTW_HEADER_getLidar_h_ */
