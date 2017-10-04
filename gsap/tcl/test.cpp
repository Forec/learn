#include <tcl.h>
#include <iostream>

int RepeatString(ClientData cld, Tcl_Interp * p, 
                 int iParamCount, Tcl_Obj * const pParamList[]) {
    std::cout << "RepeatString is called from TCL" << std::endl;
    char * pstrString = Tcl_GetString(pParamList[1]);
    int iRepCount;
    Tcl_GetIntFromObj(p, pParamList[2], &iRepCount);
    for (int i = 0; i < iRepCount; i++) {
        std::cout << "\t" << i << ": " << pstrString << std::endl;
    }
    Tcl_SetObjResult(p, Tcl_NewIntObj(iRepCount));
    return TCL_OK;
}

int main() {
    Tcl_Interp *pTclInterp = Tcl_CreateInterp();
    if (!pTclInterp) {
        std::cerr << "TCL interpreter cannot be created" << std::endl;
        return 1;
    }
    // 直接执行 TCL 语句
    Tcl_Eval(pTclInterp, "puts [expr 2 + 3]");

    // 导出 RepeatString 函数
    if (!Tcl_CreateObjCommand(pTclInterp, "RepeatString", RepeatString, (ClientData)NULL, NULL)) {
        std::cerr << "Command cannot be registered with TCL interpreter" << std::endl;
        return 1;
    }

    if (Tcl_EvalFile(pTclInterp, "test.tcl") == TCL_ERROR) {
        std::cerr << "Error executing script" << std::endl;
        return 1;
    }
    Tcl_Eval(pTclInterp, "pstr \"Hello TCL\" 4");

    int mulResult;
    // 由 TCL 调用 mul 并取得结果
    Tcl_Eval(pTclInterp, "mul 6 2");
    Tcl_Obj * pResultObj = Tcl_GetObjResult(pTclInterp);
    Tcl_GetIntFromObj(pTclInterp, pResultObj, &mulResult);
    std::cout << "6!/2! = " << mulResult << std::endl;

    // 读取 TCL 全局变量
    Tcl_Obj * pGlobalIntObj = Tcl_NewObj();
    Tcl_Obj * pGlobalStringObj = Tcl_NewObj();
    pGlobalIntObj = Tcl_GetVar2Ex(pTclInterp, "globalInt", NULL, 0);
    pGlobalStringObj = Tcl_GetVar2Ex(pTclInterp, "globalString", NULL, 0);
    int iGlobalInt;
    Tcl_GetIntFromObj(pTclInterp, pGlobalIntObj, &iGlobalInt);
    char * pstrGlobalString = Tcl_GetString(pGlobalStringObj);
    std::cout << "globalInt = " << iGlobalInt 
              << ", globalString = " << pstrGlobalString 
              << std::endl;

    // 修改 TCL 全局变量
    Tcl_SetVar2Ex(pTclInterp, "globalInt", NULL, Tcl_NewIntObj(512), 0);
    pGlobalIntObj = Tcl_GetVar2Ex(pTclInterp, "globalInt", NULL, 0);
    Tcl_GetIntFromObj(pTclInterp, pGlobalIntObj, &iGlobalInt);
    char pstrNewString [] = "...goodbye!";
    Tcl_SetVar2Ex(pTclInterp, "globalString", NULL, 
                  Tcl_NewStringObj(pstrNewString, strlen(pstrNewString)),
                  0);
    pGlobalStringObj = Tcl_GetVar2Ex(pTclInterp, "globalString", 0, 0);
    pstrGlobalString = Tcl_GetString(pGlobalStringObj);
    std::cout << "globalInt = " << iGlobalInt 
              << ", globalString = " << pstrGlobalString 
              << std::endl;

    Tcl_DeleteInterp(pTclInterp);
}