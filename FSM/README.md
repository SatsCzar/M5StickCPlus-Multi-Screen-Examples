# M5StickCPlus Finite State Machine Example

This example demonstrates the use of a Finite State Machine (FSM) to manage multiple screens on an M5StickCPlus (ESP32) device. The code includes three different screens that the user can switch between by pressing any of the buttons on the device.

## Code Structure

This example contains a single .ino file (FSM.ino) with the following main components:

* ScreenState: An enumeration of the different screens.

* currentScreenState: A variable that keeps track of the current screen.

* checkButtons(): A function that checks if any of the buttons on the M5StickCPlus have been pressed.

* drawScreen1(), drawScreen2(), and drawScreen3(): Functions that draw the contents of the respective screens on the display.

* changeScreenState(): A function that increments the current screen state and wraps around to the first state when the last state is reached.

* updateScreen(): A function that clears the screen and redraws the current screen based on the currentScreenState.

## Notes

This example is intended to demonstrate the basic structure and usage of a Finite State Machine to manage multiple screens on an M5StickCPlus device. You can easily modify the code to add more screens, update the content displayed on each screen, or change the behavior of the buttons.