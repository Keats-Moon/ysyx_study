// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vour.h for the primary calling header

#include "Vour__pch.h"

void Vour___024root___eval_sample(Vour___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vour___024root___eval_sample\n"); );
    Vour__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vour___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vour___024root___eval_ico(Vour___024root* vlSelf, CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vour___024root___eval_ico\n"); );
    Vour__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[0U]) 
                                     | (IData)((IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vour___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    return (0U);
}

bool Vour___024root___eval_act(Vour___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vour___024root___eval_act\n"); );
    Vour__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vour___024root___eval_inact(Vour___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vour___024root___eval_inact\n"); );
    Vour__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vour___024root___eval_nba(Vour___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vour___024root___eval_nba\n"); );
    Vour__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vour___024root___eval_obs(Vour___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vour___024root___eval_obs\n"); );
    Vour__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vour___024root___eval_react(Vour___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vour___024root___eval_react\n"); );
    Vour__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

void Vour___024root___eval_postponed(Vour___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vour___024root___eval_postponed\n"); );
    Vour__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

bool Vour___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vour___024root___trigger_anySet__ico\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

#ifdef VL_DEBUG
void Vour___024root___eval_debug_assertions(Vour___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vour___024root___eval_debug_assertions\n"); );
    Vour__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
