#ifndef TOOL_TOOL_MANAGER_HPP
#define TOOL_TOOL_MANAGER_HPP

#include "tool/fractalTool.hpp"
#include "tool/selectionTool.hpp"

namespace Lipuma {
    class ToolManager{
    public:
        static FractalTool* getFractalTool();
        static SelectionTool* getSelectionTool();
    private:
        static FractalTool* _FractalTool;
        static SelectionTool* _SelectionTool;
    };
}
#endif
