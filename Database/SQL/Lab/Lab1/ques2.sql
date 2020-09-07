CREATE TABLE Student (
    RollNo INT PRIMARY KEY,
    Name_ VARCHAR(20),
    Total INT,
    Marks_1 INT,
    Marks_2 INT,
    Marks_3 INT,
    Marks_4 INT,
    Marks_5 INT,
    Marks_6 INT,
    CHECK (Total = Marks_1+Marks_2+Marks_3+Marks_4+Marks_5+Marks_6)
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


-- 1

-- 2
SELECT * FROM Student WHERE RollNo IN 
(SELECT RollNo FROM StudDep WHERE DeptId = 1);

-- 2
SELECT * FROM Department WHERE DeptId IN 
(SELECT DeptId FROM StudDep WHERE StudId = 1);

-- 3
SELECT Name_ FROM Student WHERE Total > 500;

-- 4
SELECT HODName FROM Department WHERE DeptName = 'CSE';

-- 5
SELECT RollNo FROM StudDep WHERE DeptId IN 
(SELECT DeptId FROM Department WHERE DeptName='CSE');