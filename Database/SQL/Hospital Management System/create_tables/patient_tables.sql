CREATE TABLE Patient (
    username VARCHAR(20) PRIMARY KEY,
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