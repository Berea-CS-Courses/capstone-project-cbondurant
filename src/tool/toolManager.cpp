#include "tool/toolManager.hpp"

#include "tool/fractalTool.hpp"
#include "tool/selectionTool.hpp"

namespace Lipuma {

	FractalTool* ToolManager::_FractalTool = nullptr;

	FractalTool* ToolManager::getFractalTool(){
		if (!ToolManager::_FractalTool){
			ToolManager::_FractalTool = new FractalTool();
		}
		return ToolManager::_FractalTool;
	}


	SelectionTool* ToolManager::_SelectionTool = nullptr;
	
	SelectionTool* ToolManager::getSelectionTool(){
		if (!ToolManager::_SelectionTool){
			ToolManager::_SelectionTool = new SelectionTool();
		}
		return ToolManager::_SelectionTool;
	}
}
