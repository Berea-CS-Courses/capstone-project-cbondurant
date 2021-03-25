#ifndef TOOL_TOOL_MANAGER_HPP
#define TOOL_TOOL_MANAGER_HPP

#include "tool/fractalTool.hpp"
#include "tool/selectionTool.hpp"

namespace Lipuma {
    // The tool manager is a purely static class
    // All methods allow access to singleton tool objects.
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
