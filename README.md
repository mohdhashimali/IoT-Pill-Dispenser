# IoT-Pill-Dispenser
**Overview**

 Medication adherence is a critical component of effective healthcare management,
 particularly for patients with chronic diseases or those requiring long-term medication
 regimens. Non-adherence to prescribed medications can lead to severe health complications,
 increased hospitalizations, and higher healthcare costs. Traditional methods of medication
 management, such as pill organizers and manual reminders, are often insufficient and prone
 to errors.
 
 The Internet of Things (IoT) offers promising solutions to address these challenges by
 integrating smart devices into everyday healthcare practices. An IoT-based medical pill
 dispenser can significantly enhance medication adherence by automating the process of
 medication management. This smart pill dispenser is designed to dispense the correct
 dosage of medication at the prescribed times, providing timely reminders and notifications
 to patients and their caregivers.
 
 The system leverages IoT technology to ensure accurate and reliable dispensing of
 medication. It consists of several key components, including LED indicators, Button and
 LCD Display. The motors and gears work together to dispense the correct dosage, while the
 LED indicator and LCD Display provides real-time alerts, enabling caregivers to monitor
 the patient’s medication adherence remotely.

  The primary objectives of this project are to improve medication adherence, reduce the
 risk of missed or incorrect doses, and enhance the overall health management of patients.
 By automating the medication management process, the IoT-based pill dispenser aims to
 provide a user-friendly and reliable solution that can be particularly beneficial for the elderly
 and those with chronic health conditions.
 
 This project explores the design, implementation, and testing of the IoT-based medical pill
 dispenser. The system’s functionality, performance, and user satisfaction are evaluated to
 ensure it meets the requirements and provides a significant improvement over traditional
 medication management methods.

# Circuit Diagram
![image](https://github.com/user-attachments/assets/40e4c46e-0ebc-4227-b606-8913ada14079)

# Hardware Requirements
 • Arduino Uno R3 Board and USB cable
 
 • Breadboard
 
 • LCD Display I2C 16x2
 
 • Clock DS3231
 
 • Motor 28BYJ Stepper motor and ULN2003 driver
 
 • 5mm LED
 
 • Push button switch
 
 • Jumper Wire for connections

 # Software requirements
 • OS: Windows, Linux, MacOS.
 
 • IDE: Arduino IDE.
 
 • Circuit Design: Fritzing.
 
 • Programming Language: C, C++.
 
 • Libraries: Liquid Crystal by Adafruit, DS3231 by Andrew Wickert, RTClib by
 Adafruit, DHT sensor library by Adafruit, AccelStepper by Mike McCauley etc.
 in Arduino IDE.

 #  3D Model Design
 **DESIGN**
 
 The 3D model design of the IoT-based Medical Pill Dispenser provides a comprehensive
 visual representation of the device, showcasing all its components in a detailed and clear
 manner. This model helps in understanding the spatial arrangement of components, their
 interactions, and the overall design of the dispenser.
 ![image](https://github.com/user-attachments/assets/ce3fe82c-508b-4071-ac98-b89b36f14dd7)

 Figure 1: Components attached to Model

 ![image](https://github.com/user-attachments/assets/dc77bb38-6290-4255-98f2-a0205e007841)

 Figure 2: Top surface of the Model

 ![image](https://github.com/user-attachments/assets/afb212dc-9453-4448-970d-603f177a0420)

 Figure 3: Top surface with Container

#  Components
 1. The base containing all the electronics:
 Mounting pins are on the underside so components can be glued in place.

 • Holes for the stepper motor, Arduino Power supply, LCD display, push button and
 LED bulb.
 
 2. Centre spindle over which the container sits.

 3. Internal gear which is glued to the base of the container.
 
 4. Small gear which fits to the stepper motor.

 5. The container:
 
 • This has vertical walls to divide each compartment.
 
 • Each compartment is labelled with the Day Initial and Am or Pm.
 
 6. The Lid to cover the container and stop pills falling out.
 
 • This has an opening corresponding to one of the container slots.
 
 7. Dish to receive the tablets.

 The body is made using 3D Printing technology.

 #  Platforms Used
 **Arduino IDE**: Using the Arduino IDE for developing the firmware of the IoT-based Medical
 Pill Dispenser involves writing code to manage the various components of the device,
 including the Arduino UNO, motors, and connectivity module.
 
 **Frtizing**: This web application is a popular open-source tool for designing and documenting
 electronic circuits, especially useful for prototyping and visualizing circuit layouts.
 
 **Onshape**: Onshape is a cloud-based 3D CAD software used for designing and modeling
 complex mechanical systems. It allows for collaborative design and real-time updates,
 making it ideal for projects like creating a detailed 3D model of the IoT-based Medical Pill
 Dispenser.
 
 **Ultimaker Cura**: Ultimaker Cura is a popular and powerful slicing software used for
 preparing 3D models for printing. It converts 3D models into instructions (G-code) that 3D
 printers can understand.
 
 **C Language**: C is an imperative procedural language, supporting structured programming,
 lexical variable scope, and recursion, with a static type system.

 # Credits
 [Hashim](https://github.com/mohdhashimali) and [team](https://www.linkedin.com/in/mohdhashimali/overlay/urn:li:fsd_profileProject:(ACoAADkWNT8B5u5Pctn92sJm6NOuDMy80HDaAas,1121552339)/creators/).
 
 Inspired by: [chrisweedonart](https://www.instructables.com/member/chrisweedonart)
