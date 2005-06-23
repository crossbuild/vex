
/*---------------------------------------------------------------*/
/*---                                                         ---*/
/*--- This file (host-ppc32/hdefs.c) is                       ---*/
/*--- Copyright (c) OpenWorks LLP.  All rights reserved.      ---*/
/*---                                                         ---*/
/*---------------------------------------------------------------*/

/*
   This file is part of LibVEX, a library for dynamic binary
   instrumentation and translation.

   Copyright (C) 2004-2005 OpenWorks LLP.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; Version 2 dated June 1991 of the
   license.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE, or liability
   for damages.  See the GNU General Public License for more details.

   Neither the names of the U.S. Department of Energy nor the
   University of California nor the names of its contributors may be
   used to endorse or promote products derived from this software
   without prior written permission.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
   USA.
*/

#include "libvex_basictypes.h"
#include "libvex.h"
#include "libvex_trc_values.h"

#include "main/vex_util.h"
#include "host-generic/h_generic_regs.h"
#include "host-ppc32/hdefs.h"


/* --------- Registers. --------- */

void ppHRegPPC32 ( HReg reg ) 
{
   Int r;
   static HChar* ireg32_names[32] 
      = { "%r0",  "%r1",  "%r2",  "%r3",  "%r4",  "%r5",  "%r6",  "%r7",
          "%r8",  "%r9",  "%r10", "%r11", "%r12", "%r13", "%r14", "%r15",
          "%r16", "%r17", "%r18", "%r19", "%r20", "%r21", "%r22", "%r23",
          "%r24", "%r25", "%r26", "%r27", "%r28", "%r29", "%r30", "%r31" };
   /* Be generic for all virtual regs. */
   if (hregIsVirtual(reg)) {
      ppHReg(reg);
      return;
   }
   /* But specific for real regs. */
   switch (hregClass(reg)) {
   case HRcInt32:
      r = hregNumber(reg);
      vassert(r >= 0 && r < 32);
      vex_printf("%s", ireg32_names[r]);
      return;
   case HRcFlt64:
      r = hregNumber(reg);
      vassert(r >= 0 && r < 32);
      vex_printf("%%fr%d", r);
      return;
   default:
      vpanic("ppHRegPPC32");
   }
}

HReg hregPPC32_GPR0  ( void ) { return mkHReg( 0, HRcInt32, False); }
HReg hregPPC32_GPR1  ( void ) { return mkHReg( 1, HRcInt32, False); }
HReg hregPPC32_GPR2  ( void ) { return mkHReg( 2, HRcInt32, False); }
HReg hregPPC32_GPR3  ( void ) { return mkHReg( 3, HRcInt32, False); }
HReg hregPPC32_GPR4  ( void ) { return mkHReg( 4, HRcInt32, False); }
HReg hregPPC32_GPR5  ( void ) { return mkHReg( 5, HRcInt32, False); }
HReg hregPPC32_GPR6  ( void ) { return mkHReg( 6, HRcInt32, False); }
HReg hregPPC32_GPR7  ( void ) { return mkHReg( 7, HRcInt32, False); }
HReg hregPPC32_GPR8  ( void ) { return mkHReg( 8, HRcInt32, False); }
HReg hregPPC32_GPR9  ( void ) { return mkHReg( 9, HRcInt32, False); }
HReg hregPPC32_GPR10 ( void ) { return mkHReg(10, HRcInt32, False); }
HReg hregPPC32_GPR11 ( void ) { return mkHReg(11, HRcInt32, False); }
HReg hregPPC32_GPR12 ( void ) { return mkHReg(12, HRcInt32, False); }
HReg hregPPC32_GPR13 ( void ) { return mkHReg(13, HRcInt32, False); }
HReg hregPPC32_GPR14 ( void ) { return mkHReg(14, HRcInt32, False); }
HReg hregPPC32_GPR15 ( void ) { return mkHReg(15, HRcInt32, False); }
HReg hregPPC32_GPR16 ( void ) { return mkHReg(16, HRcInt32, False); }
HReg hregPPC32_GPR17 ( void ) { return mkHReg(17, HRcInt32, False); }
HReg hregPPC32_GPR18 ( void ) { return mkHReg(18, HRcInt32, False); }
HReg hregPPC32_GPR19 ( void ) { return mkHReg(19, HRcInt32, False); }
HReg hregPPC32_GPR20 ( void ) { return mkHReg(20, HRcInt32, False); }
HReg hregPPC32_GPR21 ( void ) { return mkHReg(21, HRcInt32, False); }
HReg hregPPC32_GPR22 ( void ) { return mkHReg(22, HRcInt32, False); }
HReg hregPPC32_GPR23 ( void ) { return mkHReg(23, HRcInt32, False); }
HReg hregPPC32_GPR24 ( void ) { return mkHReg(24, HRcInt32, False); }
HReg hregPPC32_GPR25 ( void ) { return mkHReg(25, HRcInt32, False); }
HReg hregPPC32_GPR26 ( void ) { return mkHReg(26, HRcInt32, False); }
HReg hregPPC32_GPR27 ( void ) { return mkHReg(27, HRcInt32, False); }
HReg hregPPC32_GPR28 ( void ) { return mkHReg(28, HRcInt32, False); }
HReg hregPPC32_GPR29 ( void ) { return mkHReg(29, HRcInt32, False); }
HReg hregPPC32_GPR30 ( void ) { return mkHReg(30, HRcInt32, False); }
HReg hregPPC32_GPR31 ( void ) { return mkHReg(31, HRcInt32, False); }

HReg hregPPC32_FPR0  ( void ) { return mkHReg( 0, HRcFlt64, False); }
HReg hregPPC32_FPR1  ( void ) { return mkHReg( 1, HRcFlt64, False); }
HReg hregPPC32_FPR2  ( void ) { return mkHReg( 2, HRcFlt64, False); }
HReg hregPPC32_FPR3  ( void ) { return mkHReg( 3, HRcFlt64, False); }
HReg hregPPC32_FPR4  ( void ) { return mkHReg( 4, HRcFlt64, False); }
HReg hregPPC32_FPR5  ( void ) { return mkHReg( 5, HRcFlt64, False); }
HReg hregPPC32_FPR6  ( void ) { return mkHReg( 6, HRcFlt64, False); }
HReg hregPPC32_FPR7  ( void ) { return mkHReg( 7, HRcFlt64, False); }
HReg hregPPC32_FPR8  ( void ) { return mkHReg( 8, HRcFlt64, False); }
HReg hregPPC32_FPR9  ( void ) { return mkHReg( 9, HRcFlt64, False); }
HReg hregPPC32_FPR10 ( void ) { return mkHReg(10, HRcFlt64, False); }
HReg hregPPC32_FPR11 ( void ) { return mkHReg(11, HRcFlt64, False); }
HReg hregPPC32_FPR12 ( void ) { return mkHReg(12, HRcFlt64, False); }
HReg hregPPC32_FPR13 ( void ) { return mkHReg(13, HRcFlt64, False); }
HReg hregPPC32_FPR14 ( void ) { return mkHReg(14, HRcFlt64, False); }
HReg hregPPC32_FPR15 ( void ) { return mkHReg(15, HRcFlt64, False); }
HReg hregPPC32_FPR16 ( void ) { return mkHReg(16, HRcFlt64, False); }
HReg hregPPC32_FPR17 ( void ) { return mkHReg(17, HRcFlt64, False); }
HReg hregPPC32_FPR18 ( void ) { return mkHReg(18, HRcFlt64, False); }
HReg hregPPC32_FPR19 ( void ) { return mkHReg(19, HRcFlt64, False); }
HReg hregPPC32_FPR20 ( void ) { return mkHReg(20, HRcFlt64, False); }
HReg hregPPC32_FPR21 ( void ) { return mkHReg(21, HRcFlt64, False); }
HReg hregPPC32_FPR22 ( void ) { return mkHReg(22, HRcFlt64, False); }
HReg hregPPC32_FPR23 ( void ) { return mkHReg(23, HRcFlt64, False); }
HReg hregPPC32_FPR24 ( void ) { return mkHReg(24, HRcFlt64, False); }
HReg hregPPC32_FPR25 ( void ) { return mkHReg(25, HRcFlt64, False); }
HReg hregPPC32_FPR26 ( void ) { return mkHReg(26, HRcFlt64, False); }
HReg hregPPC32_FPR27 ( void ) { return mkHReg(27, HRcFlt64, False); }
HReg hregPPC32_FPR28 ( void ) { return mkHReg(28, HRcFlt64, False); }
HReg hregPPC32_FPR29 ( void ) { return mkHReg(29, HRcFlt64, False); }
HReg hregPPC32_FPR30 ( void ) { return mkHReg(30, HRcFlt64, False); }
HReg hregPPC32_FPR31 ( void ) { return mkHReg(31, HRcFlt64, False); }

void getAllocableRegs_PPC32 ( Int* nregs, HReg** arr )
{
   *nregs = 59;
   *arr = LibVEX_Alloc(*nregs * sizeof(HReg));
   // GPR0 = scratch reg where possible - some ops interpret as value zero
   // GPR1 = stack pointer
   // GPR2 = TOC pointer
   (*arr)[ 0] = hregPPC32_GPR3();
   (*arr)[ 1] = hregPPC32_GPR4();
   (*arr)[ 2] = hregPPC32_GPR5();
   (*arr)[ 3] = hregPPC32_GPR6();
   (*arr)[ 4] = hregPPC32_GPR7();
   (*arr)[ 5] = hregPPC32_GPR8();
   (*arr)[ 6] = hregPPC32_GPR9();
   (*arr)[ 7] = hregPPC32_GPR10();
   (*arr)[ 8] = hregPPC32_GPR11();
   (*arr)[ 9] = hregPPC32_GPR12();
   // GPR13 = thread specific pointer
   (*arr)[10] = hregPPC32_GPR14();
   (*arr)[11] = hregPPC32_GPR15();
   (*arr)[12] = hregPPC32_GPR16();
   (*arr)[13] = hregPPC32_GPR17();
   (*arr)[14] = hregPPC32_GPR18();
   (*arr)[15] = hregPPC32_GPR19();
   (*arr)[16] = hregPPC32_GPR20();
   (*arr)[17] = hregPPC32_GPR21();
   (*arr)[18] = hregPPC32_GPR22();
   (*arr)[19] = hregPPC32_GPR23();
   (*arr)[20] = hregPPC32_GPR24();
   (*arr)[21] = hregPPC32_GPR25();
   (*arr)[22] = hregPPC32_GPR26();
   (*arr)[23] = hregPPC32_GPR27();
   (*arr)[24] = hregPPC32_GPR28();
   (*arr)[25] = hregPPC32_GPR29();
   (*arr)[26] = hregPPC32_GPR30();
   // GPR31 = GuestStatePtr

   (*arr)[27] = hregPPC32_FPR0();
   (*arr)[28] = hregPPC32_FPR1();
   (*arr)[29] = hregPPC32_FPR2();
   (*arr)[30] = hregPPC32_FPR3();
   (*arr)[31] = hregPPC32_FPR4();
   (*arr)[32] = hregPPC32_FPR5();
   (*arr)[33] = hregPPC32_FPR6();
   (*arr)[34] = hregPPC32_FPR7();
   (*arr)[35] = hregPPC32_FPR8();
   (*arr)[36] = hregPPC32_FPR9();
   (*arr)[37] = hregPPC32_FPR10();
   (*arr)[38] = hregPPC32_FPR11();
   (*arr)[39] = hregPPC32_FPR12();
   (*arr)[40] = hregPPC32_FPR13();
   (*arr)[41] = hregPPC32_FPR14();
   (*arr)[42] = hregPPC32_FPR15();
   (*arr)[43] = hregPPC32_FPR16();
   (*arr)[44] = hregPPC32_FPR17();
   (*arr)[45] = hregPPC32_FPR18();
   (*arr)[46] = hregPPC32_FPR19();
   (*arr)[47] = hregPPC32_FPR20();
   (*arr)[48] = hregPPC32_FPR21();
   (*arr)[49] = hregPPC32_FPR22();
   (*arr)[50] = hregPPC32_FPR23();
   (*arr)[51] = hregPPC32_FPR24();
   (*arr)[52] = hregPPC32_FPR25();
   (*arr)[53] = hregPPC32_FPR26();
   (*arr)[54] = hregPPC32_FPR27();
   (*arr)[55] = hregPPC32_FPR28();
   (*arr)[56] = hregPPC32_FPR29();
   (*arr)[57] = hregPPC32_FPR30();
   (*arr)[58] = hregPPC32_FPR31();
}


/* --------- Condition codes, Intel encoding. --------- */

HChar* showPPC32CondCode ( PPC32CondCode cond )
{
   if (cond.test == Pct_ALWAYS) return "always";

   switch (cond.flag) {
   case Pcf_SO:  return (cond.test == Pct_TRUE) ? "so=1" : "so=0";
   case Pcf_EQ:  return (cond.test == Pct_TRUE) ? "eq=1" : "eq=0";
   case Pcf_GT:  return (cond.test == Pct_TRUE) ? "gt=1" : "gt=0";
   case Pcf_LT:  return (cond.test == Pct_TRUE) ? "lt=1" : "lt=0";
   default: vpanic("ppPPC32CondCode");
   }
}

/* construct condition code */
PPC32CondCode mk_PPCCondCode ( PPC32CondTest test, PPC32CondFlag flag )
{
   PPC32CondCode cc;
   cc.flag = flag;
   cc.test = test;
   return cc;
}

/* false->true, true->false */
PPC32CondTest invertCondTest ( PPC32CondTest ct )
{
   vassert(ct != Pct_ALWAYS);
   return (ct == Pct_TRUE) ? Pct_FALSE : Pct_TRUE;
}


/* --------- PPCAMode: memory address expressions. --------- */

PPC32AMode* PPC32AMode_IR ( UInt idx, HReg base ) {
   PPC32AMode* am = LibVEX_Alloc(sizeof(PPC32AMode));
   vassert(idx < 0x10000);
   am->tag = Pam_IR;
   am->Pam.IR.base = base;
   am->Pam.IR.index = idx;
   return am;
}
PPC32AMode* PPC32AMode_RR ( HReg idx, HReg base ) {
   PPC32AMode* am = LibVEX_Alloc(sizeof(PPC32AMode));
   am->tag = Pam_RR;
   am->Pam.RR.base = base;
   am->Pam.RR.index = idx;
   return am;
}

PPC32AMode* dopyPPC32AMode ( PPC32AMode* am ) {
   switch (am->tag) {
   case Pam_IR: 
      return PPC32AMode_IR( am->Pam.IR.index, am->Pam.IR.base );
   case Pam_RR: 
      return PPC32AMode_RR( am->Pam.RR.index, am->Pam.RR.base );
   default:
      vpanic("dopyPPC32AMode");
   }
}

void ppPPC32AMode ( PPC32AMode* am ) {
   switch (am->tag) {
   case Pam_IR: 
      if (am->Pam.IR.index == 0)
         vex_printf("0(");
      else
         vex_printf("0x%x(", am->Pam.IR.index);
      ppHRegPPC32(am->Pam.IR.base);
      vex_printf(")");
      return;
   case Pam_RR:
      ppHRegPPC32(am->Pam.RR.base);
      vex_printf(",");
      ppHRegPPC32(am->Pam.RR.index);
      return;
   default:
      vpanic("ppPPC32AMode");
   }
}

static void addRegUsage_PPC32AMode ( HRegUsage* u, PPC32AMode* am ) {
   switch (am->tag) {
   case Pam_IR: 
      addHRegUse(u, HRmRead, am->Pam.IR.base);
      return;
   case Pam_RR:
      addHRegUse(u, HRmRead, am->Pam.RR.base);
      addHRegUse(u, HRmRead, am->Pam.RR.index);
      return;
   default:
      vpanic("addRegUsage_PPC32AMode");
   }
}

static void mapRegs_PPC32AMode ( HRegRemap* m, PPC32AMode* am ) {
   switch (am->tag) {
   case Pam_IR: 
      am->Pam.IR.base = lookupHRegRemap(m, am->Pam.IR.base);
      return;
   case Pam_RR:
      am->Pam.RR.base = lookupHRegRemap(m, am->Pam.RR.base);
      am->Pam.RR.index = lookupHRegRemap(m, am->Pam.RR.index);
      return;
   default:
      vpanic("mapRegs_PPC32AMode");
   }
}

/* --------- Operand, which can be reg or immediate only. --------- */

PPC32RI* PPC32RI_Imm ( UInt imm32 ) {
   PPC32RI* op       = LibVEX_Alloc(sizeof(PPC32RI));
   op->tag           = Pri_Imm;
   op->Pri.Imm.imm32 = imm32;
   return op;
}
PPC32RI* PPC32RI_Reg ( HReg reg ) {
   PPC32RI* op     = LibVEX_Alloc(sizeof(PPC32RI));
   op->tag         = Pri_Reg;
   op->Pri.Reg.reg = reg;
   return op;
}

void ppPPC32RI ( PPC32RI* op ) {
   switch (op->tag) {
   case Pri_Imm: 
      vex_printf("$0x%x", op->Pri.Imm.imm32);
      return;
   case Pri_Reg: 
      ppHRegPPC32(op->Pri.Reg.reg);
      return;
   default: 
      vpanic("ppPPC32RI");
   }
}

/* An PPC32RI can only be used in a "read" context (what would it mean
   to write or modify a literal?) and so we enumerate its registers
   accordingly. */
static void addRegUsage_PPC32RI ( HRegUsage* u, PPC32RI* op ) {
   switch (op->tag) {
   case Pri_Imm: 
      return;
   case Pri_Reg: 
      addHRegUse(u, HRmRead, op->Pri.Reg.reg);
      return;
   default: 
      vpanic("addRegUsage_PPC32RI");
   }
}

static void mapRegs_PPC32RI ( HRegRemap* m, PPC32RI* op ) {
   switch (op->tag) {
   case Pri_Imm: 
      return;
   case Pri_Reg: 
      op->Pri.Reg.reg = lookupHRegRemap(m, op->Pri.Reg.reg);
      return;
   default: 
      vpanic("mapRegs_PPC32RI");
   }
}

/* --------- Instructions. --------- */

//.. HChar* showX86ScalarSz ( X86ScalarSz sz ) {
//..    switch (sz) {
//..       case Xss_16: return "w";
//..       case Xss_32: return "l";
//..       default: vpanic("showX86ScalarSz");
//..    }
//.. }

HChar* showPPC32UnaryOp ( PPC32UnaryOp op ) {
   switch (op) {
   case Pun_NOT: return "not";
   case Pun_NEG: return "neg";
   case Pun_CLZ: return "cntlzw";
   default: vpanic("showPPC32UnaryOp");
   }
}

HChar* showPPC32AluOp ( PPC32AluOp op ) {
   switch (op) {
   case Palu_ADD:  return "add";
//   case Palu_ADC:  return "adc";
//   case Palu_SBB:  return "sbb";
   case Palu_AND:  return "and";
   case Palu_OR:   return "or";
   case Palu_XOR:  return "xor";
   default: vpanic("showPPC32AluOp");
   }
}

HChar* showPPC32ShiftOp ( PPC32ShiftOp op ) {
   switch (op) {
   case Psh_SHL: return "slw";
   case Psh_SHR: return "srw";
   case Psh_SAR: return "sraw";
   case Psh_ROL: return "rlw";
   default: vpanic("showPPC32ShiftOp");
   }
}

HChar* showPPC32CmpOp ( PPC32CmpOp op ) {
   switch (op) {
   case Pcmp_U: return "cmpl";
   case Pcmp_S: return "cmp";
   default: vpanic("showPPC32CmpOp");
   }
}

HChar* showPPC32FpOp ( PPC32FpOp op ) {
   switch (op) {
      case Pfp_ADD:    return "fadd";
      case Pfp_SUB:    return "fsub";
      case Pfp_MUL:    return "fmul";
      case Pfp_DIV:    return "fdiv";
      case Pfp_SQRT:   return "fsqrt";
      case Pfp_ABS:    return "fabs";
      case Pfp_NEG:    return "fneg";
      case Pfp_MOV:    return "fmr";
      default: vpanic("showPPC32FpOp");
   }
}

PPC32Instr* PPC32Instr_Alu32 ( PPC32AluOp op, HReg dst, HReg srcL, PPC32RI* srcR ) {
   PPC32Instr* i     = LibVEX_Alloc(sizeof(PPC32Instr));
   if (srcR->tag == Pri_Imm)
      vassert(srcR->Pri.Imm.imm32 < 0x10000);
   i->tag            = Pin_Alu32;
   i->Pin.Alu32.op   = op;
   i->Pin.Alu32.dst  = dst;
   i->Pin.Alu32.srcL = srcL;
   i->Pin.Alu32.srcR = srcR;
   return i;
}
PPC32Instr* PPC32Instr_Sub32 ( HReg dst, PPC32RI* srcL, HReg srcR ) {
   PPC32Instr* i     = LibVEX_Alloc(sizeof(PPC32Instr));
   if (srcL->tag == Pri_Imm)
      vassert(srcL->Pri.Imm.imm32 < 0x10000);
   i->tag            = Pin_Sub32;
   i->Pin.Sub32.dst  = dst;
   i->Pin.Sub32.srcL = srcL;
   i->Pin.Sub32.srcR = srcR;
   return i;
}
PPC32Instr* PPC32Instr_Sh32 ( PPC32ShiftOp op, HReg dst, HReg src, PPC32RI* shft ) {
   PPC32Instr* i    = LibVEX_Alloc(sizeof(PPC32Instr));
   if (op == Psh_SHL || op == Psh_SHR)  // No imm versions for these.
      vassert(shft->tag == Pri_Reg);
   if (shft->tag == Pri_Imm)
      vassert(shft->Pri.Imm.imm32 < 32);
   i->tag           = Pin_Sh32;
   i->Pin.Sh32.op   = op;
   i->Pin.Sh32.dst  = dst;
   i->Pin.Sh32.src  = src;
   i->Pin.Sh32.shft = shft;
   return i;
}
PPC32Instr* PPC32Instr_Cmp32 ( PPC32CmpOp op, UInt crfD, HReg srcL, PPC32RI* srcR ) {
   PPC32Instr* i     = LibVEX_Alloc(sizeof(PPC32Instr));
   if (srcR->tag == Pri_Imm)
      vassert(srcR->Pri.Imm.imm32 < 0x10000);
   i->tag            = Pin_Cmp32;
   i->Pin.Cmp32.op   = op;
   i->Pin.Cmp32.crfD = crfD;
   i->Pin.Cmp32.srcL = srcL;
   i->Pin.Cmp32.srcR = srcR;
   return i;
}
PPC32Instr* PPC32Instr_Unary32  ( PPC32UnaryOp op, HReg dst, HReg src ) {
   PPC32Instr* i      = LibVEX_Alloc(sizeof(PPC32Instr));
   i->tag             = Pin_Unary32;
   i->Pin.Unary32.op  = op;
   i->Pin.Unary32.dst = dst;
   i->Pin.Unary32.src = src;
   return i;
}
PPC32Instr* PPC32Instr_MulL ( Bool syned, Bool word, HReg dst,
                              HReg srcL, PPC32RI* srcR ) {
   PPC32Instr* i     = LibVEX_Alloc(sizeof(PPC32Instr));
   if (word == 1) { // high
      vassert(srcR->tag == Pri_Reg);
   } else {         // low
      if (srcR->tag == Pri_Imm) {
         vassert(syned == True);
         vassert(srcR->Pri.Imm.imm32 < 0x10000);
      }
   }
   i->tag            = Pin_MulL;
   i->Pin.MulL.syned = syned;
   i->Pin.MulL.word  = word;
   i->Pin.MulL.dst   = dst;
   i->Pin.MulL.srcL  = srcL;
   i->Pin.MulL.srcR  = srcR;
   return i;
}
PPC32Instr* PPC32Instr_Div ( Bool syned, HReg dst, HReg srcL, HReg srcR ) {
   PPC32Instr* i      = LibVEX_Alloc(sizeof(PPC32Instr));
   i->tag             = Pin_Div;
   i->Pin.Div.syned   = syned;
   i->Pin.Div.dst     = dst;
   i->Pin.Div.srcL    = srcL;
   i->Pin.Div.srcR    = srcR;
   return i;
}
PPC32Instr* PPC32Instr_Call ( PPC32CondCode cond, Addr32 target, Int regparms ) {
   PPC32Instr* i        = LibVEX_Alloc(sizeof(PPC32Instr));
   i->tag               = Pin_Call;
   i->Pin.Call.cond     = cond;
   i->Pin.Call.target   = target;
   i->Pin.Call.regparms = regparms;
   vassert(regparms >= 0 && regparms < PPC32_N_REGPARMS);
   return i;
}
PPC32Instr* PPC32Instr_Goto ( IRJumpKind jk, PPC32CondCode cond, PPC32RI* dst ) {
   PPC32Instr* i    = LibVEX_Alloc(sizeof(PPC32Instr));
   i->tag           = Pin_Goto;
   i->Pin.Goto.cond = cond;
   i->Pin.Goto.dst  = dst;
   i->Pin.Goto.jk   = jk;
   return i;
}
PPC32Instr* PPC32Instr_CMov32  ( PPC32CondCode cond, HReg dst, PPC32RI* src ) {
   PPC32Instr* i      = LibVEX_Alloc(sizeof(PPC32Instr));
   i->tag             = Pin_CMov32;
   i->Pin.CMov32.cond = cond;
   i->Pin.CMov32.src  = src;
   i->Pin.CMov32.dst  = dst;
   vassert(cond.test != Pct_ALWAYS);
   return i;
}
PPC32Instr* PPC32Instr_Load ( UChar sz, Bool syned,
                              HReg dst, PPC32AMode* src ) {
   PPC32Instr* i     = LibVEX_Alloc(sizeof(PPC32Instr));
   i->tag            = Pin_Load;
   i->Pin.Load.sz    = sz;
   i->Pin.Load.syned = syned;
   i->Pin.Load.src   = src;
   i->Pin.Load.dst   = dst;
   vassert(sz == 1 || sz == 2 || sz == 4);
   return i;
}
PPC32Instr* PPC32Instr_Store ( UChar sz, PPC32AMode* dst, HReg src ) {
   PPC32Instr* i    = LibVEX_Alloc(sizeof(PPC32Instr));
   i->tag           = Pin_Store;
   i->Pin.Store.sz  = sz;
   i->Pin.Store.src = src;
   i->Pin.Store.dst = dst;
   vassert(sz == 1 || sz == 2 || sz == 4);
   return i;
}
PPC32Instr* PPC32Instr_Set32 ( PPC32CondCode cond, HReg dst ) {
   PPC32Instr* i     = LibVEX_Alloc(sizeof(PPC32Instr));
   i->tag            = Pin_Set32;
   i->Pin.Set32.cond = cond;
   i->Pin.Set32.dst  = dst;
   return i;
}
PPC32Instr* PPC32Instr_MFence ( void )
{
   PPC32Instr* i         = LibVEX_Alloc(sizeof(PPC32Instr));
   i->tag                = Pin_MFence;
   return i;
}

PPC32Instr* PPC32Instr_FpUnary ( PPC32FpOp op, HReg dst, HReg src ) {
   PPC32Instr* i      = LibVEX_Alloc(sizeof(PPC32Instr));
   i->tag             = Pin_FpUnary;
   i->Pin.FpUnary.op  = op;
   i->Pin.FpUnary.dst = dst;
   i->Pin.FpUnary.src = src;
   return i;
}
PPC32Instr* PPC32Instr_FpBinary ( PPC32FpOp op, HReg dst, HReg srcL, HReg srcR ) {
   PPC32Instr* i        = LibVEX_Alloc(sizeof(PPC32Instr));
   i->tag               = Pin_FpBinary;
   i->Pin.FpBinary.op   = op;
   i->Pin.FpBinary.dst  = dst;
   i->Pin.FpBinary.srcL = srcL;
   i->Pin.FpBinary.srcR = srcR;
   return i;
}
PPC32Instr* PPC32Instr_FpLdSt ( Bool isLoad, UChar sz, HReg reg, PPC32AMode* addr ) {
   PPC32Instr* i        = LibVEX_Alloc(sizeof(PPC32Instr));
   i->tag               = Pin_FpLdSt;
   i->Pin.FpLdSt.isLoad = isLoad;
   i->Pin.FpLdSt.sz     = sz;
   i->Pin.FpLdSt.reg    = reg;
   i->Pin.FpLdSt.addr   = addr;
   vassert(sz == 4 || sz == 8);
   return i;
}
PPC32Instr* PPC32Instr_FpF64toF32 ( HReg dst, HReg src ) {
   PPC32Instr* i         = LibVEX_Alloc(sizeof(PPC32Instr));
   i->tag                = Pin_FpF64toF32;
   i->Pin.FpF64toF32.dst = dst;
   i->Pin.FpF64toF32.src = src;
   return i;
}
PPC32Instr* PPC32Instr_FpF64toI32 ( HReg dst, HReg src ) {
   PPC32Instr* i         = LibVEX_Alloc(sizeof(PPC32Instr));
   i->tag                = Pin_FpF64toI32;
   i->Pin.FpF64toI32.dst = dst;
   i->Pin.FpF64toI32.src = src;
   return i;
}
PPC32Instr* PPC32Instr_FpCMov ( PPC32CondCode cond, HReg dst, HReg src ) {
   PPC32Instr* i      = LibVEX_Alloc(sizeof(PPC32Instr));
   i->tag             = Pin_FpCMov;
   i->Pin.FpCMov.cond = cond;
   i->Pin.FpCMov.dst  = dst;
   i->Pin.FpCMov.src  = src;
   vassert(cond.test != Pct_ALWAYS);
   return i;
}
PPC32Instr* PPC32Instr_FpLdFPSCR ( HReg src ) {
   PPC32Instr* i        = LibVEX_Alloc(sizeof(PPC32Instr));
   i->tag               = Pin_FpLdFPSCR;
   i->Pin.FpLdFPSCR.src = src;
   return i;
}
PPC32Instr* PPC32Instr_FpCmp ( HReg dst, HReg srcL, HReg srcR ) {
   PPC32Instr* i     = LibVEX_Alloc(sizeof(PPC32Instr));
   i->tag            = Pin_FpCmp;
   i->Pin.FpCmp.dst  = dst;
   i->Pin.FpCmp.srcL = srcL;
   i->Pin.FpCmp.srcR = srcR;
   return i;
}

/* Read/Write Link Register */
PPC32Instr* PPC32Instr_RdWrLR ( Bool wrLR, HReg gpr )
{
   PPC32Instr* i      = LibVEX_Alloc(sizeof(PPC32Instr));
   i->tag             = Pin_RdWrLR;
   i->Pin.RdWrLR.wrLR = wrLR;
   i->Pin.RdWrLR.gpr  = gpr;
   return i;
}


/* Pretty Print instructions */
static void ppLoadImm ( HReg dst, UInt imm ) {
   if (imm < 0x10000) {
      vex_printf("li ");
      ppHRegPPC32(dst);
      vex_printf(",0x%x", imm);
   } else {
      vex_printf("lis ");
      ppHRegPPC32(dst);
      vex_printf(",0x%x ; ", imm >> 16);
      vex_printf("ori ");
      ppHRegPPC32(dst);
      vex_printf(",");
      ppHRegPPC32(dst);
      vex_printf(",0x%x", imm & 0xFFFF);
   }
}

static void ppMovReg ( HReg dst, HReg src ) {
   if (hregNumber(dst) != hregNumber(src)) {
      vex_printf("mr ");
      ppHRegPPC32(dst);
      vex_printf(",");
      ppHRegPPC32(src);
   }
}

void ppPPC32Instr ( PPC32Instr* i )
{
   switch (i->tag) {
   case Pin_Alu32:
      if (i->Pin.Alu32.op == Palu_OR &&     // or Rd,Rs,Rs == mr Rd,Rs
          i->Pin.Alu32.srcR->tag == Pri_Reg &&
          i->Pin.Alu32.srcR->Pri.Reg.reg == i->Pin.Alu32.srcL) {
         vex_printf("mr ");
         ppHRegPPC32(i->Pin.Alu32.dst);
         vex_printf(",");
         ppHRegPPC32(i->Pin.Alu32.srcL);
         return;
      }
      if (i->Pin.Alu32.op == Palu_ADD &&     // add rD,r0,val == li rD,val
          i->Pin.Alu32.srcL == hregPPC32_GPR0() &&
          i->Pin.Alu32.srcR->tag == Pri_Imm) {
         vex_printf("li ");
         ppHRegPPC32(i->Pin.Alu32.dst);
         vex_printf(",");
         ppPPC32RI(i->Pin.Alu32.srcR);
         return;
      }
      if (i->Pin.Alu32.op == Palu_AND &&     // 'andi.' - always has the '.'
          i->Pin.Alu32.srcR->tag == Pri_Imm) {
         vex_printf("andi. ");
         ppHRegPPC32(i->Pin.Alu32.dst);
         vex_printf(",");
         ppHRegPPC32(i->Pin.Alu32.srcL);
         vex_printf(",");
         ppPPC32RI(i->Pin.Alu32.srcR);
         return;
      }
      vex_printf("%s%s ", showPPC32AluOp(i->Pin.Alu32.op),
                 i->Pin.Alu32.srcR->tag == Pri_Imm ? "i" : "" );
      ppHRegPPC32(i->Pin.Alu32.dst);
      vex_printf(",");
      ppHRegPPC32(i->Pin.Alu32.srcL);
      vex_printf(",");
      ppPPC32RI(i->Pin.Alu32.srcR);
      return;
   case Pin_Sub32:
      vex_printf("subf%s ", i->Pin.Sub32.srcL->tag == Pri_Imm ? "ic" : "" );
      ppHRegPPC32(i->Pin.Sub32.dst);
      vex_printf(",");
      ppHRegPPC32(i->Pin.Sub32.srcR); // yes, order is right :-)
      vex_printf(",");
      ppPPC32RI(i->Pin.Sub32.srcL);
      return;
   case Pin_Sh32:
      vex_printf("%s%s ", showPPC32ShiftOp(i->Pin.Sh32.op),
                 i->Pin.Sh32.shft->tag == Pri_Imm ? "i" : "" );
      ppHRegPPC32(i->Pin.Sh32.dst);
      vex_printf(",");
      ppHRegPPC32(i->Pin.Sh32.src);
      vex_printf(",");
      ppPPC32RI(i->Pin.Sh32.shft);
      return;
   case Pin_Cmp32:
      vex_printf("%s%s %%crf%u,", showPPC32CmpOp(i->Pin.Cmp32.op),
                 i->Pin.Cmp32.srcR->tag == Pri_Imm ? "i" : "",
                 (7 - i->Pin.Cmp32.crfD));
      ppHRegPPC32(i->Pin.Cmp32.srcL);
      vex_printf(",");
      ppPPC32RI(i->Pin.Cmp32.srcR);
      return;
   case Pin_Unary32:
      vex_printf("%s ", showPPC32UnaryOp(i->Pin.Unary32.op));
      ppHRegPPC32(i->Pin.Unary32.dst);
      vex_printf(",");
      ppHRegPPC32(i->Pin.Unary32.src);
      return;
   case Pin_MulL:
      if (i->Pin.MulL.srcR->tag == Pri_Imm) {
         vex_printf("mulli ");
      } else {
         vex_printf("mul%s%c ",
                    i->Pin.MulL.word ? "hw" : "lw",
                    i->Pin.MulL.syned ? 's' : 'u');
      }
      ppHRegPPC32(i->Pin.MulL.dst);
      vex_printf(",");
      ppHRegPPC32(i->Pin.MulL.srcL);
      vex_printf(",");
      ppPPC32RI(i->Pin.MulL.srcR);
      return;
   case Pin_Div:
      vex_printf("divw%s ",
                 i->Pin.Div.syned ? "" : "u");
      ppHRegPPC32(i->Pin.Div.dst);
      vex_printf(",");
      ppHRegPPC32(i->Pin.Div.srcL);
      vex_printf(",");
      ppHRegPPC32(i->Pin.Div.srcR);
      return;
   case Pin_Call:
      vex_printf("call: ");
      if (i->Pin.Call.cond.test != Pct_ALWAYS) {
         vex_printf("if (%%crf0.%s) ", showPPC32CondCode(i->Pin.Call.cond));
      }
      vex_printf("{ ");
      ppLoadImm(hregPPC32_GPR12(), i->Pin.Call.target);
      vex_printf(" ; mtctr r12 ; bctrl [regparms=%d] }",i->Pin.Call.regparms);
      break;
   case Pin_Goto:
      vex_printf("goto: ");
      if (i->Pin.Goto.cond.test != Pct_ALWAYS) {
         vex_printf("if (%%crf0.%s) ", showPPC32CondCode(i->Pin.Goto.cond));
      }
      vex_printf("{ ");
      if (i->Pin.Goto.jk != Ijk_Boring) {
         vex_printf("li %%r31,$");
         ppIRJumpKind(i->Pin.Goto.jk);
         vex_printf(" ; ");
      }
      if (i->Pin.Goto.dst->tag == Pri_Imm) {
         ppLoadImm(hregPPC32_GPR3(), i->Pin.Goto.dst->Pri.Imm.imm32);
      } else {
         ppMovReg(hregPPC32_GPR3(), i->Pin.Goto.dst->Pri.Reg.reg);
      }
      vex_printf(" ; blr }");
      return;
   case Pin_CMov32:
      vex_printf("cmov32 (%s) ", showPPC32CondCode(i->Pin.CMov32.cond));
      ppHRegPPC32(i->Pin.CMov32.dst);
      vex_printf(",");
      ppPPC32RI(i->Pin.CMov32.src);
      vex_printf(": ");
      if (i->Pin.CMov32.cond.test != Pct_ALWAYS) {
         vex_printf("if (%%crf0.%s) ", showPPC32CondCode(i->Pin.CMov32.cond));
      }
      vex_printf("{ ");
      if (i->Pin.CMov32.src->tag == Pri_Imm) {
         ppLoadImm(i->Pin.CMov32.dst, i->Pin.CMov32.src->Pri.Imm.imm32);
      } else {
         ppMovReg(i->Pin.CMov32.dst, i->Pin.CMov32.src->Pri.Reg.reg);
      }
      vex_printf(" }");
      return;
   case Pin_Load: {
      UChar sz = i->Pin.Load.sz;
      Bool syned = i->Pin.Load.syned;
      Bool idxd = toBool(i->Pin.Load.src->tag == Pam_RR);
      vex_printf("l%c%c%s ",
                 (sz==1) ? 'b' : (sz==2 ? 'h' : 'w'),
                 syned ? 'a' : 'z',
                 idxd ? "x" : "" );
      ppHRegPPC32(i->Pin.Load.dst);
      vex_printf(",");
      ppPPC32AMode(i->Pin.Load.src);
      return;
   }
   case Pin_Store: {
      UChar sz = i->Pin.Store.sz;
      Bool idxd = toBool(i->Pin.Store.dst->tag == Pam_RR);
      vex_printf("st%c%s ",
                 (sz==1) ? 'b' : (sz==2 ? 'h' : 'w'),
                 idxd ? "x" : "" );
      ppHRegPPC32(i->Pin.Store.src);
      vex_printf(",");
      ppPPC32AMode(i->Pin.Store.dst);
      return;
   }
   case Pin_Set32: {
      PPC32CondCode cc = i->Pin.Set32.cond;
      vex_printf("set32 (%s),", showPPC32CondCode(cc));
      ppHRegPPC32(i->Pin.Set32.dst);
      if (cc.test == Pct_ALWAYS) {
         vex_printf(": { li ");
         ppHRegPPC32(i->Pin.Set32.dst);
         vex_printf(",1 }");
      } else {
         vex_printf(": { mfcr r0 ; rlwinm ");
         ppHRegPPC32(i->Pin.Set32.dst);
         vex_printf(",r0,%u,31,31", cc.flag+1);
         if (cc.test == Pct_FALSE) {
            vex_printf("; xori ");
            ppHRegPPC32(i->Pin.Set32.dst);
            vex_printf(",");
            ppHRegPPC32(i->Pin.Set32.dst);
            vex_printf("1");
         }
         vex_printf(" }");
      }
      return;
   }
   case Pin_MFence:
      vex_printf("mfence (=sync)");
      return;

   case Pin_FpUnary:
      vex_printf("%s ", showPPC32FpOp(i->Pin.FpUnary.op));
      ppHRegPPC32(i->Pin.FpUnary.dst);
      vex_printf(",");
      ppHRegPPC32(i->Pin.FpUnary.src);
      return;
   case Pin_FpBinary:
      vex_printf("%s ", showPPC32FpOp(i->Pin.FpBinary.op));
      ppHRegPPC32(i->Pin.FpBinary.dst);
      vex_printf(",");
      ppHRegPPC32(i->Pin.FpBinary.srcL);
      vex_printf(",");
      ppHRegPPC32(i->Pin.FpBinary.srcR);
      return;
   case Pin_FpLdSt: {
      UChar sz = i->Pin.FpLdSt.sz;
      Bool idxd = toBool(i->Pin.FpLdSt.addr->tag == Pam_RR);
      if (i->Pin.FpLdSt.isLoad) {
         vex_printf("lf%c%s ",
                    (sz==4 ? 's' : 'd'),
                    idxd ? "x" : "" );
         ppHRegPPC32(i->Pin.FpLdSt.reg);
         vex_printf(",");
         ppPPC32AMode(i->Pin.FpLdSt.addr);
      } else {
         vex_printf("stf%c%s ",
                    (sz==4 ? 's' : 'd'),
                    idxd ? "x" : "" );
         ppHRegPPC32(i->Pin.FpLdSt.reg);
         vex_printf(",");
         ppPPC32AMode(i->Pin.FpLdSt.addr);
      }
      return;
   }
   case Pin_FpF64toF32:
      vex_printf("frsp ");
      ppHRegPPC32(i->Pin.FpF64toF32.dst);
      vex_printf(",");
      ppHRegPPC32(i->Pin.FpF64toF32.src);
      return;
   case Pin_FpF64toI32:
      vex_printf("fctiw %%fr7,");
      ppHRegPPC32(i->Pin.FpF64toI32.src);
      vex_printf("; stfiwx %%fr7,%%r0,%%r1");
      vex_printf("; lwzx ");
      ppHRegPPC32(i->Pin.FpF64toI32.dst);
      vex_printf(",%%r0,%%r1");
      return;
   case Pin_FpCMov:
      vex_printf("fpcmov (%s) ", showPPC32CondCode(i->Pin.FpCMov.cond));
      ppHRegPPC32(i->Pin.FpCMov.dst);
      vex_printf(",");
      ppHRegPPC32(i->Pin.FpCMov.src);
      vex_printf(": ");
      vex_printf("if (fr_dst != fr_src) { ");
      if (i->Pin.FpCMov.cond.test != Pct_ALWAYS) {
         vex_printf("if (%%crf0.%s) { ", showPPC32CondCode(i->Pin.FpCMov.cond));
      }
      vex_printf("fmr ");
      ppHRegPPC32(i->Pin.FpCMov.dst);
      vex_printf(",");
      ppHRegPPC32(i->Pin.FpCMov.src);
      if (i->Pin.FpCMov.cond.test != Pct_ALWAYS)
         vex_printf(" }");
      vex_printf(" }");
      return;
   case Pin_FpLdFPSCR:
      vex_printf("mtfsf 0xFF,");
      ppHRegPPC32(i->Pin.FpLdFPSCR.src);
      return;
   case Pin_FpCmp:
      vex_printf("fcmpo %%crf1,");
      ppHRegPPC32(i->Pin.FpCmp.srcL);
      vex_printf(",");
      ppHRegPPC32(i->Pin.FpCmp.srcR);
      vex_printf("; mfcr ");
      ppHRegPPC32(i->Pin.FpCmp.dst);
      vex_printf("; rlwinm ");
      ppHRegPPC32(i->Pin.FpCmp.dst);
      vex_printf(",");
      ppHRegPPC32(i->Pin.FpCmp.dst);
      vex_printf(",8,28,31");
      return;

   case Pin_RdWrLR:
      vex_printf("%s ", i->Pin.RdWrLR.wrLR ? "mtlr" : "mflr");
      ppHRegPPC32(i->Pin.RdWrLR.gpr);
      return;

   default:
      vex_printf("\nppPPC32Instr(ppc32): No such tag(%d)\n", (Int)i->tag);
      vpanic("ppPPC32Instr(ppc32)");
   }
}

/* --------- Helpers for register allocation. --------- */

void getRegUsage_PPC32Instr ( HRegUsage* u, PPC32Instr* i )
{
//   Bool unary;
   initHRegUsage(u);
   switch (i->tag) {
   case Pin_Alu32:
      addHRegUse(u, HRmRead, i->Pin.Alu32.srcL);
      addRegUsage_PPC32RI(u, i->Pin.Alu32.srcR);
      addHRegUse(u, HRmWrite, i->Pin.Alu32.dst);
      return;

   case Pin_Sub32:
      addRegUsage_PPC32RI(u, i->Pin.Sub32.srcL);
      addHRegUse(u, HRmRead, i->Pin.Sub32.srcR);
      addHRegUse(u, HRmWrite, i->Pin.Sub32.dst);
      return;

   case Pin_Sh32:
      addHRegUse(u, HRmWrite, i->Pin.Sh32.dst);
      addHRegUse(u, HRmRead, i->Pin.Sh32.src);
      addRegUsage_PPC32RI(u, i->Pin.Sh32.shft);
      return;
      
   case Pin_Cmp32:
      addHRegUse(u, HRmRead, i->Pin.Cmp32.srcL);
      addRegUsage_PPC32RI(u, i->Pin.Cmp32.srcR);
      return;

   case Pin_Unary32:
      addHRegUse(u, HRmWrite, i->Pin.Unary32.dst);
      addHRegUse(u, HRmRead, i->Pin.Unary32.src);
      return;
   case Pin_MulL:
      addHRegUse(u, HRmWrite, i->Pin.MulL.dst);
      addHRegUse(u, HRmRead, i->Pin.MulL.srcL);
      addRegUsage_PPC32RI(u, i->Pin.MulL.srcR);
      return;
   case Pin_Div:
      addHRegUse(u, HRmWrite, i->Pin.Div.dst);
      addHRegUse(u, HRmRead, i->Pin.Div.srcL);
      addHRegUse(u, HRmRead, i->Pin.Div.srcR);
      return;
   case Pin_Call:
      /* This is a bit subtle. */
      /* First off, claim it trashes all the caller-saved regs
         which fall within the register allocator's jurisdiction.
         These I believe to be: r3:12
      */
      addHRegUse(u, HRmWrite, hregPPC32_GPR3());
      addHRegUse(u, HRmWrite, hregPPC32_GPR4());
      addHRegUse(u, HRmWrite, hregPPC32_GPR5());
      addHRegUse(u, HRmWrite, hregPPC32_GPR6());
      addHRegUse(u, HRmWrite, hregPPC32_GPR7());
      addHRegUse(u, HRmWrite, hregPPC32_GPR8());
      addHRegUse(u, HRmWrite, hregPPC32_GPR9());
      addHRegUse(u, HRmWrite, hregPPC32_GPR10());
      addHRegUse(u, HRmWrite, hregPPC32_GPR11());
      addHRegUse(u, HRmWrite, hregPPC32_GPR12());
      
      /* Now we have to state any parameter-carrying registers
         which might be read.  This depends on the regparmness. */
      switch (i->Pin.Call.regparms) {
      case  8: addHRegUse(u, HRmRead, hregPPC32_GPR10()); /*fallthru*/
      case  7: addHRegUse(u, HRmRead, hregPPC32_GPR9() ); /*fallthru*/
      case  6: addHRegUse(u, HRmRead, hregPPC32_GPR8() ); /*fallthru*/
      case  5: addHRegUse(u, HRmRead, hregPPC32_GPR7() ); /*fallthru*/
      case  4: addHRegUse(u, HRmRead, hregPPC32_GPR6() ); /*fallthru*/
      case  3: addHRegUse(u, HRmRead, hregPPC32_GPR5() ); /*fallthru*/
      case  2: addHRegUse(u, HRmRead, hregPPC32_GPR4() ); /*fallthru*/
      case  1: addHRegUse(u, HRmRead, hregPPC32_GPR3() ); /*fallthru*/
      case  0: break;
      default: vpanic("getRegUsage_PPC32Instr:Call:regparms");
      }
      /* Finally, there is the issue that the insn trashes a
         register because the literal target address has to be
         loaded into a register.  %r12 seems a suitable victim.
         (Can't use %r0, as use ops that interpret it as value zero).  */
      addHRegUse(u, HRmWrite, hregPPC32_GPR12());
      /* Upshot of this is that the assembler really must use %r12,
         and no other, as a destination temporary. */
      return;
   case Pin_Goto:
      addRegUsage_PPC32RI(u, i->Pin.Goto.dst);
      /* GPR3 holds destination address from Pin_Goto */
      addHRegUse(u, HRmWrite, hregPPC32_GPR3());
      if (i->Pin.Goto.jk != Ijk_Boring)
         addHRegUse(u, HRmWrite, GuestStatePtr);
      return;
   case Pin_CMov32:
      addRegUsage_PPC32RI(u, i->Pin.CMov32.src);
      addHRegUse(u, HRmWrite, i->Pin.CMov32.dst);
      return;
   case Pin_Load:
      addRegUsage_PPC32AMode(u, i->Pin.Load.src);
      addHRegUse(u, HRmWrite, i->Pin.Load.dst);
      return;
   case Pin_Store:
      addHRegUse(u, HRmRead, i->Pin.Store.src);
      addRegUsage_PPC32AMode(u, i->Pin.Store.dst);
      return;
   case Pin_Set32:
      addHRegUse(u, HRmWrite, i->Pin.Set32.dst);
      return;
   case Pin_MFence:
      return;

   case Pin_FpUnary:
      addHRegUse(u, HRmWrite, i->Pin.FpUnary.dst);
      addHRegUse(u, HRmRead,  i->Pin.FpUnary.src);
      return;
   case Pin_FpBinary:
      addHRegUse(u, HRmWrite, i->Pin.FpBinary.dst);
      addHRegUse(u, HRmRead,  i->Pin.FpBinary.srcL);
      addHRegUse(u, HRmRead,  i->Pin.FpBinary.srcR);
      return;
   case Pin_FpLdSt:
      addHRegUse(u, (i->Pin.FpLdSt.isLoad ? HRmWrite : HRmRead),
                 i->Pin.FpLdSt.reg);
      addRegUsage_PPC32AMode(u, i->Pin.FpLdSt.addr);
      return;
   case Pin_FpF64toF32:
      addHRegUse(u, HRmWrite, i->Pin.FpF64toF32.dst);
      addHRegUse(u, HRmRead,  i->Pin.FpF64toF32.src);
      return;
   case Pin_FpF64toI32:
      addHRegUse(u, HRmWrite,  i->Pin.FpF64toI32.dst);
      addHRegUse(u, HRmWrite, hregPPC32_FPR7());
      addHRegUse(u, HRmRead,   i->Pin.FpF64toI32.src);
      return;
   case Pin_FpCMov:
      addHRegUse(u, HRmModify, i->Pin.FpCMov.dst);
      addHRegUse(u, HRmRead, i->Pin.FpCMov.src);
      return;
   case Pin_FpLdFPSCR:
      addHRegUse(u, HRmRead, i->Pin.FpLdFPSCR.src);
      return;
   case Pin_FpCmp:
      addHRegUse(u, HRmWrite, i->Pin.FpCmp.dst);
      addHRegUse(u, HRmRead,   i->Pin.FpCmp.srcL);
      addHRegUse(u, HRmRead,   i->Pin.FpCmp.srcR);
      return;

   case Pin_RdWrLR:
      addHRegUse(u, (i->Pin.RdWrLR.wrLR ? HRmRead : HRmWrite),
                 i->Pin.RdWrLR.gpr);
      return;

   default:
      ppPPC32Instr(i);
      vpanic("getRegUsage_PPC32Instr");
   }
}

/* local helper */
static void mapReg(HRegRemap* m, HReg* r)
{
   *r = lookupHRegRemap(m, *r);
}

void mapRegs_PPC32Instr (HRegRemap* m, PPC32Instr* i)
{
   switch (i->tag) {
   case Pin_Alu32:
      mapReg(m, &i->Pin.Alu32.dst);
      mapReg(m, &i->Pin.Alu32.srcL);
      mapRegs_PPC32RI(m, i->Pin.Alu32.srcR);
      return;
   case Pin_Sub32:
      mapReg(m, &i->Pin.Sub32.dst);
      mapRegs_PPC32RI(m, i->Pin.Sub32.srcL);
      mapReg(m, &i->Pin.Sub32.srcR);
      return;
   case Pin_Sh32:
      mapReg(m, &i->Pin.Sh32.dst);
      mapReg(m, &i->Pin.Sh32.src);
      mapRegs_PPC32RI(m, i->Pin.Sh32.shft);
      return;
   case Pin_Cmp32:
      mapReg(m, &i->Pin.Cmp32.srcL);
      mapRegs_PPC32RI(m, i->Pin.Cmp32.srcR);
      return;
   case Pin_Unary32:
      mapReg(m, &i->Pin.Unary32.dst);
      mapReg(m, &i->Pin.Unary32.src);
      return;
   case Pin_MulL:
      mapReg(m, &i->Pin.MulL.dst);
      mapReg(m, &i->Pin.MulL.srcL);
      mapRegs_PPC32RI(m, i->Pin.MulL.srcR);
      return;
   case Pin_Div:
      mapReg(m, &i->Pin.Div.dst);
      mapReg(m, &i->Pin.Div.srcL);
      mapReg(m, &i->Pin.Div.srcR);
      return;
   case Pin_Call:
      return;
   case Pin_Goto:
      mapRegs_PPC32RI(m, i->Pin.Goto.dst);
      return;
   case Pin_CMov32:
      mapRegs_PPC32RI(m, i->Pin.CMov32.src);
      mapReg(m, &i->Pin.CMov32.dst);
      return;
   case Pin_Load:
      mapRegs_PPC32AMode(m, i->Pin.Load.src);
      mapReg(m, &i->Pin.Load.dst);
      return;
   case Pin_Store:
      mapReg(m, &i->Pin.Store.src);
      mapRegs_PPC32AMode(m, i->Pin.Store.dst);
      return;
   case Pin_Set32:
      mapReg(m, &i->Pin.Set32.dst);
      return;
   case Pin_MFence:
      return;

   case Pin_FpUnary:
         mapReg(m, &i->Pin.FpUnary.dst);
         mapReg(m, &i->Pin.FpUnary.src);
         return;
      case Pin_FpBinary:
         mapReg(m, &i->Pin.FpBinary.dst);
         mapReg(m, &i->Pin.FpBinary.srcL);
         mapReg(m, &i->Pin.FpBinary.srcR);
         return;
      case Pin_FpLdSt:
         mapReg(m, &i->Pin.FpLdSt.reg);
         mapRegs_PPC32AMode(m, i->Pin.FpLdSt.addr);
         return;
      case Pin_FpF64toF32:
         mapReg(m, &i->Pin.FpF64toF32.dst);
         mapReg(m, &i->Pin.FpF64toF32.src);
         return;
      case Pin_FpF64toI32:
         mapReg(m, &i->Pin.FpF64toI32.dst);
         mapReg(m, &i->Pin.FpF64toI32.src);
         return;
      case Pin_FpCMov:
         mapReg(m, &i->Pin.FpCMov.dst);
         mapReg(m, &i->Pin.FpCMov.src);
         return;
      case Pin_FpLdFPSCR:
         mapReg(m, &i->Pin.FpLdFPSCR.src);
         return;
      case Pin_FpCmp:
         mapReg(m, &i->Pin.FpCmp.dst);
         mapReg(m, &i->Pin.FpCmp.srcL);
         mapReg(m, &i->Pin.FpCmp.srcR);
         return;

   case Pin_RdWrLR:
      mapReg(m, &i->Pin.RdWrLR.gpr);
      return;

   default:
      ppPPC32Instr(i);
      vpanic("mapRegs_PPC32Instr");
   }
}

/* Figure out if i represents a reg-reg move, and if so assign the
   source and destination to *src and *dst.  If in doubt say No.  Used
   by the register allocator to do move coalescing. 
*/
Bool isMove_PPC32Instr ( PPC32Instr* i, HReg* src, HReg* dst )
{
   /* Moves between integer regs */
   if (i->tag == Pin_Alu32) {
      // or Rd,Rs,Rs == mr Rd,Rs
      if (i->Pin.Alu32.op != Palu_OR)
         return False;
      if (i->Pin.Alu32.srcR->tag != Pri_Reg)
         return False;
      if (i->Pin.Alu32.srcR->Pri.Reg.reg != i->Pin.Alu32.srcL)
         return False;
      *src = i->Pin.Alu32.srcL;
      *dst = i->Pin.Alu32.dst;
      return True;
   }
   /* Moves between FP regs */
   if (i->tag == Pin_FpUnary) {
      if (i->Pin.FpUnary.op != Pfp_MOV)
         return False;
      *src = i->Pin.FpUnary.src;
      *dst = i->Pin.FpUnary.dst;
      return True;
   }
   return False;
}


/* Generate ppc32 spill/reload instructions under the direction of the
   register allocator.  Note it's critical these don't write the
   condition codes. */

PPC32Instr* genSpill_PPC32 ( HReg rreg, Int offsetB )
{
   PPC32AMode* am;
   vassert(offsetB >= 0);
   vassert(!hregIsVirtual(rreg));
   am = PPC32AMode_IR(offsetB, GuestStatePtr);
   
   switch (hregClass(rreg)) {
   case HRcInt32:
      return PPC32Instr_Store( 4, am, rreg);
   case HRcFlt64:
      return PPC32Instr_FpLdSt ( False/*store*/, 8, rreg, am );
   default: 
      ppHRegClass(hregClass(rreg));
      vpanic("genSpill_PPC32: unimplemented regclass");
   }
}

PPC32Instr* genReload_PPC32 ( HReg rreg, Int offsetB )
{
   PPC32AMode* am;
   vassert(offsetB >= 0);
   vassert(!hregIsVirtual(rreg));
   am = PPC32AMode_IR(offsetB, GuestStatePtr);

   switch (hregClass(rreg)) {
   case HRcInt32:
      return PPC32Instr_Load( 4, False, rreg, am );
   case HRcFlt64:
      return PPC32Instr_FpLdSt ( True/*load*/, 8, rreg, am );
   default: 
      ppHRegClass(hregClass(rreg));
      vpanic("genReload_PPC32: unimplemented regclass");
   }
}


/* --------- The ppc32 assembler (bleh.) --------- */

static UInt iregNo ( HReg r )
{
   UInt n;
   vassert(hregClass(r) == HRcInt32);
   vassert(!hregIsVirtual(r));
   n = hregNumber(r);
   vassert(n <= 32);
   return n;
}

static UInt fregNo ( HReg fr )
{
   UInt n;
   vassert(hregClass(fr) == HRcFlt64);
   vassert(!hregIsVirtual(fr));
   n = hregNumber(fr);
   vassert(n <= 32);
   return n;
}

/* Emit 32bit instruction big-endianly */
static UChar* emit32 ( UChar* p, UInt w32 )
{
   *p++ = toUChar((w32 >> 24) & 0x000000FF);
   *p++ = toUChar((w32 >> 16) & 0x000000FF);
   *p++ = toUChar((w32 >>  8) & 0x000000FF);
   *p++ = toUChar((w32)       & 0x000000FF);
   return p;
}

/* The following mkForm[...] functions refer to PPC32 instruction forms
   as per PPC32 p576
 */

static UChar* mkFormD ( UChar* p, UInt opc1, UInt r1, UInt r2, UInt imm )
{
   UInt theInstr;
   vassert(opc1 < 0x40);
   vassert(r1  < 0x20);
   vassert(r2  < 0x20);
   vassert(imm < 0x10000 || imm >= 0xFFFF8000);     // Pos|Neg
   imm = imm & 0xFFFF;
   theInstr = ((opc1<<26) | (r1<<21) | (r2<<16) | (imm));
   return emit32(p, theInstr);
}

static UChar* mkFormX ( UChar* p, UInt opc1, UInt r1, UInt r2,
                        UInt r3, UInt opc2, UInt b0 )
{
   UInt theInstr;
   vassert(opc1 < 0x40);
   vassert(r1  < 0x20);
   vassert(r2  < 0x20);
   vassert(r3  < 0x20);
   vassert(opc2 < 0x400);
   vassert(b0  < 0x2);
   theInstr = ((opc1<<26) | (r1<<21) | (r2<<16) | (r3<<11) | (opc2<<1) | (b0));
   return emit32(p, theInstr);
}

static UChar* mkFormXO ( UChar* p, UInt opc1, UInt r1, UInt r2,
                         UInt r3, UInt b10, UInt opc2, UInt b0 )
{
   UInt theInstr;
   vassert(opc1 < 0x40);
   vassert(r1  < 0x20);
   vassert(r2  < 0x20);
   vassert(r3  < 0x20);
   vassert(b10 < 0x2);
   vassert(opc2 < 0x200);
   vassert(b0  < 0x2);
   theInstr = ((opc1<<26) | (r1<<21) | (r2<<16) |
               (r3<<11) | (b10 << 10) | (opc2<<1) | (b0));
   return emit32(p, theInstr);
}

static UChar* mkFormXL ( UChar* p, UInt opc1, UInt f1, UInt f2,
                         UInt f3, UInt opc2, UInt b0 )
{
   UInt theInstr;
   vassert(opc1 < 0x40);
   vassert(f1  < 0x20);
   vassert(f2  < 0x20);
   vassert(f3  < 0x20);
   vassert(opc2 < 0x400);
   vassert(b0  < 0x2);
   theInstr = ((opc1<<26) | (f1<<21) | (f2<<16) | (f3<<11) | (opc2<<1) | (b0));
   return emit32(p, theInstr);
}

// Note: for split field ops, give mnemonic arg
static UChar* mkFormXFX ( UChar* p, UInt r1, UInt f2, UInt opc2 )
{
   UInt theInstr;
   vassert(r1  < 0x20);
   vassert(f2  < 0x20);
   vassert(opc2 < 0x400);
   switch (opc2) {
   case 144:  // mtcrf
      vassert(f2 < 0x100);
      f2 = f2 << 1;
      break;
   case 339:  // mfspr
   case 371:  // mftb
   case 467:  // mtspr
      vassert(f2 < 0x400);
      f2 = ((f2>>5) & 0x1F) | ((f2 & 0x1F)<<5);  // re-arrange split field
      break;
   default: vpanic("mkFormXFX(PPC32)");
   }
   theInstr = ((31<<26) | (r1<<21) | (f2<<11) | (opc2<<1));
   return emit32(p, theInstr);
}

// Only used by mtfsf
static UChar* mkFormXFL ( UChar* p, UInt FM, UInt freg )
{
   UInt theInstr;
   vassert(FM   < 0x100);
   vassert(freg < 0x20);
   theInstr = ((63<<26) | (FM<<17) | (freg<<11) | (711<<1));
   return emit32(p, theInstr);
}

#if 0
// 'b'
static UChar* mkFormI ( UChar* p, UInt LI, UInt AA, UInt LK )
{
   UInt theInstr;
   vassert(LI  < 0x1000000);
   vassert(AA  < 0x2);
   vassert(LK  < 0x2);
   theInstr = ((18<<26) | (LI<<2) | (AA<<1) | (LK));
   return emit32(p, theInstr);
}
#endif

// 'bc'
static UChar* mkFormB ( UChar* p, UInt BO, UInt BI,
                        UInt BD, UInt AA, UInt LK )
{
   UInt theInstr;
   vassert(BO  < 0x20);
   vassert(BI  < 0x20);
   vassert(BD  < 0x4000);
   vassert(AA  < 0x2);
   vassert(LK  < 0x2);
   theInstr = ((16<<26) | (BO<<21) | (BI<<16) | (BD<<2) | (AA<<1) | (LK));
   return emit32(p, theInstr);
}

// rotates
static UChar* mkFormM ( UChar* p, UInt opc1, UInt r1, UInt r2,
                        UInt f3, UInt MB, UInt ME, UInt Rc )
{
   UInt theInstr;
   vassert(opc1 < 0x40);
   vassert(r1  < 0x20);
   vassert(r2  < 0x20);
   vassert(f3  < 0x20);
   vassert(MB  < 0x20);
   vassert(ME  < 0x20);
   vassert(Rc  < 0x2);
   theInstr = ((opc1<<26) | (r1<<21) | (r2<<16) |
               (f3<<11) | (MB<<6) | (ME<<1) | (Rc));
   return emit32(p, theInstr);
}

static UChar* mkFormA ( UChar* p, UInt opc1, UInt r1, UInt r2,
                        UInt r3, UInt r4, UInt opc2, UInt b0 )
{
   UInt theInstr;
   vassert(opc1 < 0x40);
   vassert(r1   < 0x20);
   vassert(r2   < 0x20);
   vassert(r3   < 0x20);
   vassert(r4   < 0x20);
   vassert(opc2 < 0x20);
   vassert(b0   < 0x2 );
   theInstr = ((opc1<<26) | (r1<<21) | (r2<<16) | (r3<<11) |
               (r4<<6) | (opc2<<1) | (b0));
   return emit32(p, theInstr);
}

static UChar* doAMode_IR ( UChar* p, UInt opc1, UInt rSD, PPC32AMode* am )
{
   UInt rA, idx;
   vassert(am->tag == Pam_IR);
   vassert(am->Pam.IR.index < 0x10000);

   rA  = iregNo(am->Pam.IR.base);
   idx = am->Pam.IR.index;

   p = mkFormD(p, opc1, rSD, rA, idx);
   return p;
}


static UChar* doAMode_RR ( UChar* p, UInt opc1, UInt opc2,
                           UInt rSD, PPC32AMode* am )
{
   UInt rA, rB;
   vassert(am->tag == Pam_RR);

   rA  = iregNo(am->Pam.RR.base);
   rB  = iregNo(am->Pam.RR.index);
   
   p = mkFormX(p, opc1, rSD, rA, rB, opc2, 0);
   return p;
}

/* Load imm to r_dst */
static UChar* mkLoadImm ( UChar* p, UInt r_dst, UInt imm )
{
   vassert(r_dst < 0x20);

   if (imm >= 0xFFFF8000 || imm <= 0x7FFF) { // sign-extendable from 16 bits?
      // addi r_dst,0,imm  => li r_dst,imm
      p = mkFormD(p, 14, r_dst, 0, imm);
   } else {
      // addis r_dst,r0,(imm>>16) => lis r_dst, (imm>>16)
      p = mkFormD(p, 15, r_dst, 0, (imm>>16));
      // ori r_dst, r_dst, (imm & 0xFFFF)
      p = mkFormD(p, 24, r_dst, r_dst, (imm & 0xFFFF));
   }
   return p;
}


/* Move r_dst to r_src */
static UChar* mkMoveReg ( UChar* p, UInt r_dst, UInt r_src )
{
   vassert(r_dst < 0x20);
   vassert(r_src < 0x20);

   if (r_dst != r_src) {
      /* or r_dst, r_src, r_src */
      p = mkFormX(p, 31, r_src, r_dst, r_src, 444, 0 );
   }
   return p;
}


/* Emit an instruction into buf and return the number of bytes used.
   Note that buf is not the insn's final place, and therefore it is
   imperative to emit position-independent code. */

Int emit_PPC32Instr ( UChar* buf, Int nbuf, PPC32Instr* i )
{
//..    UInt irno, opc, opc_rr, subopc_imm, opc_imma, opc_cl, opc_imm, subopc;

   UChar* p = &buf[0];
   UChar* ptmp = p;
   vassert(nbuf >= 32);

//   vex_printf("asm  ");ppPPC32Instr(i); vex_printf("\n");

   switch (i->tag) {

   case Pin_Alu32: {
      UInt opc1, opc2, r_srcR, imm_srcR;
      UInt r_dst  = iregNo(i->Pin.Alu32.dst);
      UInt r_srcL = iregNo(i->Pin.Alu32.srcL);

      /* ADD/AND/OR/XOR */
      if (i->Pin.Alu32.srcR->tag == Pri_Reg) {
         opc1 = 31;
         r_srcR = iregNo(i->Pin.Alu32.srcR->Pri.Reg.reg);
         switch (i->Pin.Alu32.op) {
         case Palu_ADD: opc2 = 266; break;
         case Palu_AND: opc2 =  28; break;
         case Palu_XOR: opc2 = 316; break;
         case Palu_OR:  opc2 = 444; break;
         default:
            goto bad;
         }

         if (i->Pin.Alu32.op == Palu_ADD) {
            p = mkFormXO(p, opc1, r_dst, r_srcL, r_srcR, 0, opc2, 0);
         } else {
            p = mkFormX(p, opc1, r_srcL, r_dst, r_srcR, opc2, 0);
         }
      } else { // tag == Pri_Imm:
         imm_srcR = i->Pin.Alu32.srcR->Pri.Imm.imm32;
         switch (i->Pin.Alu32.op) {
         case Palu_ADD: opc1 = 14; break;
         case Palu_AND: opc1 = 28; break;
         case Palu_XOR: opc1 = 26; break;
         case Palu_OR:  opc1 = 24; break;
         default:
            goto bad;
         }

         if (i->Pin.Alu32.op == Palu_ADD) {
            p = mkFormD(p, opc1, r_dst, r_srcL, imm_srcR);
         } else {
            p = mkFormD(p, opc1, r_srcL, r_dst, imm_srcR);
         }
      }
      goto done;
   }

   case Pin_Sub32: {
      UInt r_dst = iregNo(i->Pin.Sub32.dst);
      UInt r_srcR = iregNo(i->Pin.Sub32.srcR);
      UInt r_srcL, imm_srcL;

      // Note argument swap: PPC32 only has sub-from instrs
      switch (i->Pin.Sub32.srcL->tag) {
      case Pri_Reg:
         r_srcL = iregNo(i->Pin.Sub32.srcL->Pri.Reg.reg);
         // subf r_dst, r_srcR, r_srcL
         p = mkFormXO(p, 31, r_dst, r_srcR, r_srcL, 0, 40, 0);
         break;
      case Pri_Imm:
         imm_srcL = i->Pin.Sub32.srcL->Pri.Imm.imm32;
         // subf r_dst, r_srcR, imm_srcL
         p = mkFormD(p, 8, r_dst, r_srcR, imm_srcL);
         break;
      default:
         goto bad;
      }
      goto done;
   }

   case Pin_Sh32: {
      UInt opc1 = 31, opc2, r_shft, imm_shft;
      UInt op = i->Pin.Sh32.op;
      UInt r_src = iregNo(i->Pin.Sh32.src);
      UInt r_dst = iregNo(i->Pin.Sh32.dst);

      switch (i->Pin.Sh32.shft->tag) {
      case Pri_Reg:
         switch (op) {
         case Psh_SHL: opc2 = 24;  break;
         case Psh_SHR: opc2 = 536; break;
         case Psh_SAR: opc2 = 792; break;
         default: goto bad;
         }
         r_shft = iregNo(i->Pin.Sh32.shft->Pri.Reg.reg);
         p = mkFormX(p, opc1, r_src, r_dst, r_shft, opc2, 0);
         break;

      case Pri_Imm:  // SAR only
         if (op != Psh_SAR) goto bad;
         opc2 = 824;
         imm_shft = i->Pin.Sh32.shft->Pri.Imm.imm32;
         p = mkFormX(p, opc1, r_src, r_dst, imm_shft, opc2, 0);
         break;

      default:
         goto bad;
      }
      goto done;
   }

   case Pin_Cmp32: {
      UInt opc1, opc2=0;
      UInt op = i->Pin.Cmp32.op;
      UInt fld1 = (7 - i->Pin.Cmp32.crfD) << 2;
      UInt r_srcL = iregNo(i->Pin.Cmp32.srcL);
      UInt r_srcR, imm_srcR;

      switch (i->Pin.Cmp32.srcR->tag) {
      case Pri_Imm:
         opc1 = (op == Pcmp_U) ? 10 : 11;
         imm_srcR = i->Pin.Cmp32.srcR->Pri.Imm.imm32;
         p = mkFormD(p, opc1, fld1, r_srcL, imm_srcR);
         break;
      case Pri_Reg:
         opc1 = 31;
         opc2 = (op == Pcmp_U) ? 32 : 0;
         r_srcR = iregNo(i->Pin.Cmp32.srcR->Pri.Reg.reg);
         p = mkFormX(p, opc1, fld1, r_srcL, r_srcR, opc2, 0);
         break;
      default: goto bad;
      }        
      goto done;
   }

   case Pin_Unary32: {
      UInt r_dst = iregNo(i->Pin.Unary32.dst);
      UInt r_src = iregNo(i->Pin.Unary32.src);

      switch (i->Pin.Unary32.op) {
      case Pun_NOT:  // nor r_dst,r_src,r_src
         p = mkFormX(p, 31, r_src, r_dst, r_src, 124, 0);
         break;
      case Pun_NEG:  // neg r_dst,r_src
         p = mkFormXO(p, 31, r_dst, r_src, 0, 0, 104, 0);
         break;
      case Pun_CLZ:  // cntlzw r_dst, r_src
         p = mkFormX(p, 31, r_src, r_dst, 0, 26, 0);
         break;
      default: goto bad;
      }
      goto done;
   }

   case Pin_MulL: {
      Bool syned  = i->Pin.MulL.syned;
      UInt r_dst  = iregNo(i->Pin.MulL.dst);
      UInt r_srcL = iregNo(i->Pin.MulL.srcL);
      UInt r_srcR, imm;

      switch (i->Pin.MulL.word) {
      case 0:  // Mult LOW word
         switch (i->Pin.MulL.srcR->tag) {
         case Pri_Reg:
            // mullw r_dst,r_srcL,r_srcR
            // sign makes no difference.
            r_srcR = iregNo(i->Pin.MulL.srcR->Pri.Reg.reg);
            p = mkFormXO(p, 31, r_dst, r_srcL, r_srcR, 0, 235, 0);
            break;
         case Pri_Imm:
            // mulli r_dst,r_src,imm
            vassert(syned == True);  // always signed
            imm = i->Pin.MulL.srcR->Pri.Imm.imm32;
            p = mkFormD(p, 07, r_dst, r_srcL, imm);
            break;
         default:
            goto bad;
         }
         break;

      case 1:  // Mult HIGH word
         vassert(i->Pin.MulL.srcR->tag == Pri_Reg);
         r_srcR = iregNo(i->Pin.MulL.srcR->Pri.Reg.reg);
         if (syned == True) {
            // mulhw r_dst,r_srcL,r_srcR
            p = mkFormXO(p, 31, r_dst, r_srcL, r_srcR, 0, 75, 0);
         } else {
            // mulhwu r_dst,r_srcL,r_srcR
            p = mkFormXO(p, 31, r_dst, r_srcL, r_srcR, 0, 11, 0);
         }
         break;

      default: goto bad;
      }
      goto done;
   }

   case Pin_Div: {
      Bool syned  = i->Pin.MulL.syned;
      UInt r_dst  = iregNo(i->Pin.Div.dst);
      UInt r_srcL = iregNo(i->Pin.Div.srcL);
      UInt r_srcR = iregNo(i->Pin.Div.srcR);

      if (syned == True) {
         // divw r_dst,r_srcL,r_srcR
         p = mkFormXO(p, 31, r_dst, r_srcL, r_srcR, 0, 491, 0);
      } else {
         // divwu r_dst,r_srcL,r_srcR
         p = mkFormXO(p, 31, r_dst, r_srcL, r_srcR, 0, 459, 0);
      }
      goto done;
   }

   case Pin_Call: {
      PPC32CondCode cond = i->Pin.Call.cond;
      UInt r_dst = 12;
      /* As per detailed comment for Pin_Call in
         getRegUsage_PPC32Instr above, %r12 is used as an address temp */

      /* jump over the following insns if condition does not hold */
      if (cond.test != Pct_ALWAYS) {
         /* jmp fwds if !condition */
         /* don't know how many bytes to jump over yet...
            make space for a jump instruction and fill in later. */
         ptmp = p; /* fill in this bit later */
         p += 4;                                               // p += 4
      }

      /* load target to r_dst */
      p = mkLoadImm(p, r_dst, i->Pin.Call.target);             // p += 4|8

      /* mtspr 9,r_dst => move r_dst to count register */
      p = mkFormXFX(p, r_dst, 9, 467);                         // p += 4
      
      /* bctrl => branch to count register (and save to lr) */
      p = mkFormXL(p, 19, Pct_ALWAYS, 0, 0, 528, 1);           // p += 4

      /* Fix up the conditional jump, if there was one. */
      if (cond.test != Pct_ALWAYS) {
         Int delta = p - ptmp;
         vassert(delta >= 16 && delta <= 20);
         /* bc !ct,cf,delta */
         mkFormB(ptmp, invertCondTest(cond.test), cond.flag, (delta>>2), 0, 0);
      }
      goto done;
   }

   case Pin_Goto: {
      UInt magic_num = 0;
      UChar r_return = 3;    /* Put target addr into %r3 */
      PPC32CondCode cond = i->Pin.Goto.cond;
      UInt r_dst, imm_dst;
      
      /* First off, if this is conditional, create a conditional
         jump over the rest of it. */
      if (cond.test != Pct_ALWAYS) {
         /* jmp fwds if !condition */
         /* don't know how many bytes to jump over yet...
            make space for a jump instruction and fill in later. */
         ptmp = p; /* fill in this bit later */
         p += 4;
      }

      // cond succeeds...
      
      /* If a non-boring, set GuestStatePtr appropriately. */
      switch (i->Pin.Goto.jk) {
      case Ijk_ClientReq: magic_num = VEX_TRC_JMP_CLIENTREQ; break;
      case Ijk_Syscall:   magic_num = VEX_TRC_JMP_SYSCALL;   break;
      case Ijk_Yield:     magic_num = VEX_TRC_JMP_YIELD;     break;
      case Ijk_EmWarn:    magic_num = VEX_TRC_JMP_EMWARN;    break;
      case Ijk_MapFail:   magic_num = VEX_TRC_JMP_MAPFAIL;   break;
      case Ijk_NoDecode:  magic_num = VEX_TRC_JMP_NODECODE;  break;
      case Ijk_TInval:    magic_num = VEX_TRC_JMP_TINVAL;    break;
      case Ijk_Ret:
      case Ijk_Call:
      case Ijk_Boring:
         break;
      default: 
         ppIRJumpKind(i->Pin.Goto.jk);
         vpanic("emit_PPC32Instr.Pin_Goto: unknown jump kind");
      }
      if (magic_num !=0) {
         vassert(magic_num < 0x10000);
         /* addi r31,0,magic_num */
         p = mkFormD(p, 14, 31, 0, magic_num);         // p += 4
      }

      /* Get the destination address into %r_return */
      if (i->Pin.Goto.dst->tag == Pri_Imm) {
         imm_dst = i->Pin.Goto.dst->Pri.Imm.imm32;
         p = mkLoadImm(p, r_return, imm_dst);          // p += 4|8
      } else {
         vassert(i->Pin.Goto.dst->tag == Pri_Reg);
         r_dst = iregNo(i->Pin.Goto.dst->Pri.Reg.reg);
         p = mkMoveReg(p, r_return, r_dst);            // p += 4
      }
      
      /* blr */
      p = mkFormXL(p, 19, Pct_ALWAYS, 0, 0, 16, 0);    // p += 4

      /* Fix up the conditional jump, if there was one. */
      if (cond.test != Pct_ALWAYS) {
         Int delta = p - ptmp;
         vassert(delta >= 12 && delta <= 20);
         /* bc !ct,cf,delta */
         mkFormB(ptmp, invertCondTest(cond.test), cond.flag, (delta>>2), 0, 0);
      }
      goto done;
   }

   case Pin_CMov32: {
      UInt r_dst, imm_src, r_src;
      PPC32CondCode cond;
      vassert(i->Pin.CMov32.cond.test != Pct_ALWAYS);

      r_dst = iregNo(i->Pin.CMov32.dst);
      cond = i->Pin.CMov32.cond;

      /* branch (if cond fails) over move instrs */
      if (cond.test != Pct_ALWAYS) {
         /* don't know how many bytes to jump over yet...
            make space for a jump instruction and fill in later. */
         ptmp = p; /* fill in this bit later */
         p += 4;
      }

      // cond true: move src => dst
      switch (i->Pin.CMov32.src->tag) {
      case Pri_Imm:
         imm_src = i->Pin.CMov32.src->Pri.Imm.imm32;
         p = mkLoadImm(p, r_dst, imm_src);
         break;
      case Pri_Reg:
         r_src = iregNo(i->Pin.CMov32.src->Pri.Reg.reg);
         p = mkMoveReg(p, r_dst, r_src);
         break;
      default: goto bad;
      }

      /* Fix up the conditional jump, if there was one. */
      if (cond.test != Pct_ALWAYS) {
         Int delta = p - ptmp;
         vassert(delta >= 4 && delta <= 12);
         /* bc !ct,cf,delta */
         mkFormB(ptmp, invertCondTest(cond.test), cond.flag, (delta>>2), 0, 0);
      }
      goto done;
   }

   case Pin_Load: {
      PPC32AMode* am_addr = i->Pin.Load.src;
      UInt r_dst = iregNo(i->Pin.Load.dst);
      Bool syned = i->Pin.Load.syned;
      UInt opc1, opc2, sz = i->Pin.Load.sz;
      switch (i->Pin.Load.src->tag) {
      case Pam_IR:
         if (sz == 2) {  // the only signed load
            opc1 = (syned) ? 42: 40;
         } else {
            vassert(syned == False);
            opc1 = (sz == 1) ? 34 : 32;   // 1:4
         }
         p = doAMode_IR(p, opc1, r_dst, am_addr);
         goto done;
      case Pam_RR:
         if (sz == 2) {  // the only signed load
            opc2 = (syned) ? 343: 279;
         } else {
            vassert(syned == False);
            opc2 = (sz == 1) ? 87 : 23;   // 1:4
         }
         p = doAMode_RR(p, 31, opc2, r_dst, am_addr);
         goto done;
      default:
         goto bad;
      }
   }

   case Pin_Set32: {
      /* Make the destination register be 1 or 0, depending on whether
         the relevant condition holds. */
      UInt r_dst = iregNo(i->Pin.Set32.dst);
      PPC32CondCode cond = i->Pin.Set32.cond;
      UInt rot_imm;
      UInt r_tmp;

      if (cond.test == Pct_ALWAYS) {
         // Just load 1 to dst => li dst,1
         p = mkFormD(p, 14, r_dst, 0, 1);
      } else {
         rot_imm = 1 + cond.flag;
         r_tmp = 0;  // Not within scope of regalloc, so no need to declare.

         // r_tmp = CR  => mfcr r_tmp
         p = mkFormX(p, 31, r_tmp, 0, 0, 19, 0);

         // r_dst = flag (rotate left and mask)
         //  => rlwinm r_dst,r_tmp,rot_imm,31,31
         p = mkFormM(p, 21, r_tmp, r_dst, rot_imm, 31, 31, 0);

         if (cond.test == Pct_FALSE) {
            // flip bit  => xori r_dst,r_dst,1
            p = mkFormD(p, 26, r_dst, r_dst, 1);
         }
      }
      goto done;
   }

   case Pin_MFence: {
      p = mkFormX(p, 31, 0, 0, 0, 598, 0);   // sync, PPC32 p616
// CAB: Should this be isync?
//    p = mkFormXL(p, 19, 0, 0, 0, 150, 0);  // isync, PPC32 p467
      goto done;
   }

   case Pin_Store: {
      PPC32AMode* am_addr = i->Pin.Store.dst;
      UInt r_src = iregNo(i->Pin.Store.src);
      UInt opc1, opc2, sz = i->Pin.Store.sz;
      switch (i->Pin.Store.dst->tag) {
      case Pam_IR:
         opc1 = (sz == 1) ? 38 : ((sz == 2) ? 44 : 36);      // 1:2:4
         p = doAMode_IR(p, opc1, r_src, am_addr);
         goto done;
      case Pam_RR:
         opc2 = (sz == 1) ? 215 : ((sz == 2) ? 407 : 151);   // 1:2:4
         p = doAMode_RR(p, 31, opc2, r_src, am_addr);
         goto done;
      default:
         goto bad;
      }
      goto done;
   }

   case Pin_FpUnary: {
      UInt fr_dst = fregNo(i->Pin.FpUnary.dst);
      UInt fr_src = fregNo(i->Pin.FpUnary.src);
      switch (i->Pin.FpUnary.op) {
      case Pfp_SQRT:  // fsqrt, PPC32 p427
         p = mkFormA( p, 63, fr_dst, 0, fr_src, 0, 22, 0 );
         break;
      case Pfp_ABS:   // fabs, PPC32 p399
         p = mkFormX(p, 63, fr_dst, 0, fr_src, 264, 0);
         break;
      case Pfp_NEG:   // fneg, PPC32 p416
         p = mkFormX(p, 63, fr_dst, 0, fr_src, 40, 0);
         break;
      case Pfp_MOV:   // fmr, PPC32 p410
         p = mkFormX(p, 63, fr_dst, 0, fr_src, 72, 0);
         break;
      default:
         goto bad;
      }
      goto done;
   }

   case Pin_FpBinary: {
      UInt fr_dst  = fregNo(i->Pin.FpBinary.dst);
      UInt fr_srcL = fregNo(i->Pin.FpBinary.srcL);
      UInt fr_srcR = fregNo(i->Pin.FpBinary.srcR);
      switch (i->Pin.FpBinary.op) {
      case Pfp_ADD:   // fadd, PPC32 p400
         p = mkFormA( p, 63, fr_dst, fr_srcL, fr_srcR, 0, 21, 0 );
         break;
      case Pfp_SUB:   // fsub, PPC32 p429
         p = mkFormA( p, 63, fr_dst, fr_srcL, fr_srcR, 0, 20, 0 );
         break;
      case Pfp_MUL:   // fmul, PPC32 p413
         p = mkFormA( p, 63, fr_dst, fr_srcL, 0, fr_srcR, 25, 0 );
         break;
      case Pfp_DIV:   // fdiv, PPC32 p406
         p = mkFormA( p, 63, fr_dst, fr_srcL, fr_srcR, 0, 18, 0 );
         break;
      default:
         goto bad;
      }
      goto done;
   }

   case Pin_FpLdSt: {
      PPC32AMode* am_addr = i->Pin.FpLdSt.addr;
      UInt f_reg = fregNo(i->Pin.FpLdSt.reg);
      Bool idxd = toBool(i->Pin.FpLdSt.addr->tag == Pam_RR);
      UChar sz = i->Pin.FpLdSt.sz;
      vassert(sz == 4 || sz == 8);

      if (i->Pin.FpLdSt.isLoad) {   // Load from memory
         if (idxd) {  // lf[s|d]x, PPC32 p444|440
            p = doAMode_RR(p, 31, ((sz == 4) ? 535 : 599), f_reg, am_addr);
         } else {     // lf[s|d], PPC32 p441|437
            p = doAMode_IR(p, ((sz == 4) ? 48 : 50), f_reg, am_addr);
         }
      } else {                      // Store to memory
         if (idxd) { // stf[s|d]x, PPC32 p521|516
            p = doAMode_RR(p, 31, ((sz == 4) ? 663 : 727), f_reg, am_addr);
         } else {    // stf[s|d], PPC32 p518|513
            p = doAMode_IR(p, ((sz == 4) ? 52 : 54), f_reg, am_addr);
         }
      }
      goto done;
   }

   case Pin_FpF64toF32: {
      UInt fr_dst = fregNo(i->Pin.FpF64toF32.dst);
      UInt fr_src = fregNo(i->Pin.FpF64toF32.src);
      // frsp, PPC32 p423
      p = mkFormX(p, 63, fr_dst, 0, fr_src, 12, 0);
      goto done;
   }

   case Pin_FpF64toI32: {
      UInt  r_dst   = iregNo(i->Pin.FpF64toI32.dst);
      UInt  fr_src  = fregNo(i->Pin.FpF64toI32.src);
      UChar fr_tmp  = 7;                // Temp freg
      PPC32AMode* am_addr;

      // fctiw (conv f64 to i32), PPC32 p404
      p = mkFormX(p, 63, fr_tmp, 0, fr_src, 14, 0);

      // No RI form of stfiwx, so need PPC32AMode_RR:
      am_addr = PPC32AMode_RR( StackFramePtr, hregPPC32_GPR0() );

      // stfiwx (store fp64[lo32] as int32), PPC32 p517
      p = doAMode_RR(p, 31, 983, fr_tmp, am_addr);

      // lwzx (load int32), PPC32 p463
      p = doAMode_RR(p, 31, 23, r_dst, am_addr);
      goto done;
   }

   case Pin_FpCMov: {
      UInt fr_dst      = fregNo(i->Pin.FpCMov.dst);
      UInt fr_src      = fregNo(i->Pin.FpCMov.src);
      PPC32CondCode cc = i->Pin.FpCMov.cond;

      if (fr_dst == fr_src) goto done;
      
      vassert(cc.test != Pct_ALWAYS);

      /* jmp fwds if !condition */
      if (cc.test != Pct_ALWAYS) {
         /* bc !ct,cf,n_bytes>>2 */
         p = mkFormB(p, invertCondTest(cc.test), cc.flag, 8>>2, 0, 0);
      }

      // fmr, PPC32 p410
      p = mkFormX(p, 63, fr_dst, 0, fr_src, 72, 0);
      goto done;
   }

   case Pin_FpLdFPSCR: {
      UInt fr_src = fregNo(i->Pin.FpLdFPSCR.src);
      p = mkFormXFL(p, 0xFF, fr_src);     // mtfsf, PPC32 p480
      goto done;
   }

   case Pin_FpCmp: {
      UChar crfD = 1;
      UInt r_dst   = iregNo(i->Pin.FpCmp.dst);
      UInt fr_srcL = fregNo(i->Pin.FpCmp.srcL);
      UInt fr_srcR = fregNo(i->Pin.FpCmp.srcR);
      vassert(crfD < 8);
      // fcmpo, PPC32 p402
      p = mkFormX(p, 63, (crfD<<2), fr_srcL, fr_srcR, 32, 0);

      // mfcr (mv CR to r_dst), PPC32 p467
      p = mkFormX(p, 31, r_dst, 0, 0, 19, 0);
      
      // rlwinm r_dst,r_dst,8,28,31, PPC32 p501
      //  => rotate field 6 to field 0, masking to field 0
      p = mkFormM(p, 21, r_dst, r_dst, 8, 28, 31, 0);
      goto done;
   }

   case Pin_RdWrLR: {
      UInt reg = iregNo(i->Pin.RdWrLR.gpr);
      /* wrLR==True ? mtlr r4 : mflr r4 */
      p = mkFormXFX(p, reg, 8, (i->Pin.RdWrLR.wrLR==True) ? 467 : 339);
      goto done;
   }

   default: 
      goto bad;
   }

  bad:
   vex_printf("\n=> ");
   ppPPC32Instr(i);
   vpanic("emit_PPC32Instr");
   /*NOTREACHED*/
   
  done:
   vassert(p - &buf[0] <= 32);
   return p - &buf[0];
}

/*---------------------------------------------------------------*/
/*--- end                                  host-ppc32/hdefs.c ---*/
/*---------------------------------------------------------------*/
