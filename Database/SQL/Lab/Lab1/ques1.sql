CREATE TABLE Employee (
    EmpId INT PRIMARY KEY,
    EmpName VARCHAR(20),
    Address VARCHAR(100),
    Salary INT,
    Doj VARCHAR(20)
);

CREATE TABLE Project (
    ProjectNo INT PRIMARY KEY,
    Duration DECIMAL,
    ProjectName VARCHAR(50)
);

CREATE TABLE WorksOn (
    EmpId INT,
    ProjectNo INT,
    FOREIGN KEY (EmpId) REFERENCES Employee(EmpId),
    FOREIGN KEY (ProjectNo) REFERENCES Project(ProjectNo)
);

-- 1
SELECT * FROM Employee ORDER BY EmpName DESC;

-- 2
SELECT * FROM Project WHERE ProjectNo = '';

-- 3
SELECT * FROM Employee WHERE EmpName LIKE 'B%';

-- 4
SELECT EmpId FROM WorksOn WHERE ProjectNo = '';