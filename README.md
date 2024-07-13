# HospitalManage
An hospital admin manager used to test my capabilities with C++.

## Instructions

### Installation

- Download build from Github.
- Open the HospitalManage executable file. If you are using 32-bit architecture, use x86. If you are using 64-bit architecture, use 64-bit.

### How to use
When the executable has been opened, the manager will indicate what user type you can log in as. If there are no doctor or patient profiles in the csv files provided, the user who will have to log in as an admin and create them through the options provided.

#### Admin

The options available to an admin include:
- 1 Add a patient: The user can add a patient to the patients.csv file by filling in the relevant variables. These include the patient name, gender, condition, doctor, patient number, height, weight, and date of birth. Their name, gender, condition, and doctor must be entered as strings. The patient number, height, weight, and date of birth must be entered as integers.
- 2 Delete a patient: The user can delete a patient from the patients.csv file.
- 3 View all patients: The user can view all the patients in the patients.csv file.
- 4 Add a doctor: The user can add a doctor to the doctors.csv file by filling in the relevant variables. These include the doctor name, gender, role, doctor number, and date of birth. Their name, gender, and role must be entered as strings. The doctor number and date of birth must be entered as integers.
- 5 Delete a doctor: The user can delete a doctor from the doctor.csv file.
- 6 View all doctor: The user can view all the doctors in the doctors.csv file.
- 7 Exit: Return to the log in screen.
 
#### Doctor

In order to log in as a doctor, they must enter their doctor number. If it exists in the doctors.csv file, then the user can access doctor functions.

The options available to a doctor include:
- 1 View details: Displays variables associated with the doctor who has logged in.
- 2 View patients: The user can view all the patients in the patients.csv file.
- 3 View patient condition: When the user enters the number of a specific patient, it will display their condition.
- 4 View patient gender: When the user enters the number of a specific patient, it will display their gender.
- 5 View patient height: When the user enters the number of a specific patient, it will display their height. 
- 6 View patient weight: When the user enters the number of a specific patient, it will display their weight.
- 7 Exit: Return to the log in screen.
 
#### Patient

In order to log in as a patient, they must enter their patient number. If it exists in the patients.csv file, then the user can access patient functions.

The options available to a patient include:
- 1 View details: Displays variables associated with the patient who has logged in.
- 2 Exit: Return to the log in screen.
   
## Version history 

### Version 0.1.0

Initial release.

## Upcoming features

- Detect if inputs are valid.
- Add prescription functionality.
- Use uniform patient and doctor number format.
- Make patients exclusive to their registered doctor.
- Add appointment functionality.
- Create admin password.

## Links

View my portfolio for other projects and services that I provide: https://oliverstup.github.io/

Follow me on LinkedIn: https://www.linkedin.com/in/oliver-page-6ba9a9216/

## Credits

### Programming
- Oliver Page

### Testing
- Oliver Page

### Adapted from source code by
- [wkhaliddev](https://github.com/wkhaliddev/Bank-Management/tree/master)
