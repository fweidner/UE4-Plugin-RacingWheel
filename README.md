# Unreal Version
4.22

# How to use this plugin 
* Create a new project (Vehicle, C++)
* Create new folder: Plugins
* Go to Plugins and do a "Git clone" of this plugin
* Copy SDL2.dll to your Binaries/Win64 folder (in the plugin folder)
* Generate Visual Studio
* Open Visual Studio Solution
* Compile your project
* Go to project settings > Input
* For example, 
** add a new Axis Mapping for MoveForward: Thrustmaster -> Gas
** add a new Axis Mapping for MoveRight: Thrustmaster -> Steering
** Delete all references to GenericUSBController and Gamepad

Works :)


