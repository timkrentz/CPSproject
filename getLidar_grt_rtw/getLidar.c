/*
 * getLidar.c
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

#include "getLidar.h"
#include "getLidar_private.h"

/* External inputs (root inport signals with auto storage) */
ExtU_getLidar_T getLidar_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_getLidar_T getLidar_Y;

/* Real-time model */
RT_MODEL_getLidar_T getLidar_M_;
RT_MODEL_getLidar_T *const getLidar_M = &getLidar_M_;

/* Forward declaration for local functions */
static void getLidar_inv(const real_T x[4], real_T y[4]);

/* Function for MATLAB Function: '<Root>/getLidar' */
static void getLidar_inv(const real_T x[4], real_T y[4])
{
  real_T r;
  real_T t;
  if (fabs(x[1]) > fabs(x[0])) {
    r = x[0] / x[1];
    t = 1.0 / (r * x[3] - x[2]);
    y[0] = x[3] / x[1] * t;
    y[1] = -t;
    y[2] = -x[2] / x[1] * t;
    y[3] = r * t;
  } else {
    r = x[1] / x[0];
    t = 1.0 / (x[3] - r * x[2]);
    y[0] = x[3] / x[0] * t;
    y[1] = -r * t;
    y[2] = -x[2] / x[0] * t;
    y[3] = t;
  }
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T a;
  a = fabs(u0);
  y = fabs(u1);
  if (a < y) {
    a /= y;
    y *= sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = sqrt(y * y + 1.0) * a;
  } else {
    if (!rtIsNaN(y)) {
      y = a * 1.4142135623730951;
    }
  }

  return y;
}

/* Model step function */
void getLidar_step(void)
{
  real_T X;
  real_T Y;
  int32_T i;
  int32_T j;
  real_T rtb_lidarRays[512];
  real_T tmp[4];
  real_T tmp_0[4];
  real_T tmp_1[4];
  real_T Q[4];
  real_T Q_0;
  real_T INT;
  real_T INT_idx_0;
  real_T Q_idx_0;
  real_T rtb_lidarRays_i;

  /* MATLAB Function: '<Root>/getLidar' incorporates:
   *  Inport: '<Root>/orientation'
   *  Inport: '<Root>/robotX'
   *  Inport: '<Root>/robotY'
   *  Inport: '<Root>/walls'
   */
  /* MATLAB Function 'getLidar': '<S1>:1' */
  /* '<S1>:1:32' */
  /* '<S1>:1:26' */
  /* '<S1>:1:8' */
  /* '<S1>:1:4' */
  /* Create rays matrix */
  /* '<S1>:1:7' */
  /* '<S1>:1:8' */
  /* '<S1>:1:9' */
  /* For each LIDAR ray... */
  /* '<S1>:1:18' */
  for (i = 0; i < 256; i++) {
    /* '<S1>:1:9' */
    /* '<S1>:1:10' */
    rtb_lidarRays[i] = 40.0;

    /* '<S1>:1:11' */
    rtb_lidarRays[256 + i] = 0.024543692606170259 * (real_T)i;

    /* '<S1>:1:9' */
    /* '<S1>:1:18' */
    /* Find its ending coordinate */
    /* '<S1>:1:21' */
    X = cos(0.024543692606170259 * (real_T)i + getLidar_U.orientation) * 40.0 +
      getLidar_U.robotX;

    /* '<S1>:1:22' */
    Y = sin(0.024543692606170259 * (real_T)i + getLidar_U.orientation) * 40.0 +
      getLidar_U.robotY;

    /* Find standard form of LIDAR ray */
    /* '<S1>:1:25' */
    /* '<S1>:1:26' */
    tmp[0] = getLidar_U.robotX;
    tmp[2] = getLidar_U.robotY;
    tmp[1] = X;
    tmp[3] = Y;
    getLidar_inv(tmp, tmp_0);
    Q_idx_0 = tmp_0[0] + tmp_0[2];
    Q_0 = tmp_0[1] + tmp_0[3];

    /* For each wall... */
    /* '<S1>:1:29' */
    for (j = 0; j < 2; j++) {
      rtb_lidarRays_i = rtb_lidarRays[i];

      /* '<S1>:1:29' */
      /* Find standard form of wall */
      /* '<S1>:1:32' */
      /* '<S1>:1:33' */
      /* Find intersection of wall and LIDAR ray */
      /* '<S1>:1:36' */
      tmp_1[0] = getLidar_U.walls[j];
      tmp_1[1] = getLidar_U.walls[j + 4];
      tmp_1[2] = getLidar_U.walls[j + 2];
      tmp_1[3] = getLidar_U.walls[j + 6];
      getLidar_inv(tmp_1, tmp_0);
      Q[0] = Q_idx_0;
      Q[1] = tmp_0[0] + tmp_0[2];
      Q[2] = Q_0;
      Q[3] = tmp_0[1] + tmp_0[3];
      getLidar_inv(Q, tmp_0);
      INT_idx_0 = tmp_0[0] + tmp_0[2];
      INT = tmp_0[1] + tmp_0[3];

      /* '<S1>:1:37' */
      /*  x coordinate of intersection */
      /* '<S1>:1:38' */
      /*  y coordinate of intersection */
      /* Check that intersection actually occurs within the */
      /* bounds of the LIDAR ray and wall */
      /* Checks if a value lies inbetween A and B, regardless of order */
      /*    Has +-0.0001 buffer */
      if ((((INT >= getLidar_U.robotY - 0.0001) && (INT <= Y + 0.0001)) || ((INT
             >= Y - 0.0001) && (INT <= getLidar_U.robotY + 0.0001))) &&
          (((INT_idx_0 >= getLidar_U.robotX - 0.0001) && (INT_idx_0 <= X +
             0.0001)) || ((INT_idx_0 >= X - 0.0001) && (INT_idx_0 <=
             getLidar_U.robotX + 0.0001))) && (((INT_idx_0 >= getLidar_U.walls[j]
             - 0.0001) && (INT_idx_0 <= getLidar_U.walls[4 + j] + 0.0001)) ||
           ((INT_idx_0 >= getLidar_U.walls[4 + j] - 0.0001) && (INT_idx_0 <=
             getLidar_U.walls[j] + 0.0001))) && (((INT >= getLidar_U.walls[2 + j]
             - 0.0001) && (INT <= getLidar_U.walls[6 + j] + 0.0001)) || ((INT >=
             getLidar_U.walls[6 + j] - 0.0001) && (INT <= getLidar_U.walls[2 + j]
             + 0.0001)))) {
        /* '<S1>:1:42' */
        /* Checks if a value lies inbetween A and B, regardless of order */
        /*    Has +-0.0001 buffer */
        /* '<S1>:1:43' */
        /* Checks if a value lies inbetween A and B, regardless of order */
        /*    Has +-0.0001 buffer */
        /* '<S1>:1:44' */
        /* Checks if a value lies inbetween A and B, regardless of order */
        /*    Has +-0.0001 buffer */
        /* '<S1>:1:45' */
        /*              disp('INTERSECTION') */
        /* '<S1>:1:47' */
        INT_idx_0 = rt_hypotd_snf(INT_idx_0 - getLidar_U.robotX, INT -
          getLidar_U.robotY);

        /* Clip ranges beyond max sensitivity */
        if (INT_idx_0 > 40.0) {
          /* '<S1>:1:50' */
          /* '<S1>:1:51' */
          INT_idx_0 = 40.0;
        }

        /* Only store the minimum range for each wall */
        if (rtb_lidarRays[i] > INT_idx_0) {
          /* '<S1>:1:55' */
          /* '<S1>:1:56' */
          rtb_lidarRays_i = INT_idx_0;
        }
      } else {
        /*              disp('NOPE') */
      }

      /* '<S1>:1:29' */
      rtb_lidarRays[i] = rtb_lidarRays_i;
    }

    /* '<S1>:1:18' */
  }

  /* End of MATLAB Function: '<Root>/getLidar' */

  /* Outport: '<Root>/lidarRays' */
  memcpy(&getLidar_Y.lidarRays[0], &rtb_lidarRays[0], sizeof(real_T) << 9U);

  /* Matfile logging */
  rt_UpdateTXYLogVars(getLidar_M->rtwLogInfo, (&getLidar_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.001s, 0.0s] */
    if ((rtmGetTFinal(getLidar_M)!=-1) &&
        !((rtmGetTFinal(getLidar_M)-getLidar_M->Timing.taskTime0) >
          getLidar_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(getLidar_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++getLidar_M->Timing.clockTick0)) {
    ++getLidar_M->Timing.clockTickH0;
  }

  getLidar_M->Timing.taskTime0 = getLidar_M->Timing.clockTick0 *
    getLidar_M->Timing.stepSize0 + getLidar_M->Timing.clockTickH0 *
    getLidar_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void getLidar_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)getLidar_M, 0,
                sizeof(RT_MODEL_getLidar_T));
  rtmSetTFinal(getLidar_M, 1.0);
  getLidar_M->Timing.stepSize0 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    getLidar_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(getLidar_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(getLidar_M->rtwLogInfo, (NULL));
    rtliSetLogT(getLidar_M->rtwLogInfo, "tout");
    rtliSetLogX(getLidar_M->rtwLogInfo, "");
    rtliSetLogXFinal(getLidar_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(getLidar_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(getLidar_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(getLidar_M->rtwLogInfo, 0);
    rtliSetLogDecimation(getLidar_M->rtwLogInfo, 1);
    rtliSetLogY(getLidar_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(getLidar_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(getLidar_M->rtwLogInfo, (NULL));
  }

  /* external inputs */
  (void) memset((void *)&getLidar_U, 0,
                sizeof(ExtU_getLidar_T));

  /* external outputs */
  (void) memset(&getLidar_Y.lidarRays[0], 0,
                512U*sizeof(real_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(getLidar_M->rtwLogInfo, 0.0, rtmGetTFinal
    (getLidar_M), getLidar_M->Timing.stepSize0, (&rtmGetErrorStatus(getLidar_M)));
}

/* Model terminate function */
void getLidar_terminate(void)
{
  /* (no terminate code required) */
}
