// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vour__pch.h"

//============================================================
// Constructors

Vour::Vour(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vour__Syms(contextp(), _vcname__, this)}
    , m_evalLoop{*this, /*convergeLimit:*/ 10000}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vour::Vour(const char* _vcname__)
    : Vour(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vour::~Vour() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vour___024root___eval_debug_assertions(Vour___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vour___024root___eval_static(Vour___024root* vlSelf);
VL_ATTR_COLD void Vour___024root___eval_initial(Vour___024root* vlSelf);
VL_ATTR_COLD bool Vour___024root___eval_stl(Vour___024root* vlSelf, CData/*0:0*/ firstIteration);
void Vour___024root___eval_sample(Vour___024root* vlSelf);
bool Vour___024root___eval_ico(Vour___024root* vlSelf, CData/*0:0*/ firstIteration);
bool Vour___024root___eval_act(Vour___024root* vlSelf);
bool Vour___024root___eval_inact(Vour___024root* vlSelf);
bool Vour___024root___eval_nba(Vour___024root* vlSelf);
bool Vour___024root___eval_obs(Vour___024root* vlSelf);
bool Vour___024root___eval_react(Vour___024root* vlSelf);
void Vour___024root___eval_postponed(Vour___024root* vlSelf);
VL_ATTR_COLD void Vour___024root___eval_final(Vour___024root* vlSelf);
VL_ATTR_COLD void Vour___024root___eval_dump_triggers__stl(Vour___024root* vlSelf);
VL_ATTR_COLD void Vour___024root___eval_dump_triggers__ico(Vour___024root* vlSelf);
VL_ATTR_COLD void Vour___024root___eval_dump_triggers__act(Vour___024root* vlSelf);
VL_ATTR_COLD void Vour___024root___eval_dump_triggers__nba(Vour___024root* vlSelf);
VL_ATTR_COLD void Vour___024root___eval_dump_triggers__obs(Vour___024root* vlSelf);
VL_ATTR_COLD void Vour___024root___eval_dump_triggers__react(Vour___024root* vlSelf);

void Vour::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vour::eval_step\n"); );
    m_evalLoop.eval();
}

void Vour::evalBegin() {
#ifdef VL_DEBUG
    // Debug assertions
    Vour___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
}

void Vour::evalEnd() {
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vour::evalStatic() {
    Vour___024root___eval_static(&(vlSymsp->TOP));
}

void Vour::evalInitial() {
    Vour___024root___eval_initial(&(vlSymsp->TOP));
}

bool Vour::evalStl(bool firstIteration) {
    return Vour___024root___eval_stl(&(vlSymsp->TOP), firstIteration);
}

void Vour::evalSample() {
    Vour___024root___eval_sample(&(vlSymsp->TOP));
}

bool Vour::evalIco(bool firstIteration) {
    return Vour___024root___eval_ico(&(vlSymsp->TOP), firstIteration);
}

bool Vour::evalAct() {
    return Vour___024root___eval_act(&(vlSymsp->TOP));
}

bool Vour::evalInact() {
    return Vour___024root___eval_inact(&(vlSymsp->TOP));
}

bool Vour::evalNba() {
    return Vour___024root___eval_nba(&(vlSymsp->TOP));
}

bool Vour::evalObs() {
    return Vour___024root___eval_obs(&(vlSymsp->TOP));
}

bool Vour::evalReact() {
    return Vour___024root___eval_react(&(vlSymsp->TOP));
}

void Vour::evalPostponed() {
    Vour___024root___eval_postponed(&(vlSymsp->TOP));
}

void Vour::evalFinal() {
    Vour___024root___eval_final(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vour::dumpTriggersStl() {
    Vour___024root___eval_dump_triggers__stl(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vour::dumpTriggersIco() {
    Vour___024root___eval_dump_triggers__ico(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vour::dumpTriggersAct() {
    Vour___024root___eval_dump_triggers__act(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vour::dumpTriggersNba() {
    Vour___024root___eval_dump_triggers__nba(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vour::dumpTriggersObs() {
    Vour___024root___eval_dump_triggers__obs(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vour::dumpTriggersReact() {
    Vour___024root___eval_dump_triggers__react(&(vlSymsp->TOP));
}

//============================================================
// Events and timing
bool Vour::eventsPending() { return false; }

uint64_t Vour::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vour::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vour::final() {
    contextp()->executingFinal(true);
    evalFinal();
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vour::hierName() const { return vlSymsp->name(); }
const char* Vour::modelName() const { return "Vour"; }
unsigned Vour::threads() const { return 1; }
void Vour::prepareClone() const { contextp()->prepareClone(); }
void Vour::atClone() const {
    contextp()->threadPoolpOnClone();
}
