#ifndef TOOL_SELECTION_TOOL_HPP
#define TOOL_SELECTION_TOOL_HPP

#include "tool/tool.hpp"

namespace Lipuma {
    class SelectionTool : public Tool{
       void mousePressEvent(QMouseEvent *e) override;
    };
}

#endif
