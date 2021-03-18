## Tool
### Configure
1. User clicks on a configuration option in the Tool Settings widget.
3. The Tool setting widget accepts the event and modifies the associatied config option of the current tool object.

### Select
1. User clicks on a tool in the Tool Palette widget.
2. Tool Pallet emits a Tool Change event, allowing both the Canvas View and Tool Settings widgets to be notified.

## Canvas
### Draw on
1. User causes a click, drag, or release actions on the canvas view widget
2. canvas view widget recieves the event, and passes it to the currently active tool 
3. The tool recieves the event, as well as the canvas that is active, and updates the canvas as needed
4. The tool marks the event as handled. 

### Pan/Scale
1. The user causes a middle click, drag, or release action on the Canvas View Widget
2. Canvas View widget recieves the event and passes it to the currently active tool
3. The tool recieves the event and does not process it.
4. The canvas registers that the event was unhandled and handles it for panning or scrolling.

### Create New
1. User selects the New Canvas option from the taskbar, under file
2. A configuration modal appears with configuration options for the new canvas
3. The config modal communicates with the Canvas View widget, causing a new canvas object to be created
4. A CanvasChange event will be emmitted for widgets that need to update themselves.

### Save
1. User selects the Save option from the taskbar, under file
2. if the user has not saved this file already, or has selected Save as..., a save configuration menu appears, defining where to save the file.
3. The file is saved to the specified location.

### Load
1. User selects the Open option from the taskbar, under file
2. A file selection modal appears, filtered to only show Lipuma files.
3. The user selects the file to be opened. 
4. The file is loaded into memory.
5. The file selection modal communicates with the Canvas View widget causes the data loaded to be registered as a canvas
6. A CanvasChange event will be emmitted for widgets that need to update themselves.

### Export
1. User selects the export option from the taskbar, under file.
2. A modal appears asking where the file should be exported to.
3. Based on selected file type in the modal, the appropriate export configuration menu will appear, providing additional configuration details.
4. The file is exported with the given information.

### Select
1. The user clicks on a tab representing a canvas on the Canvas View widget
2. The Canvas View widget changes the currently active canvas
3. A CanvasChange event will be emmitted for widgets that need to update themselves.

## Canvas Object
> Canvas objects are the individual lines that can be modified.
- Select
- Deselect
- Move Selected
- Configure Selected
- Delete Selected

## Layer
- Select 
- Hide 
- Reorder 
- Create 
- Delete 
- Configure 
