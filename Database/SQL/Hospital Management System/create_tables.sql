CREATE TABLE Doctor (
    username VARCHAR(30) PRIMARY KEY,
    pass_word VARCHAR(50),
    name VARCHAR(50) NOT NULL,
    phone NUMERIC,
    email VARCHAR(20) NOT NULL,
    gender VARCHAR(6),
    department VARCHAR(15) NOT NULL,
    attendance INT,
    salary INT,
    status VARCHAR(10),
    CHECK (gender IN ('Male', 'Female', 'Other')),
    CHECK (status IN ('Active', 'Not Active'))
);


CREATE TABLE Patient (
    username VARCHAR(20) PRIMARY KEY,
    pass_word VARCHAR(50),
    name VARCHAR(30) NOT NULL,
    email VARCHAR(50),
    gender VARCHAR(6),
    age INT,
    phone NUMERIC,
    address VARCHAR(500),
    blood_group VARCHAR(3),
    CHECK (gender IN ('Male', 'Female', 'Other')),
    CHECK (blood_group IN ('A+', 'A-', 'B+', 'B-', 'O+', 'O-', 'AB-', 'AB+'))
);


CREATE TABLE Receptionist (
    username VARCHAR(30) PRIMARY KEY,
    pass_word VARCHAR(50),  
);


CREATE TABLE Appointments (
    id AUTO_INCREMENT PRIMARY KEY,
    date_added DATE NOT NULL,
    status VARCHAR(15),
    patient VARCHAR(20),
    doctor VARCHAR(30),
    receptionist VARCHAR(30),
    CHECK (status IN ('Pending', 'Completed')),
    FOREIGN KEY (patient) REFERENCES Patient(username),
    FOREIGN KEY (doctor) REFERENCES Doctor(username),
    FOREIGN KEY (receptionist) REFERENCES Receptionist(username),
);


CREATE TABLE Invoice (
    id AUTO_INCREMENT PRIMARY KEY,
    date_added DATE NOT NULL,
    paid_amount NUMERIC,
    outstanding_amount NUMERIC,
    patient VARCHAR(20),
    FOREIGN KEY (patient) REFERENCES Patient(username)
);


CREATE TABLE Prescription (
    id AUTO_INCREMENT PRIMARY KEY,
    date_added DATE NOT NULL,
    symptoms VARCHAR(100) NOT NULL,
    prescription VARCHAR(500) NOT NULL,
    patient VARCHAR(20),
    doctor VARCHAR(30),
    FOREIGN KEY (patient) REFERENCES Patient(username),
    FOREIGN KEY (doctor) REFERENCES Doctor(username)
);