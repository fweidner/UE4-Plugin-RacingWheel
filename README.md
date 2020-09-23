# Unreal Version
4.25

# How to use this plugin 
* Create a new project (Vehicle, C++)
* Create new folder: Plugins/RacingWheel
* Go to Plugins and put all files into it
* Generate Visual Studio
* Open Visual Studio Solution
* Compile your project
* Go to project settings > Input
* For example, 
  * add a new Axis Mapping for MoveForward: Thrustmaster -> Gas
  *  add a new Axis Mapping for MoveRight: Thrustmaster -> Steering
  * Delete all references to GenericUSBController and Gamepad

* Don't forget to copy third-party binaries:
  * The SDL2 lib files are placed under Plugins/RacingWheel/ThirdParty/WheelLib/Libraries/x64/
  * The SDL2.dll is copied into Plugins/RachingWheel/Binaries/Win64 after the compilation has successfully completed and before starting the Editor

Works :)


