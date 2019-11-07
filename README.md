# SolarPanelTracker
Simple one-axis rotation solar panel tracker using an arduino. 

Final project for ECE 3301 class at Calstate Polytechnic University, Pomona with Dr. Omar.

The available sunlight available to the solar panel is measured using two photoresistors. These resistors feed analog data into the arduino which determines if the motor should rotate the panel or not. The motor rotates the panel until the arduino measures out the ideal position.

The sunlight is at its most available when both photoresistors output equal voltages. Due to subtle differences such as the resistance in the wires or the photoresistors themselves, a sensitivity parameter is used to account for a certain amount of error. 
