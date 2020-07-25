/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Project_Sim_MPC.c
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

#include "Project_Sim_MPC.h"

/* Named constants for MATLAB Function: '<S3>/optimizer' */
#define ny                             (2.0)

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

/* Used by FromWorkspace Block: '<S2>/From Workspace2' */
#ifndef rtInterpolate
# define rtInterpolate(v1,v2,f1,f2)    (((v1)==(v2))?((double)(v1)): (((f1)*((double)(v1)))+((f2)*((double)(v2)))))
#endif

#ifndef rtRound
# define rtRound(v)                    ( ((v) >= 0) ? floor((v) + 0.5) : ceil((v) - 0.5) )
#endif

/* Continuous states */
X rtX;

/* Block signals and states (default storage) */
DW rtDW;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* private model entry point functions */
extern void Project_Sim_MPC_derivatives(void);

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Project_Sim_MPC_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  Project_Sim_MPC_step();
  Project_Sim_MPC_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  Project_Sim_MPC_step();
  Project_Sim_MPC_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void Project_Sim_MPC_step(void)
{
  /* local block i/o variables */
  real_T rtb_FromWorkspace2;
  real_T rtb_FromWorkspace;
  if (rtmIsMajorTimeStep(rtM)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&rtM->solverInfo,((rtM->Timing.clockTick0+1)*
      rtM->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(rtM)) {
    rtM->Timing.t[0] = rtsiGetT(&rtM->solverInfo);
  }

  {
    real_T rseq[20];
    static const real_T a_0[10] = { -0.24399868166951261, 0.14060869226058112,
      0.21411690183415785, 0.50631045521506235, -0.0357934370056684,
      -0.14569818355099956, 0.068357225516489317, 0.20666406614713317,
      0.10481525525491273, 0.085697711904000745 };

    static const int8_T b_a[10] = { 0, 0, 0, 1, 0, 0, 1, 0, 0, 1 };

    static const real_T b_Kx_0[10] = { 22.994058377653104, 652.79851529780308,
      53.354227290582806, 54.461427426700325, 0.0, 17.080793367576021,
      485.9261137569639, 40.067066077709576, 39.396909688464589, 0.0 };

    static const real_T b_Kr_0[40] = { -0.11400709822746803, -0.0,
      -0.45483902928779751, -0.0, -1.0528441622800591, -0.0, -1.9518731003560692,
      -0.0, -3.1899925509786087, -0.0, -4.7935381665225441, -0.0,
      -6.7777668235418593, -0.0, -9.1498755631424853, -0.0, -11.9121731941277,
      -0.0, -15.06451773823574, -0.0, -0.0, -0.0, -0.11400709822746803, -0.0,
      -0.45483902928779751, -0.0, -1.0528441622800591, -0.0, -1.9518731003560692,
      -0.0, -3.1899925509786087, -0.0, -4.7935381665225441, -0.0,
      -6.7777668235418593, -0.0, -9.1498755631424853, -0.0, -11.9121731941277,
      -0.0 };

    static const real_T c_a_0[25] = { 0.59029522013726732, 0.0050186685703353341,
      0.083693736924718931, 0.081595384470467269, 0.0, 0.0, 1.0, 0.0, 1.5, 0.0,
      -0.74954881953164743, 0.076034046986390588, 0.54309372380774523,
      0.01780173334859092, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0
    };

    static const real_T d_a_0[5] = { 1.1898718909245078, 0.070741975047093675,
      1.3270514387018264, 0.11400709822746803, 0.0 };

    static const real_T e_a_0[10] = { -0.30452232652087458, 0.15566431832032182,
      0.0958643840736638, 0.70112597935670129, -0.0357934370056684,
      -0.24090974815303129, 0.083339519937776621, 0.10004393181656998,
      0.199141772824441, 0.085697711904000745 };

    boolean_T rtb_Memory;
    real_T rtb_last_x[5];
    real_T rtb_last_mv;
    real_T rtb_TmpSignalConversionAtSFunct[2];
    real_T rtb_xest[5];
    int32_T i;
    real_T tmp;
    real_T tmp_0;
    real_T LateralPositionYawAngle[2];
    int32_T rseq_tmp;

    /* StateSpace: '<Root>/Plant with changing dynamics' */
    LateralPositionYawAngle[0] = rtX.Plantwithchangingdynamics_CSTAT[3];
    LateralPositionYawAngle[1] = rtX.Plantwithchangingdynamics_CSTAT[1];
    if (rtmIsMajorTimeStep(rtM)) {
      /* Memory: '<S3>/Memory' */
      rtb_Memory = rtDW.Memory_PreviousInput;

      /* UnitDelay: '<S3>/last_mv' */
      rtb_last_mv = rtDW.last_mv_DSTATE;

      /* Memory: '<S3>/last_x' */
      for (i = 0; i < 5; i++) {
        rtb_last_x[i] = rtDW.last_x_PreviousInput[i];
      }

      /* End of Memory: '<S3>/last_x' */

      /* FromWorkspace: '<S2>/From Workspace2' */
      {
        real_T *pDataValues = (real_T *) rtDW.FromWorkspace2_PWORK.DataPtr;
        real_T *pTimeValues = (real_T *) rtDW.FromWorkspace2_PWORK.TimePtr;
        int_T currTimeIndex = rtDW.FromWorkspace2_IWORK.PrevIndex;
        real_T t = ((rtM->Timing.clockTick1) * 0.1);

        /* Get index */
        if (t <= pTimeValues[0]) {
          currTimeIndex = 0;
        } else if (t >= pTimeValues[13]) {
          currTimeIndex = 12;
        } else {
          if (t < pTimeValues[currTimeIndex]) {
            while (t < pTimeValues[currTimeIndex]) {
              currTimeIndex--;
            }
          } else {
            while (t >= pTimeValues[currTimeIndex + 1]) {
              currTimeIndex++;
            }
          }
        }

        rtDW.FromWorkspace2_IWORK.PrevIndex = currTimeIndex;

        /* Post output */
        {
          real_T t1 = pTimeValues[currTimeIndex];
          real_T t2 = pTimeValues[currTimeIndex + 1];
          if (t1 == t2) {
            if (t < t1) {
              rtb_FromWorkspace2 = pDataValues[currTimeIndex];
            } else {
              rtb_FromWorkspace2 = pDataValues[currTimeIndex + 1];
            }
          } else {
            real_T f1 = (t2 - t) / (t2 - t1);
            real_T f2 = 1.0 - f1;
            real_T d1;
            real_T d2;
            int_T TimeIndex= currTimeIndex;
            d1 = pDataValues[TimeIndex];
            d2 = pDataValues[TimeIndex + 1];
            rtb_FromWorkspace2 = (real_T) rtInterpolate(d1, d2, f1, f2);
            pDataValues += 14;
          }
        }
      }

      /* FromWorkspace: '<S2>/From Workspace' */
      {
        real_T *pDataValues = (real_T *) rtDW.FromWorkspace_PWORK.DataPtr;
        real_T *pTimeValues = (real_T *) rtDW.FromWorkspace_PWORK.TimePtr;
        int_T currTimeIndex = rtDW.FromWorkspace_IWORK.PrevIndex;
        real_T t = ((rtM->Timing.clockTick1) * 0.1);

        /* Get index */
        if (t <= pTimeValues[0]) {
          currTimeIndex = 0;
        } else if (t >= pTimeValues[13]) {
          currTimeIndex = 12;
        } else {
          if (t < pTimeValues[currTimeIndex]) {
            while (t < pTimeValues[currTimeIndex]) {
              currTimeIndex--;
            }
          } else {
            while (t >= pTimeValues[currTimeIndex + 1]) {
              currTimeIndex++;
            }
          }
        }

        rtDW.FromWorkspace_IWORK.PrevIndex = currTimeIndex;

        /* Post output */
        {
          real_T t1 = pTimeValues[currTimeIndex];
          real_T t2 = pTimeValues[currTimeIndex + 1];
          if (t1 == t2) {
            if (t < t1) {
              rtb_FromWorkspace = pDataValues[currTimeIndex];
            } else {
              rtb_FromWorkspace = pDataValues[currTimeIndex + 1];
            }
          } else {
            real_T f1 = (t2 - t) / (t2 - t1);
            real_T f2 = 1.0 - f1;
            real_T d1;
            real_T d2;
            int_T TimeIndex= currTimeIndex;
            d1 = pDataValues[TimeIndex];
            d2 = pDataValues[TimeIndex + 1];
            rtb_FromWorkspace = (real_T) rtInterpolate(d1, d2, f1, f2);
            pDataValues += 14;
          }
        }
      }

      /* MATLAB Function: '<S3>/optimizer' incorporates:
       *  SignalConversion: '<S22>/TmpSignal ConversionAt SFunction Inport4'
       */
      memset(&rseq[0], 0, 20U * sizeof(real_T));
      for (i = 0; i < 10; i++) {
        rseq_tmp = i * (int32_T)ny;
        rseq[rseq_tmp] = rtb_FromWorkspace2;
        rseq[1 + rseq_tmp] = rtb_FromWorkspace;
      }

      for (rseq_tmp = 0; rseq_tmp < 2; rseq_tmp++) {
        tmp = 0.0;
        for (i = 0; i < 5; i++) {
          tmp += (real_T)b_a[(i << 1) + rseq_tmp] * rtb_last_x[i];
        }

        rtb_TmpSignalConversionAtSFunct[rseq_tmp] =
          LateralPositionYawAngle[rseq_tmp] - tmp;
      }

      for (rseq_tmp = 0; rseq_tmp < 5; rseq_tmp++) {
        rtb_xest[rseq_tmp] = (a_0[rseq_tmp + 5] *
                              rtb_TmpSignalConversionAtSFunct[1] + a_0[rseq_tmp]
                              * rtb_TmpSignalConversionAtSFunct[0]) +
          rtb_last_x[rseq_tmp];
      }

      for (i = 0; i < 2; i++) {
        tmp = 0.0;
        for (rseq_tmp = 0; rseq_tmp < 5; rseq_tmp++) {
          tmp += b_Kx_0[5 * i + rseq_tmp] * rtb_xest[rseq_tmp];
        }

        tmp_0 = 0.0;
        for (rseq_tmp = 0; rseq_tmp < 20; rseq_tmp++) {
          tmp_0 += b_Kr_0[20 * i + rseq_tmp] * rseq[rseq_tmp];
        }

        LateralPositionYawAngle[i] = (-129.73532387887974 * (real_T)i +
          536.7901370479683) * rtb_last_mv + (tmp + tmp_0);
      }

      rtb_last_mv += (0.0 - 0.484530179534217 * LateralPositionYawAngle[0]) -
        -0.63651345812785476 * LateralPositionYawAngle[1];
      rtDW.u = rtb_last_mv;
      rtDW.iAout = rtb_Memory;
      for (rseq_tmp = 0; rseq_tmp < 5; rseq_tmp++) {
        tmp = 0.0;
        for (i = 0; i < 5; i++) {
          tmp += c_a_0[5 * i + rseq_tmp] * rtb_last_x[i];
        }

        rtDW.xk1[rseq_tmp] = (d_a_0[rseq_tmp] * rtb_last_mv + tmp) +
          (e_a_0[rseq_tmp + 5] * rtb_TmpSignalConversionAtSFunct[1] +
           e_a_0[rseq_tmp] * rtb_TmpSignalConversionAtSFunct[0]);
      }

      /* End of MATLAB Function: '<S3>/optimizer' */
    }
  }

  if (rtmIsMajorTimeStep(rtM)) {
    int32_T i;
    if (rtmIsMajorTimeStep(rtM)) {
      /* Update for Memory: '<S3>/Memory' */
      rtDW.Memory_PreviousInput = rtDW.iAout;

      /* Update for UnitDelay: '<S3>/last_mv' */
      rtDW.last_mv_DSTATE = rtDW.u;

      /* Update for Memory: '<S3>/last_x' */
      for (i = 0; i < 5; i++) {
        rtDW.last_x_PreviousInput[i] = rtDW.xk1[i];
      }

      /* End of Update for Memory: '<S3>/last_x' */
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(rtM)) {
    rt_ertODEUpdateContinuousStates(&rtM->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++rtM->Timing.clockTick0;
    rtM->Timing.t[0] = rtsiGetSolverStopTime(&rtM->solverInfo);

    {
      /* Update absolute timer for sample time: [0.1s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.1, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      rtM->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Project_Sim_MPC_derivatives(void)
{
  XDot *_rtXdot;
  _rtXdot = ((XDot *) rtM->derivs);

  /* Derivatives for StateSpace: '<Root>/Plant with changing dynamics' */
  _rtXdot->Plantwithchangingdynamics_CSTAT[0] = 0.0;
  _rtXdot->Plantwithchangingdynamics_CSTAT[1] = 0.0;
  _rtXdot->Plantwithchangingdynamics_CSTAT[2] = 0.0;
  _rtXdot->Plantwithchangingdynamics_CSTAT[3] = 0.0;
  _rtXdot->Plantwithchangingdynamics_CSTAT[0] += -4.4021164021164028 *
    rtX.Plantwithchangingdynamics_CSTAT[0];
  _rtXdot->Plantwithchangingdynamics_CSTAT[0] += -12.46031746031746 *
    rtX.Plantwithchangingdynamics_CSTAT[2];
  _rtXdot->Plantwithchangingdynamics_CSTAT[1] +=
    rtX.Plantwithchangingdynamics_CSTAT[2];
  _rtXdot->Plantwithchangingdynamics_CSTAT[2] += 1.3913043478260869 *
    rtX.Plantwithchangingdynamics_CSTAT[0];
  _rtXdot->Plantwithchangingdynamics_CSTAT[2] += -5.186782608695653 *
    rtX.Plantwithchangingdynamics_CSTAT[2];
  _rtXdot->Plantwithchangingdynamics_CSTAT[3] +=
    rtX.Plantwithchangingdynamics_CSTAT[0];
  _rtXdot->Plantwithchangingdynamics_CSTAT[3] += 15.0 *
    rtX.Plantwithchangingdynamics_CSTAT[1];
  _rtXdot->Plantwithchangingdynamics_CSTAT[0] += 24.126984126984127 * rtDW.u;
  _rtXdot->Plantwithchangingdynamics_CSTAT[2] += 15.860869565217392 * rtDW.u;
}

/* Model initialize function */
void Project_Sim_MPC_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&rtM->solverInfo, &rtM->Timing.simTimeStep);
    rtsiSetTPtr(&rtM->solverInfo, &rtmGetTPtr(rtM));
    rtsiSetStepSizePtr(&rtM->solverInfo, &rtM->Timing.stepSize0);
    rtsiSetdXPtr(&rtM->solverInfo, &rtM->derivs);
    rtsiSetContStatesPtr(&rtM->solverInfo, (real_T **) &rtM->contStates);
    rtsiSetNumContStatesPtr(&rtM->solverInfo, &rtM->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&rtM->solverInfo,
      &rtM->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&rtM->solverInfo,
      &rtM->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&rtM->solverInfo,
      &rtM->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&rtM->solverInfo, (&rtmGetErrorStatus(rtM)));
    rtsiSetRTModelPtr(&rtM->solverInfo, rtM);
  }

  rtsiSetSimTimeStep(&rtM->solverInfo, MAJOR_TIME_STEP);
  rtM->intgData.y = rtM->odeY;
  rtM->intgData.f[0] = rtM->odeF[0];
  rtM->intgData.f[1] = rtM->odeF[1];
  rtM->intgData.f[2] = rtM->odeF[2];
  rtM->contStates = ((X *) &rtX);
  rtsiSetSolverData(&rtM->solverInfo, (void *)&rtM->intgData);
  rtsiSetSolverName(&rtM->solverInfo,"ode3");
  rtmSetTPtr(rtM, &rtM->Timing.tArray[0]);
  rtM->Timing.stepSize0 = 0.1;

  /* Start for FromWorkspace: '<S2>/From Workspace2' */
  {
    static real_T pTimeValues0[] = { 0.0, 2.1, 3.3, 4.87, 7.77, 10.42, 12.41,
      15.57, 17.61, 19.65, 23.0, 26.58, 28.62, 29.99 } ;

    static real_T pDataValues0[] = { 21.4, 21.1, 18.5, 12.0, -2.7, -15.3, -21.8,
      -21.7, -20.8, -12.6, 5.7, 21.3, 21.8, 21.4 } ;

    rtDW.FromWorkspace2_PWORK.TimePtr = (void *) pTimeValues0;
    rtDW.FromWorkspace2_PWORK.DataPtr = (void *) pDataValues0;
    rtDW.FromWorkspace2_IWORK.PrevIndex = 0;
  }

  /* Start for FromWorkspace: '<S2>/From Workspace' */
  {
    static real_T pTimeValues0[] = { 0.0, 2.1, 3.3, 4.87, 7.77, 10.42, 12.41,
      15.57, 17.61, 19.65, 23.0, 26.58, 28.62, 29.99 } ;

    static real_T pDataValues0[] = { -0.081506876068135184, -0.16755160819145562,
      -0.576482251933727, -1.1992157290453038, -1.638689634697476,
      -1.9746655157063844, -2.6989771552840311, 3.0937706320851484,
      2.821324735848834, 1.9573867561116407, 1.4770721459628011,
      0.53860860716545012, -0.0890117918517108, -0.082030474843733492 } ;

    rtDW.FromWorkspace_PWORK.TimePtr = (void *) pTimeValues0;
    rtDW.FromWorkspace_PWORK.DataPtr = (void *) pDataValues0;
    rtDW.FromWorkspace_IWORK.PrevIndex = 0;
  }

  /* InitializeConditions for StateSpace: '<Root>/Plant with changing dynamics' */
  rtX.Plantwithchangingdynamics_CSTAT[0] = 0.0;
  rtX.Plantwithchangingdynamics_CSTAT[1] = 0.0;
  rtX.Plantwithchangingdynamics_CSTAT[2] = 0.0;
  rtX.Plantwithchangingdynamics_CSTAT[3] = 0.0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
