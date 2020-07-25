/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Project_Sim_MPC.h
 *
 * Code generated for Simulink model 'Project_Sim_MPC'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Mon Nov 19 22:15:59 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Project_Sim_MPC_h_
#define RTW_HEADER_Project_Sim_MPC_h_
#include <math.h>
#include <string.h>
#ifndef Project_Sim_MPC_COMMON_INCLUDES_
# define Project_Sim_MPC_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* Project_Sim_MPC_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
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
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T xk1[5];                       /* '<S3>/optimizer' */
  real_T last_x_PreviousInput[5];      /* '<S3>/last_x' */
  real_T u;                            /* '<S3>/optimizer' */
  real_T last_mv_DSTATE;               /* '<S3>/last_mv' */
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWorkspace2_PWORK;              /* '<S2>/From Workspace2' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWorkspace_PWORK;               /* '<S2>/From Workspace' */

  struct {
    int_T PrevIndex;
  } FromWorkspace2_IWORK;              /* '<S2>/From Workspace2' */

  struct {
    int_T PrevIndex;
  } FromWorkspace_IWORK;               /* '<S2>/From Workspace' */

  boolean_T iAout;                     /* '<S3>/optimizer' */
  boolean_T Memory_PreviousInput;      /* '<S3>/Memory' */
} DW;

/* Continuous states (default storage) */
typedef struct {
  real_T Plantwithchangingdynamics_CSTAT[4];/* '<Root>/Plant with changing dynamics' */
} X;

/* State derivatives (default storage) */
typedef struct {
  real_T Plantwithchangingdynamics_CSTAT[4];/* '<Root>/Plant with changing dynamics' */
} XDot;

/* State disabled  */
typedef struct {
  boolean_T Plantwithchangingdynamics_CSTAT[4];/* '<Root>/Plant with changing dynamics' */
} XDis;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[4];
  real_T odeF[3][4];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Continuous states (default storage) */
extern X rtX;

/* Block signals and states (default storage) */
extern DW rtDW;

/* Model entry point functions */
extern void Project_Sim_MPC_initialize(void);
extern void Project_Sim_MPC_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S5>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S6>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S7>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S8>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S9>/Vector Dimension Check' : Unused code path elimination
 * Block '<S10>/Vector Dimension Check' : Unused code path elimination
 * Block '<S11>/Vector Dimension Check' : Unused code path elimination
 * Block '<S12>/Vector Dimension Check' : Unused code path elimination
 * Block '<S13>/Vector Dimension Check' : Unused code path elimination
 * Block '<S14>/Vector Dimension Check' : Unused code path elimination
 * Block '<S15>/Vector Dimension Check' : Unused code path elimination
 * Block '<S16>/Vector Dimension Check' : Unused code path elimination
 * Block '<S17>/Vector Dimension Check' : Unused code path elimination
 * Block '<S18>/Vector Dimension Check' : Unused code path elimination
 * Block '<S19>/Vector Dimension Check' : Unused code path elimination
 * Block '<S20>/Vector Dimension Check' : Unused code path elimination
 * Block '<S21>/Vector Dimension Check' : Unused code path elimination
 * Block '<S3>/constant' : Unused code path elimination
 * Block '<S3>/umin_scale2' : Unused code path elimination
 * Block '<S3>/umin_scale3' : Unused code path elimination
 * Block '<S3>/ym_zero' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 * Block '<Root>/Scope2' : Unused code path elimination
 * Block '<S3>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion10' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion11' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion12' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion13' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion4' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion5' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion6' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion7' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion8' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion9' : Eliminate redundant data type conversion
 * Block '<S3>/E Conversion' : Eliminate redundant data type conversion
 * Block '<S3>/F Conversion' : Eliminate redundant data type conversion
 * Block '<S3>/G Conversion' : Eliminate redundant data type conversion
 * Block '<S3>/Reshape' : Reshape block reduction
 * Block '<S3>/Reshape1' : Reshape block reduction
 * Block '<S3>/Reshape2' : Reshape block reduction
 * Block '<S3>/S Conversion' : Eliminate redundant data type conversion
 * Block '<S3>/ext.mv_scale' : Eliminated nontunable gain of 1
 * Block '<S3>/ext.mv_scale1' : Eliminated nontunable gain of 1
 * Block '<S3>/mo or x Conversion' : Eliminate redundant data type conversion
 * Block '<S3>/umax_scale' : Eliminated nontunable gain of 1
 * Block '<S3>/umin_scale' : Eliminated nontunable gain of 1
 * Block '<S3>/umin_scale1' : Eliminated nontunable gain of 1
 * Block '<S3>/umin_scale4' : Eliminated nontunable gain of 1
 * Block '<S3>/ymax_scale' : Eliminated nontunable gain of 1
 * Block '<S3>/ymin_scale' : Eliminated nontunable gain of 1
 * Block '<S3>/ymin_scale1' : Eliminated nontunable gain of 1
 * Block '<S3>/ymin_scale2' : Eliminated nontunable gain of 1
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Project_Sim_MPC'
 * '<S1>'   : 'Project_Sim_MPC/MPC Controller'
 * '<S2>'   : 'Project_Sim_MPC/Reference'
 * '<S3>'   : 'Project_Sim_MPC/MPC Controller/MPC'
 * '<S4>'   : 'Project_Sim_MPC/MPC Controller/MPC/MPC Matrix Signal Check'
 * '<S5>'   : 'Project_Sim_MPC/MPC Controller/MPC/MPC Matrix Signal Check1'
 * '<S6>'   : 'Project_Sim_MPC/MPC Controller/MPC/MPC Matrix Signal Check2'
 * '<S7>'   : 'Project_Sim_MPC/MPC Controller/MPC/MPC Preview Signal Check'
 * '<S8>'   : 'Project_Sim_MPC/MPC Controller/MPC/MPC Preview Signal Check1'
 * '<S9>'   : 'Project_Sim_MPC/MPC Controller/MPC/MPC Scalar Signal Check'
 * '<S10>'  : 'Project_Sim_MPC/MPC Controller/MPC/MPC Scalar Signal Check1'
 * '<S11>'  : 'Project_Sim_MPC/MPC Controller/MPC/MPC Vector Signal Check'
 * '<S12>'  : 'Project_Sim_MPC/MPC Controller/MPC/MPC Vector Signal Check1'
 * '<S13>'  : 'Project_Sim_MPC/MPC Controller/MPC/MPC Vector Signal Check11'
 * '<S14>'  : 'Project_Sim_MPC/MPC Controller/MPC/MPC Vector Signal Check2'
 * '<S15>'  : 'Project_Sim_MPC/MPC Controller/MPC/MPC Vector Signal Check3'
 * '<S16>'  : 'Project_Sim_MPC/MPC Controller/MPC/MPC Vector Signal Check4'
 * '<S17>'  : 'Project_Sim_MPC/MPC Controller/MPC/MPC Vector Signal Check5'
 * '<S18>'  : 'Project_Sim_MPC/MPC Controller/MPC/MPC Vector Signal Check6'
 * '<S19>'  : 'Project_Sim_MPC/MPC Controller/MPC/MPC Vector Signal Check7'
 * '<S20>'  : 'Project_Sim_MPC/MPC Controller/MPC/MPC Vector Signal Check8'
 * '<S21>'  : 'Project_Sim_MPC/MPC Controller/MPC/MPC Vector Signal Check9'
 * '<S22>'  : 'Project_Sim_MPC/MPC Controller/MPC/optimizer'
 */
#endif                                 /* RTW_HEADER_Project_Sim_MPC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
