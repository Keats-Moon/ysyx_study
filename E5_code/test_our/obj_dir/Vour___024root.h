// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vour.h for the primary calling header

#ifndef VERILATED_VOUR___024ROOT_H_
#define VERILATED_VOUR___024ROOT_H_  // guard

#include "verilated.h"


class Vour__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vour___024root final {
  public:

    // DESIGN SPECIFIC STATE
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;

    // INTERNAL VARIABLES
    Vour__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vour___024root(Vour__Syms* symsp, const char* namep);
    ~Vour___024root();
    VL_UNCOPYABLE(Vour___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
