CREATE TABLE Appointments (
    id AUTO_INCREMENT PRIMARY KEY,
    date_added DATE NOT NULL,
    status VARCHAR(15),
    patient VARCHAR(20),
    doctor VARCHAR(30),
    CHECK (status IN ('Pending', 'Completed')),
    FOREIGN KEY (patient) REFERENCES Patient(username),
    FOREIGN KEY (doctor) REFERENCES Doctor(username)
);