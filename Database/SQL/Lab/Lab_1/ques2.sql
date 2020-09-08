CREATE TABLE Student (
    RollNo INT PRIMARY KEY,
    Name_ VARCHAR(20),
    Total INT,
    Marks_1 INT,
    Marks_2 INT,
    Marks_3 INT,
    Marks_4 INT,
    Marks_5 INT,
    Marks_6 INT
);

CREATE TABLE Department (
    DeptId INT PRIMARY KEY,
    DeptName VARCHAR(10),
    HODName VARCHAR(10)
);

CREATE TABLE StudDep (
    RollNo INT,
    DeptId INT,
    FOREIGN KEY (RollNo) REFERENCES Student(RollNo),
    FOREIGN KEY (DeptId) REFERENCES Department(DeptId)
);

-- Inserting values
-- 1
INSERT INTO 
Student (RollNo, Name_, Marks_1, Marks_2, Marks_3, Marks_4, Marks_5, Marks_6)
VALUES 
(1, 'Scott', 70, 78, 80, 81, 100, 97),
(2, 'Wallace', 90, 91, 70, 98, 93, 86),
(3, 'Bernard', 100, 86, 90, 80, 92, 85),
(4, 'Hudson', 86, 98, 95, 92, 94, 90),
(5, 'Levinson', 81, 87, 86, 82, 99, 100);

-- Updating Total from added marks
UPDATE Student
SET Total = (Marks_1 + Marks_2 + Marks_3 + Marks_4 + Marks_5 + Marks_6);


INSERT INTO Department
VALUES
(1, 'CSE', 'CSE_Hod'),
(2, 'ECE', 'ECE_Hod'),
(3, 'EEE', 'EEE_Hod');


INSERT INTO StudDep
VALUES
(1,1), (2,1), (3,2), (4,2), (5,3);


-- Viewing tables
SELECT * FROM Student;
SELECT * FROM Department;
SELECT * FROM StudDep;



-- 2
SELECT * FROM Student WHERE RollNo IN 
(SELECT RollNo FROM StudDep WHERE DeptId = 1);

-- 3
SELECT * FROM Department WHERE DeptId IN 
(SELECT DeptId FROM StudDep WHERE RollNo = 1);

-- 4
SELECT Name_ FROM Student WHERE Total > 520;

-- 5
SELECT HODName FROM Department WHERE DeptName = 'CSE';

-- 6
SELECT RollNo FROM StudDep WHERE DeptId IN 
(SELECT DeptId FROM Department WHERE DeptName='CSE');